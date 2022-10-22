#include <cassert>
#include <vector>

template <class monoid, class isomorphism>
class lazy_segment_tree
{
    using size_type = typename std::vector<monoid>::size_type;

    size_type orig_n, height, ext_n;
    std::vector<monoid> data;
    std::vector<isomorphism> lazy;

    void recalc(const size_type node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

    void apply(size_type index, const isomorphism &iso)
    {
        iso.apply(data[index]);
        if(index < ext_n) lazy[index] *= iso;
    }

    void push(size_type index)
    {
        if(index >= ext_n) return;
        apply(index << 1, lazy[index]);
        apply(index << 1 | 1, lazy[index]);
        lazy[index] = isomorphism{};
    }

    template <class pred_type>
    size_type left_search_subtree(size_type index, const pred_type pred, monoid mono)
    {
        assert(index);
        while(index < ext_n)
        {
            push(index);
            const monoid tmp = data[(index <<= 1) | 1] + mono;
            if(pred(tmp)) mono = tmp;
            else ++index;
        }
        return ++index -= ext_n;
    }

    template <class pred_type>
    size_type right_search_subtree(size_type index, const pred_type pred, monoid mono)
    {
        assert(index);
        while(index < ext_n)
        {
            push(index);
            const monoid tmp = mono + data[index <<= 1];
            if(pred(tmp)) ++index, mono = tmp;
        }
        return (index -= ext_n) < orig_n ? index : orig_n;
    }

public:
    lazy_segment_tree(const size_type n = 0)
        : orig_n{n}, height(orig_n > 1 ? 32 - __builtin_clz(orig_n - 1) : 0), ext_n{1u << height}, data(ext_n << 1), lazy(ext_n) {}

    lazy_segment_tree(const size_type n, const monoid &init) : lazy_segment_tree(n)
    {
        std::fill(std::next(std::begin(data), ext_n), std::end(data), init);
        for(size_type i{ext_n}; --i; ) recalc(i);
    }

    template <class iter_type, class value_type = typename std::iterator_traits<iter_type>::value_type>
    lazy_segment_tree(iter_type first, iter_type last)
        : orig_n(std::distance(first, last)), height(orig_n > 1 ? 32 - __builtin_clz(orig_n - 1) : 0), ext_n{1u << height}, data(ext_n << 1), lazy(ext_n)
    {
        static_assert(std::is_constructible<monoid, value_type>::value, "monoid(iter_type::value_type) is not constructible.");
        for(auto iter{std::next(std::begin(data), ext_n)}; iter != std::end(data) && first != last; ++iter, ++first) *iter = monoid(*first);
        for(size_type i{ext_n}; --i; ) recalc(i);
    }

    template <class container_type, typename = typename container_type::value_type>
    lazy_segment_tree(const container_type &cont) : lazy_segment_tree(std::begin(cont), std::end(cont)) {}

    // copy of the element at position i.
    typename decltype(data)::const_reference operator[](size_type i) { return fold(i, i + 1); }

    void update(size_type index, const isomorphism &iso) { update(index, index + 1, iso); }

    void update(size_type first, size_type last, const isomorphism &iso)
    {
        assert(last <= orig_n);
        if(first >= last) return;
        first += ext_n, last += ext_n - 1;
        for(size_type i = height; i; --i) push(first >> i), push(last >> i);
        for(size_type l = first, r = last + 1; last; l >>= 1, r >>= 1)
        {
            if(l < r)
            {
                if(l & 1) apply(l++, iso);
                if(r & 1) apply(--r, iso);
            }
            if(first >>= 1, last >>= 1)
            {
                recalc(first), recalc(last);
            }
        }
    }

    monoid fold() { return fold(0, orig_n); }

    monoid fold(size_type first, size_type last)
    {
        assert(last <= orig_n);
        if(first >= last) return monoid{};
        first += ext_n, last += ext_n - 1;
        monoid left_val{}, right_val{};
        for(size_type l = first, r = last + 1; last; l >>= 1, r >>= 1)
        {
            if(l < r)
            {
                if(l & 1) left_val = left_val + data[l++];
                if(r & 1) right_val = data[--r] + right_val;
            }
            if(first >>= 1, last >>= 1)
            {
                lazy[first].apply(left_val);
                lazy[last].apply(right_val);
            }
        }
        return left_val + right_val;
    }

    template <class pred_type>
    size_type left_search(size_type right, const pred_type pred)
    {
        assert(right <= orig_n);
        right += ext_n - 1;
        for(size_type i{height}; i; --i) push(right >> i);
        ++right;
        monoid mono{};
        for(size_type left{ext_n}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = data[--right] + mono;
                if(!pred(tmp)) return left_search_subtree(right, pred, mono);
                mono = tmp;
            }
        }
        return 0;
    }

    template <class pred_type>
    size_type right_search(size_type left, const pred_type pred)
    {
        assert(left <= orig_n);
        left += ext_n;
        for(size_type i{height}; i; --i) push(left >> i);
        monoid mono{};
        for(size_type right{ext_n << 1}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = mono + data[left];
                if(!pred(tmp)) return right_search_subtree(left, pred, mono);
                mono = tmp;
                ++left;
            }
        }
        return orig_n;
    }
}; //class lazy_segment_tree


#include <iostream>
using namespace std;

struct mino
{
    int val=1<<30;
    mino() {}
    mino(int v) : val(v) {}
    mino operator+(const mino& rhs) const
    {
        return val<rhs.val ? *this:rhs;
    }
};

struct iso
{
    int val;
    iso(int v=0) : val(v) {}
    iso &operator*=(const iso& rhs)
    {
        val+=rhs.val;
        return *this;
    }
    void apply(mino& rhs) const
    {
        rhs.val+=val;
    }
};

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    lazy_segment_tree<mino,iso> laz(1000000,0);

    int n,m; cin>>n>>m;
    vector<int> a(n),b(m);
    for(int &e: a)
    {
        cin>>e;
        laz.update(0,e,-1);
    }
    for(int &e: b)
    {
        cin>>e;
        laz.update(0,e,1);
    }

    auto pred=[&](mino x)->bool
    {
        return x.val>=0;
    };

    int Q; cin>>Q;
    while(Q--)
    {
        int k,i,x; cin>>k>>i>>x; --i;
        if(k==1)
        {
            laz.update(0,a[i],1);
            laz.update(0,x,-1);
            a[i]=x;
        }
        else
        {
            laz.update(0,b[i],-1);
            laz.update(0,x,1);
            b[i]=x;
        }
        // cout << laz.fold().val << "\n";
        auto ans=laz.left_search(1000000,pred);
        if(ans) cout << ans << "\n";
        else cout << -1 << "\n";
    }
}