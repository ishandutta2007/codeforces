#line 1 "atcoder-workspace\\tmp.cc"
#include <bits/extc++.h>

#line 2 "Library\\src\\data_structure\\compression.hpp"

/**
 * @file compression.hpp
 * @brief Compression
 */

#line 11 "Library\\src\\data_structure\\compression.hpp"

namespace workspace {

template <class _Tp> class compression {
  std::vector<_Tp> __vec;

  decltype(auto) begin() { return __vec.begin(); }

  decltype(auto) end() { return __vec.end(); }

 public:
  using size_type = typename std::vector<_Tp>::size_type;

  /**
   * @brief Construct a new compression object.
   */
  compression() = default;

  /**
   * @brief Construct a new compression object.
   *
   * @param __first
   * @param __last
   */
  template <class _IIter>
  compression(_IIter __first, _IIter __last) noexcept : __vec(__first, __last) {
    make();
  }

  decltype(auto) begin() const noexcept { return __vec.begin(); }

  decltype(auto) end() const noexcept { return __vec.end(); }

  decltype(auto) operator[](size_type __i) const noexcept {
    assert(__i < size());
    return __vec[__i];
  }

  size_type size() const noexcept { return __vec.size(); }

  template <class... _Args> decltype(auto) emplace(_Args&&... __args) noexcept {
    return __vec.emplace_back(std::forward<_Args>(__args)...);
  }

  template <class... _Args> void insert(_Args&&... __args) noexcept {
    __vec.insert(end(), std::forward<_Args>(__args)...);
  }

  /**
   * @brief Sort and make unique.
   * @return Number of different values.
   */
  size_type make() noexcept {
    std::sort(begin(), end());

    __vec.erase(std::unique(begin(), end(),
                            [](const _Tp& __l, const _Tp& __r) {
                              return !(__l < __r) && !(__r < __l);
                            }),
                end());

    return size();
  }

  size_type lower_bound(const _Tp& __x) const noexcept {
    return std::lower_bound(begin(), end(), __x) - begin();
  }

  size_type upper_bound(const _Tp& __x) const noexcept {
    return std::upper_bound(begin(), end(), __x) - begin();
  }
};

template <class _IIter>
compression(_IIter, _IIter)
    -> compression<typename std::iterator_traits<_IIter>::value_type>;

}  // namespace workspace
#line 2 "Library\\src\\graph\\directed\\flow\\Dinic.hpp"

/**
 * @file Dinic.hpp
 * @brief Dinic's Algorithm
 */

#line 9 "Library\\src\\graph\\directed\\flow\\Dinic.hpp"

#line 2 "Library\\src\\graph\\directed\\flow\\base.hpp"

/**
 * @file base.hpp
 * @brief Flow Graph
 */

#line 12 "Library\\src\\graph\\directed\\flow\\base.hpp"

namespace workspace {

template <class _Cap, class _Cost = void> class flow_graph {
 protected:
  class adjacency_impl;

 public:
  using container_type = std::vector<adjacency_impl>;
  using size_type = typename container_type::size_type;

  class unweighted_edge {
   public:
    size_type tail;  // Source
    size_type head;  // Destination
    _Cap capacity;   // Capacity
    _Cap flow;       // Flow

    unweighted_edge(size_type __s, size_type __d, const _Cap &__u = 1)
        : tail(__s), head(__d), capacity(__u), flow(0) {
      assert(!(capacity < static_cast<_Cap>(0))),
          assert(!(flow < static_cast<_Cap>(0)));
    }

    // tail, head, capacity, flow
    template <class _Os>
    friend _Os &operator<<(_Os &__os, const unweighted_edge &__e) {
      return __os << __e.tail << ' ' << __e.head << ' ' << __e.capacity << ' '
                  << __e.flow;
    }

   protected:
    unweighted_edge() = default;

    unweighted_edge(size_type __s, size_type __d, const _Cap &__u,
                    const _Cap &__f)
        : tail(__s), head(__d), capacity(__u), flow(__f) {}

    unweighted_edge make_rev() const { return {head, tail, flow, capacity}; }
  };

  class weighted_edge : public unweighted_edge {
   public:
    _Cost cost;  // _Cost

    weighted_edge(const unweighted_edge &__e, const _Cost &__c = 0)
        : unweighted_edge(__e), cost(__c) {}

    weighted_edge(size_type __s, size_type __d, const _Cap &__u = 1,
                  const _Cost &__c = 0)
        : unweighted_edge(__s, __d, __u), cost(__c) {}

    // tail, head, capacity, flow, cost
    template <class _Os>
    friend _Os &operator<<(_Os &__os, const weighted_edge &__e) {
      return __os << static_cast<unweighted_edge>(__e) << ' ' << __e.cost;
    }

   protected:
    weighted_edge() = default;

    weighted_edge make_rev() const {
      return {unweighted_edge::make_rev(), -cost};
    }
  };

  using edge = std::conditional_t<std::is_void<_Cost>::value, unweighted_edge,
                                  weighted_edge>;

 protected:
  struct edge_impl : edge {
    bool aux = false;
    edge_impl *rev = nullptr;

    edge_impl() = default;

    edge_impl(const edge &__e) : edge(__e) {}
    edge_impl(edge &&__e) : edge(__e) {}

    void push(_Cap __f) {
      edge::capacity -= __f;
      edge::flow += __f;
      if (rev) {
        rev->capacity += __f;
        rev->flow -= __f;
      }
    }

    edge_impl make_rev() {
      edge_impl __e = edge::make_rev();
      __e.aux = true;
      __e.rev = this;
      return __e;
    }
  };

 public:
  class adjacency {
   public:
    using value_type = edge;
    using reference = edge &;
    using const_reference = edge const &;
    using pointer = edge *;
    using const_pointer = const edge *;

    class iterator {
      edge_impl *__p;

     public:
      iterator(edge_impl *__p = nullptr) : __p(__p) {}

      bool operator!=(const iterator &__x) const { return __p != __x.__p; }

      bool operator==(const iterator &__x) const { return __p == __x.__p; }

      iterator &operator++() {
        do ++__p;
        while (__p->rev && __p->aux);
        return *this;
      }

      iterator operator++(int) {
        auto __cp = *this;
        do ++__p;
        while (__p->rev && __p->aux);
        return __cp;
      }

      iterator &operator--() {
        do --__p;
        while (__p->aux);
        return *this;
      }

      iterator operator--(int) {
        auto __cp = *this;
        do --__p;
        while (__p->aux);
        return __cp;
      }

      pointer operator->() const { return __p; }

      reference operator*() const { return *__p; }
    };

    class const_iterator {
      const edge_impl *__p;

     public:
      const_iterator(const edge_impl *__p = nullptr) : __p(__p) {}

      bool operator!=(const const_iterator &__x) const {
        return __p != __x.__p;
      }

      bool operator==(const const_iterator &__x) const {
        return __p == __x.__p;
      }

      const_iterator &operator++() {
        do ++__p;
        while (__p->rev && __p->aux);
        return *this;
      }

      const_iterator operator++(int) {
        auto __cp = *this;
        do ++__p;
        while (__p->rev && __p->aux);
        return __cp;
      }

      const_iterator &operator--() {
        do --__p;
        while (__p->aux);
        return *this;
      }

      const_iterator operator--(int) {
        auto __cp = *this;
        do --__p;
        while (__p->aux);
        return __cp;
      }

      const_pointer operator->() const { return __p; }

      const_reference operator*() const { return *__p; }
    };

    adjacency()
        : first(new edge_impl[2]), last(first + 1), __s(first), __t(first) {}

    ~adjacency() { delete[] first; }

    const_reference operator[](size_type __i) const {
      assert(__i < size());
      return *(first + __i);
    }

    size_type size() const { return __t - first; }

    auto begin() { return iterator{__s}; }
    auto begin() const { return const_iterator{__s}; }

    auto end() { return iterator{__t}; }
    auto end() const { return const_iterator{__t}; }

    /**
     * @brief Construct a new adjacency object
     *
     * @param __x Rvalue reference to another object
     */
    adjacency(adjacency &&__x) : first(nullptr) { operator=(std::move(__x)); }

    /**
     * @brief Assignment operator.
     *
     * @param __x Rvalue reference to another object
     * @return Reference to this object.
     */
    adjacency &operator=(adjacency &&__x) {
      delete[] first;
      first = __x.first, __x.first = nullptr;
      last = __x.last, __s = __x.__s, __t = __x.__t;
      return *this;
    }

   protected:
    edge_impl *first, *last, *__s, *__t;
  };

  using value_type = adjacency;
  using reference = adjacency &;
  using const_reference = adjacency const &;

 protected:
  class adjacency_impl : public adjacency {
   public:
    using base = adjacency;
    using base::__s;
    using base::__t;
    using base::first;
    using base::last;

    using iterator = edge_impl *;

    iterator push(const edge_impl &__e) {
      realloc();
      *__t = __e;
      if (__s->aux) ++__s;
      return __t++;
    }

    iterator push(edge_impl &&__e) {
      realloc();
      *__t = std::move(__e);
      if (__s->aux) ++__s;
      return __t++;
    }

    iterator begin() const { return first; }

    iterator end() const { return __t; }

    void realloc() {
      if (__t == last) {
        size_type __n(last - first);
        iterator loc = new edge_impl[__n << 1 | 1];
        __s += loc - first;
        __t = loc;
        for (iterator __p{first}; __p != last; ++__p, ++__t) {
          *__t = *__p;
          if (__p->rev) __p->rev->rev = __t;
        }
        delete[] first;
        first = loc;
        last = __t + __n;
      }
    }
  };

  // Only member variable.
  container_type graph;

 public:
  /**
   * @brief Construct a new flow graph object
   *
   * @param __n Number of vertices
   */
  flow_graph(size_type __n = 0) : graph(__n) {}

  /**
   * @brief Construct a new flow graph object
   *
   * @param __x Const reference to another object
   */
  flow_graph(const flow_graph &__x) : graph(__x.size()) {
    for (auto &&__adj : __x)
      for (auto &&__e : __adj) add_edge(__e);
  }

  /**
   * @brief Construct a new flow graph object
   *
   * @param __x Rvalue reference to another object
   */
  flow_graph(flow_graph &&__x) : graph(std::move(__x.graph)) {}

  /**
   * @brief Assignment operator.
   *
   * @param __x Const reference to another object
   * @return Reference to this object.
   */
  flow_graph &operator=(const flow_graph &__x) {
    return operator=(std::move(flow_graph{__x}));
  }

  /**
   * @brief Assignment operator.
   *
   * @param __x Rvalue reference to another object
   * @return Reference to this object.
   */
  flow_graph &operator=(flow_graph &&__x) {
    graph = std::move(__x.graph);
    return *this;
  }

  /**
   * @return Whether the graph is empty.
   */
  bool empty() const { return graph.empty(); }

  /**
   * @return Number of nodes.
   */
  size_type size() const { return graph.size(); }

  /**
   * @param node Node
   * @return Referece to the adjacency list of the node.
   */
  reference operator[](size_type node) {
    assert(node < size());
    return graph[node];
  }

  /**
   * @param node Node
   * @return Const referece to the adjacency list of the node.
   */
  const_reference operator[](size_type node) const {
    assert(node < size());
    return graph[node];
  }

  class iterator : public container_type::iterator {
    using base = typename container_type::iterator;

   public:
    using reference = adjacency &;
    using pointer = adjacency *;

    iterator(const base &__i) : base(__i) {}

    pointer operator->() const { return base::operator->(); }

    reference operator*() const { return base::operator*(); }
  };

  class const_iterator : public container_type::const_iterator {
    using base = typename container_type::const_iterator;

   public:
    using const_reference = const adjacency &;
    using const_pointer = const adjacency *;

    const_iterator(const base &__i) : base(__i) {}

    const_pointer operator->() const { return base::operator->(); }

    const_reference operator*() const { return base::operator*(); }
  };

  auto begin() { return iterator{graph.begin()}; }
  auto begin() const { return const_iterator{graph.begin()}; }

  auto end() { return iterator{graph.end()}; }
  auto end() const { return const_iterator{graph.end()}; }

  /**
   * @brief Add a node to the graph.
   *
   * @return Index of the node.
   */
  size_type add_node() { return add_nodes(1).front(); }

  /**
   * @brief Add some nodes to the graph.
   *
   * @param __n Number of nodes added
   * @return List of indices of the nodes.
   */
  std::vector<size_type> add_nodes(size_type __n) {
    std::vector<size_type> __nodes(__n);
    std::iota(__nodes.begin(), __nodes.end(), graph.size());
    __n += graph.size();
    if (__n > graph.capacity()) {
      container_type __tmp(__n);
      for (auto &&__adj : graph)
        for (auto &&__e : __adj) {
          edge_impl *__p = __tmp[__e.tail].push(std::move(__e));
          // Careful with a self loop.
          if (__p->rev) __p->rev->rev = __p;
        }
      graph = std::move(__tmp);
    } else
      graph.resize(__n);
    return __nodes;
  }

  /**
   * @brief Add a directed edge to the graph.
   *
   * @return Reference to the edge.
   */
  template <class... _Args>
  typename std::enable_if<std::is_constructible<edge, _Args...>::value,
                          edge &>::type
  add_edge(_Args &&...__args) {
    edge_impl __e = edge(std::forward<_Args>(__args)...);
    assert(__e.tail < size()), assert(__e.head < size());
    edge_impl *__p = graph[__e.tail].push(std::move(__e));
    // Careful with a self loop.
    if (__p->tail != __p->head)
      __p->rev = graph[__p->head].push(__p->make_rev());
    return *__p;
  }

  /**
   * @brief Add a directed edge to the graph.
   *
   * @return Reference to the edge.
   */
  template <class _Tp>
  typename std::enable_if<(std::tuple_size<std::decay_t<_Tp>>::value >= 0),
                          edge &>::type
  add_edge(_Tp &&__t) {
    return _unpack_directed(std::forward<_Tp>(__t));
  }

  /**
   * @brief Add an undirected edge to the graph. Its cost must be non-negative.
   *
   * @return Reference to the edge.
   */
  template <class... _Args> edge &add_undirected_edge(_Args &&...__args) {
    edge_impl __e = edge(std::forward<_Args>(__args)...);
    assert(__e.tail < size()), assert(__e.head < size());
    __e.flow += __e.capacity;
    edge_impl *__p = graph[__e.tail].push(std::move(__e));
    // Careful with a self loop.
    if (__p->tail != __p->head) {
      edge_impl __r = __p->make_rev();
      __r.aux = false;
      __p->rev = graph[__p->head].push(std::move(__r));
    }
    return *__p;
  }

  /**
   * @brief Add an undirected edge to the graph. Its cost must be non-negative.
   *
   * @return Reference to the edge.
   */
  template <class _Tp>
  typename std::enable_if<(std::tuple_size<std::decay_t<_Tp>>::value >= 0),
                          edge &>::type
  add_undirected_edge(_Tp &&__t) {
    return _unpack_undirected(std::forward<_Tp>(__t));
  }

 protected:
  // internal
  template <class _Tp, size_t _Nm = 0, class... _Args>
  decltype(auto) _unpack_directed(_Tp &&__t, _Args &&...__args) {
    if constexpr (_Nm == std::tuple_size<std::decay_t<_Tp>>::value)
      return add_edge(std::forward<_Args>(__args)...);
    else
      return _unpack_directed<_Tp, _Nm + 1>(std::forward<_Tp>(__t),
                                            std::forward<_Args>(__args)...,
                                            std::get<_Nm>(__t));
  }

  // internal
  template <class _Tp, size_t _Nm = 0, class... _Args>
  decltype(auto) _unpack_undirected(_Tp &&__t, _Args &&...__args) {
    if constexpr (_Nm == std::tuple_size<std::decay_t<_Tp>>::value)
      return add_undirected_edge(std::forward<_Args>(__args)...);
    else
      return _unpack_undirected<_Tp, _Nm + 1>(std::forward<_Tp>(__t),
                                              std::forward<_Args>(__args)...,
                                              std::get<_Nm>(__t));
  }

  template <class _Os>
  friend _Os &operator<<(_Os &__os, flow_graph const &__g) {
    for (const auto &adj : __g)
      for (const auto &e : adj) __os << e << "\n";
    return __os;
  }
};

}  // namespace workspace
#line 11 "Library\\src\\graph\\directed\\flow\\Dinic.hpp"

namespace workspace {

/**
 * @brief Compute the maximum flow.
 * @tparam _Cap Capacity type
 */
template <class _Cap> class Dinic : public flow_graph<_Cap> {
  using base = flow_graph<_Cap>;

 public:
  using size_type = typename base::size_type;

 protected:
  constexpr static size_type nil = -1;

  std::vector<size_type> __level;
  std::vector<typename base::container_type::value_type::iterator> __iter;

  _Cap dfs(size_type __src, size_type __dst, _Cap __limit) noexcept {
    if (__src == __dst) return __limit;

    _Cap __flow(0);

    for (auto &__e{__iter[__dst]}; __e != base::graph[__dst].end(); ++__e)
      if (static_cast<_Cap>(0) < __e->flow &&
          __level[__e->head] < __level[__dst])
        if (_Cap achv = dfs(__src, __e->head, std::min(__limit, __e->flow));
            static_cast<_Cap>(0) < achv) {
          __e->push(-achv);
          __flow += achv, __limit -= achv;
          if (__limit == static_cast<_Cap>(0)) break;
        }

    return __flow;
  }

 public:
  // Construct a new Dinic object.
  Dinic() noexcept {}

  /**
   * @brief Construct a new Dinic object.
   * @param __n Number of nodes
   */
  Dinic(size_type __n) noexcept : base::flow_graph(__n) {}

  /**
   * @brief Run Dinic's algorithm.
   * @param __src Source
   * @param __dst Destination
   * @return Maximum flow.
   */
  _Cap run(size_type __src, size_type __dst) noexcept {
    return run(__src, __dst, std::numeric_limits<_Cap>::max());
  }

  /**
   * @brief Run Dinic's algorithm.
   * @param __src Source
   * @param __dst Destination
   * @param __limit Flow limit
   * @return Maximum flow.
   */
  _Cap run(size_type __src, size_type __dst, _Cap __limit) noexcept {
    assert(__src < base::size()), assert(__dst < base::size()),
        assert(__src != __dst);

    __level.resize(base::size(), nil);
    __iter.resize(base::size());

    if (!(static_cast<_Cap>(0) < __limit)) return 0;
    _Cap __flow = 0;

    for (std::vector<size_type> __q(base::size());;
         std::fill(__level.begin(), __level.end(), nil)) {
      __level[__q.front() = __src] = 0;

      for (auto __ql{__q.begin()}, __qr{std::next(__ql)};
           __level[__dst] == nil && __ql != __qr; ++__ql)
        for (const auto &__e : base::graph[*__ql])
          if (static_cast<_Cap>(0) < __e.capacity && __level[__e.head] == nil)
            __level[ *__qr++ = __e.head] = __level[*__ql] + 1;

      if (__level[__dst] == nil) break;

      for (size_type __x{}; __x != base::size(); ++__x)
        __iter[__x] = base::graph[__x].begin();

      __flow += dfs(__src, __dst, __limit);
    }

    return __flow;
  }

  // Minimum Cut.
  // Call it after `run`.
  auto min_cut() const noexcept {
    std::vector<typename base::edge> __cut;

    for (size_type __x{}; __x != base::size(); ++__x)
      if (~__level[__x])
        for (const auto &__e : base::operator[](__x))
          if (!~__level[__e.head]) __cut.emplace_back(__e);

    return __cut;
  }
};

}  // namespace workspace
#line 2 "Library\\src\\utils\\py-like\\enumerate.hpp"

/**
 * @file enumerate.hpp
 * @brief Enumerate
 */

#line 2 "Library\\src\\utils\\py-like\\range.hpp"

/**
 * @file range.hpp
 * @brief Range
 */

#line 2 "Library\\src\\utils\\py-like\\reversed.hpp"

/**
 * @file reversed.hpp
 * @brief Reversed
 */

#line 9 "Library\\src\\utils\\py-like\\reversed.hpp"

#line 2 "Library\\lib\\cxx17"

#line 2 "Library\\lib\\cxx14"

#ifndef _CXX14_CONSTEXPR
#if __cplusplus >= 201402L
#define _CXX14_CONSTEXPR constexpr
#else
#define _CXX14_CONSTEXPR
#endif
#endif
#line 4 "Library\\lib\\cxx17"

#ifndef _CXX17_CONSTEXPR
#if __cplusplus >= 201703L
#define _CXX17_CONSTEXPR constexpr
#else
#define _CXX17_CONSTEXPR
#endif
#endif

#ifndef _CXX17_STATIC_ASSERT
#if __cplusplus >= 201703L
#define _CXX17_STATIC_ASSERT static_assert
#else
#define _CXX17_STATIC_ASSERT assert
#endif
#endif

#line 22 "Library\\lib\\cxx17"

#if __cplusplus < 201703L

namespace std {

/**
 *  @brief  Return the size of a container.
 *  @param  __cont  Container.
 */
template <typename _Container>
constexpr auto size(const _Container& __cont) noexcept(noexcept(__cont.size()))
    -> decltype(__cont.size()) {
  return __cont.size();
}

/**
 *  @brief  Return the size of an array.
 */
template <typename _Tp, size_t _Nm>
constexpr size_t size(const _Tp (&)[_Nm]) noexcept {
  return _Nm;
}

/**
 *  @brief  Return whether a container is empty.
 *  @param  __cont  Container.
 */
template <typename _Container>
[[nodiscard]] constexpr auto empty(const _Container& __cont) noexcept(
    noexcept(__cont.empty())) -> decltype(__cont.empty()) {
  return __cont.empty();
}

/**
 *  @brief  Return whether an array is empty (always false).
 */
template <typename _Tp, size_t _Nm>
[[nodiscard]] constexpr bool empty(const _Tp (&)[_Nm]) noexcept {
  return false;
}

/**
 *  @brief  Return whether an initializer_list is empty.
 *  @param  __il  Initializer list.
 */
template <typename _Tp>
[[nodiscard]] constexpr bool empty(initializer_list<_Tp> __il) noexcept {
  return __il.size() == 0;
}

struct monostate {};

}  // namespace std

#else

#include <variant>

#endif
#line 11 "Library\\src\\utils\\py-like\\reversed.hpp"

namespace workspace {

// Reversed container.
template <class _Container> class reversed {
  _Container __c;

 public:
  template <class _Tp>
  constexpr reversed(_Tp &&__x) noexcept : __c(std::forward<_Container>(__x)) {}

  template <class _Tp>
  constexpr reversed(std::initializer_list<_Tp> __x) noexcept : __c(__x) {}

  constexpr decltype(auto) begin() noexcept { return std::rbegin(__c); }
  constexpr decltype(auto) begin() const noexcept { return std::rbegin(__c); }

  constexpr decltype(auto) end() noexcept { return std::rend(__c); }
  constexpr decltype(auto) end() const noexcept { return std::rend(__c); }

  constexpr bool empty() const noexcept { return std::empty(__c); }

  constexpr decltype(auto) size() const noexcept { return std::size(__c); }

  using iterator = decltype(std::rbegin(__c));
  using const_iterator = decltype(std::crbegin(__c));

  using size_type = decltype(std::size(__c));
  using difference_type =
      typename std::iterator_traits<iterator>::difference_type;
  using value_type = typename std::iterator_traits<iterator>::value_type;

  using reference = typename std::iterator_traits<iterator>::reference;
  using const_reference =
      typename std::iterator_traits<const_iterator>::reference;
};

#if __cpp_deduction_guides >= 201606L

template <class _Tp> reversed(_Tp &&) -> reversed<_Tp>;

template <class _Tp>
reversed(std::initializer_list<_Tp>) -> reversed<std::initializer_list<_Tp>>;

#endif

}  // namespace workspace
#line 9 "Library\\src\\utils\\py-like\\range.hpp"

namespace workspace {

template <class _Index> class range {
  _Index __first, __last;

 public:
  class iterator {
    _Index __i;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = _Index;
    using pointer = void;
    using reference = value_type;
    using iterator_category = std::random_access_iterator_tag;

    constexpr iterator() = default;
    constexpr iterator(const _Index &__x) noexcept : __i(__x) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return __i == __x.__i;
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
      return __i != __x.__i;
    }

    constexpr bool operator<(const iterator &__x) const noexcept {
      return __i < __x.__i;
    }
    constexpr bool operator<=(const iterator &__x) const noexcept {
      return __i <= __x.__i;
    }

    constexpr bool operator>(const iterator &__x) const noexcept {
      return __i > __x.__i;
    }
    constexpr bool operator>=(const iterator &__x) const noexcept {
      return __i >= __x.__i;
    }

    constexpr iterator &operator++() noexcept {
      ++__i;
      return *this;
    }
    constexpr iterator operator++(int) noexcept {
      auto __tmp = *this;
      ++__i;
      return __tmp;
    }

    constexpr iterator &operator--() noexcept {
      --__i;
      return *this;
    }
    constexpr iterator operator--(int) noexcept {
      auto __tmp = *this;
      --__i;
      return __tmp;
    }

    constexpr difference_type operator-(const iterator &__x) const noexcept {
      return __i - __x.__i;
    }

    constexpr iterator &operator+=(difference_type __x) noexcept {
      __i += __x;
      return *this;
    }
    constexpr iterator operator+(difference_type __x) const noexcept {
      return iterator(*this) += __x;
    }

    constexpr iterator &operator-=(difference_type __x) noexcept {
      __i -= __x;
      return *this;
    }
    constexpr iterator operator-(difference_type __x) const noexcept {
      return iterator(*this) -= __x;
    }

    constexpr reference operator*() const noexcept { return __i; }
  };

  using value_type = _Index;
  using reference = value_type;

  using difference_type = std::ptrdiff_t;
  using size_type = std::size_t;

  using const_iterator = iterator;

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = reverse_iterator;

  template <class _Tp1, class _Tp2>
  constexpr range(const _Tp1 &__first, const _Tp2 &__last) noexcept
      : __first(__first), __last(__last) {}

  template <class _Tp>
  constexpr range(const _Tp &__last) noexcept : __first(), __last(__last) {}

  constexpr iterator begin() const noexcept { return {__first}; }
  constexpr const_iterator cbegin() const noexcept { return begin(); }

  constexpr iterator end() const noexcept { return {__last}; }
  constexpr const_iterator cend() const noexcept { return end(); }

  constexpr reverse_iterator rbegin() const noexcept {
    return reverse_iterator{end()};
  }
  constexpr const_reverse_iterator crbegin() const noexcept { return rbegin(); }

  constexpr reverse_iterator rend() const noexcept {
    return reverse_iterator{begin()};
  }
  constexpr const_reverse_iterator crend() const noexcept { return rend(); }

  constexpr size_type size() const noexcept { return __last - __first; }
};

#if __cpp_deduction_guides >= 201606L

template <class _Tp1, class _Tp2>
range(const _Tp1 &, const _Tp2 &)
    -> range<std::decay_t<decltype(++std::declval<_Tp1 &>())>>;

template <class _Tp>
range(const _Tp &) -> range<std::decay_t<decltype(++std::declval<_Tp &>())>>;

template <class... _Args>
constexpr decltype(auto) rrange(_Args &&...__args) noexcept {
  return reversed(range(std::forward<_Args>(__args)...));
}

#endif

}  // namespace workspace
#line 2 "Library\\src\\utils\\py-like\\zip.hpp"

/**
 * @file zip.hpp
 * @brief Zip
 */

#line 11 "Library\\src\\utils\\py-like\\zip.hpp"

#line 2 "Library\\src\\utils\\iterator\\category.hpp"

/*
 * @file category.hpp
 * @brief Iterator Category
 */

#line 10 "Library\\src\\utils\\iterator\\category.hpp"

namespace workspace {

/*
 * @tparam Tuple Tuple of iterator types
 */
template <class Tuple, size_t N = std::tuple_size<Tuple>::value - 1>
struct common_iterator_category {
  using type = typename std::common_type<
      typename common_iterator_category<Tuple, N - 1>::type,
      typename std::iterator_traits<typename std::tuple_element<
          N, Tuple>::type>::iterator_category>::type;
};

template <class Tuple> struct common_iterator_category<Tuple, 0> {
  using type = typename std::iterator_traits<
      typename std::tuple_element<0, Tuple>::type>::iterator_category;
};

}  // namespace workspace
#line 2 "Library\\src\\utils\\iterator\\reverse.hpp"

/*
 * @file reverse_iterator.hpp
 * @brief Reverse Iterator
 */

#if __cplusplus >= 201703L

#include <iterator>
#include <optional>

namespace workspace {

/*
 * @class reverse_iterator
 * @brief Wrapper class for `std::reverse_iterator`.
 * @see http://gcc.gnu.org/PR51823
 */
template <class Iterator>
class reverse_iterator : public std::reverse_iterator<Iterator> {
  using base_std = std::reverse_iterator<Iterator>;
  std::optional<typename base_std::value_type> deref;

 public:
  using base_std::reverse_iterator;

  constexpr typename base_std::reference operator*() noexcept {
    if (!deref) {
      Iterator tmp = base_std::current;
      deref = *--tmp;
    }
    return deref.value();
  }

  constexpr reverse_iterator &operator++() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator &operator--() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator++(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator--(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
};

}  // namespace workspace

#endif
#line 15 "Library\\src\\utils\\py-like\\zip.hpp"

namespace workspace {

template <class _Tuple> class zipped : protected _Tuple {
 public:
  zipped(const _Tuple &__x) : _Tuple(__x) {}

  template <std::size_t _Nm> constexpr decltype(auto) get() const &noexcept {
    return *std::get<_Nm>(*this);
  }

  template <std::size_t _Nm> constexpr decltype(auto) get() &&noexcept {
    auto __tmp = *std::get<_Nm>(*this);
    return __tmp;
  }
};

template <class... _Containers> class zip {
  std::tuple<_Containers...> __c;

  template <std::size_t _Nm = 0>
  constexpr decltype(auto) begin_cat() const noexcept {
    if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers)) {
      return std::tuple_cat(std::tuple(std::begin(std::get<_Nm>(__c))),
                            begin_cat<_Nm + 1>());
    } else
      return std::tuple<>();
  }

  template <std::size_t _Nm = 0>
  constexpr decltype(auto) end_cat() const noexcept {
    if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers)) {
      return std::tuple_cat(std::tuple(std::end(std::get<_Nm>(__c))),
                            end_cat<_Nm + 1>());
    } else
      return std::tuple<>();
  }

  using _Iterator_tuple =
      std::tuple<decltype(std::begin(std::declval<_Containers>()))...>;

 public:
  using size_type = std::size_t;

  class iterator : public zipped<_Iterator_tuple> {
    using _Base = zipped<_Iterator_tuple>;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = _Base;
    using pointer = void;
    using reference = value_type &;
    using iterator_category =
        typename common_iterator_category<_Iterator_tuple>::type;

   protected:
    template <std::size_t _Nm = 0>
    constexpr bool equal(const iterator &__x) const noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers)) {
        return std::get<_Nm>(*this) == std::get<_Nm>(__x) ||
               equal<_Nm + 1>(__x);
      } else
        return false;
    }

    template <std::size_t _Nm = 0> constexpr void increment() noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers))
        ++std::get<_Nm>(*this), increment<_Nm + 1>();
    }

    template <std::size_t _Nm = 0> constexpr void decrement() noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers))
        --std::get<_Nm>(*this), decrement<_Nm + 1>();
    }

    template <std::size_t _Nm = 0>
    constexpr void advance(difference_type __d) noexcept {
      if _CXX17_CONSTEXPR (_Nm != sizeof...(_Containers))
        std::get<_Nm>(*this) += __d, advance<_Nm + 1>(__d);
    }

   public:
    iterator(const _Iterator_tuple &__x) : _Base(__x) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return equal(__x);
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
      return !equal(__x);
    }

    constexpr iterator &operator++() noexcept {
      increment();
      return *this;
    }
    constexpr iterator operator++(int) noexcept {
      auto __tmp = *this;
      increment();
      return __tmp;
    }

    constexpr iterator &operator--() noexcept {
      decrement();
      return *this;
    }
    constexpr iterator operator--(int) noexcept {
      auto __tmp = *this;
      decrement();
      return __tmp;
    }

    constexpr bool operator<(const iterator &__x) const noexcept {
      return std::get<0>(*this) < std::get<0>(__x);
    }
    constexpr bool operator<=(const iterator &__x) const noexcept {
      return std::get<0>(*this) <= std::get<0>(__x);
    }
    constexpr bool operator>(const iterator &__x) const noexcept {
      return !operator<=(__x);
    }
    constexpr bool operator>=(const iterator &__x) const noexcept {
      return !operator>(__x);
    }

    constexpr iterator &operator+=(difference_type __d) noexcept {
      advance(__d);
      return *this;
    }
    constexpr iterator &operator-=(difference_type __d) noexcept {
      advance(-__d);
      return *this;
    }
    constexpr iterator operator+(difference_type __d) const noexcept {
      return iterator{*this} += __d;
    }
    constexpr iterator operator-(difference_type __d) const noexcept {
      return iterator{*this} -= __d;
    }

    constexpr difference_type operator-(const iterator &__x) const noexcept {
      return std::get<0>(*this) - std::get<0>(__x);
    }

    constexpr reference operator*() noexcept { return {*this}; }
  };

  using const_iterator = iterator;

  template <class... _Args>
  constexpr zip(_Args &&...__args) noexcept
      : __c(std::forward<_Args>(__args)...) {}

  template <class... _Args>
  constexpr zip(std::initializer_list<_Args>... __args) noexcept
      : __c(std::forward<_Args>(__args)...) {}

  constexpr iterator begin() const noexcept { return {begin_cat()}; }

  constexpr iterator end() const noexcept { return {end_cat()}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>{end()};
  }

  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>{begin()};
  }

#if __cplusplus >= 201703L
  constexpr size_type size() const noexcept {
    size_type __n = -1;
    std::apply(
        [&__n](auto &&__x) {
          if (__n < __x.size()) __n = __x.size();
        },
        __c);
    return __n;
  }
#endif
};

#if __cpp_deduction_guides >= 201606L

template <class... _Args> zip(_Args &&...) -> zip<_Args...>;

// For gcc version < 10
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=80438
template <class _Tp, class... _Args>
zip(_Tp &&, _Args &&...) -> zip<_Tp, _Args...>;

template <class... _Args>
zip(std::initializer_list<_Args>...) -> zip<std::initializer_list<_Args>...>;

#endif

}  // namespace workspace

namespace std {

template <size_t _Nm, class _Tuple>
struct tuple_element<_Nm, workspace::zipped<_Tuple>> {
  using type = remove_reference_t<
      typename iterator_traits<tuple_element_t<_Nm, _Tuple>>::reference>;
};

template <class _Tuple>
struct tuple_size<workspace::zipped<_Tuple>> : tuple_size<_Tuple> {};

}  // namespace std
#line 10 "Library\\src\\utils\\py-like\\enumerate.hpp"

#if __cplusplus >= 201703L

namespace workspace {

namespace _enumerate_impl {

constexpr size_t min_size() noexcept { return SIZE_MAX; }

template <class _Container, class... _Args>
constexpr size_t min_size(_Container const &__cont,
                          _Args &&... __args) noexcept {
  return std::min(std::size(__cont), min_size(std::forward<_Args>(__args)...));
}

}  // namespace _enumerate_impl

template <class... _Args>
constexpr decltype(auto) enumerate(_Args &&... __args) noexcept {
  return zip(range(_enumerate_impl::min_size(__args...)),
             std::forward<_Args>(__args)...);
}

template <class... _Args>
constexpr decltype(auto) enumerate(
    std::initializer_list<_Args> const &... __args) noexcept {
  return zip(range(_enumerate_impl::min_size(__args...)),
             std::vector(__args)...);
}

}  // namespace workspace

#endif
#line 6 "atcoder-workspace\\tmp.cc"

namespace workspace {

void main() {
  // start here!

  using namespace std;

  int n;
  cin >> n;
  Dinic<int> dinic(n + 2);
  const int src = n, dst = src + 1;
  int ans = 0;
  vector<int> a(n), b(n);
  for (auto &&x : a) {
    cin >> x;
  }
  for (auto &&x : b) {
    cin >> x;
  }
  for (auto &&[i, x, c] : enumerate(a, b)) {
    vector<int> ap(x + 1);
    for (auto j : rrange(i)) {
      if (x % a[j] or ap[a[j]]) continue;
      for (auto d = 1; d * d <= a[j]; ++d) {
        if (a[j] % d) continue;
        ap[d] = ap[a[j] / d] = 1;
      }
      dinic.add_edge(i, j, 1e9);
    }
    if (c > 0) {
      ans += c;
      dinic.add_edge(src, i, c);
    } else {
      dinic.add_edge(i, dst, -c);
    }
  }
  ans -= dinic.run(src, dst);
  cout << ans << "\n";
}

}  // namespace workspace

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  workspace::main();
}