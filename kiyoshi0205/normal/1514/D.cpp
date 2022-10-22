#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <cassert>
#include <cstddef>
#include <vector>

using usize=unsigned long long;
class range_mode_query {
  class b_node {
  public:
    usize value;
    usize rank;

    b_node(const usize value, const usize rank) : value(value), rank(rank) {}
  };

  class s_node {
  public:
    usize mode;
    usize freq;

    s_node(const usize mode, const usize freq) : mode(mode), freq(freq) {}
  };

  std::vector<b_node> b;
  std::vector<std::vector<usize>> q;
  std::vector<std::vector<s_node>> s;
  usize t;

public:
  range_mode_query() = default;

  range_mode_query(const std::vector<usize> a) : t(1) {
    const usize n = a.size();
    b.assign(n, b_node(0, 0));
    q.assign(n, {});
    while (t * t < n)
      t += 1;
    for (usize i = 0; i != n; i += 1) {
      const usize e = a[i];
      assert(e < n);
      b[i] = b_node(e, q[e].size());
      q[e].push_back(i);
    }
    s.assign(n / t + 1, std::vector<s_node>(n / t + 1, s_node(0, 0)));
    for (usize f = 0; f * t <= n; f += 1) {
      std::vector<usize> freq(n, 0);
      s_node cur(0, 0);
      for (usize l = f + 1; l * t <= n; l += 1) {
        for (usize i = (l - 1) * t; i != l * t; i += 1) {
          const usize e = a[i];
          freq[e] += 1;
          if (freq[e] > cur.freq)
            cur = s_node(e, freq[e]);
        }
        s[f][l] = cur;
      }
    }
  }

  usize query(const usize first, const usize last) const {
    assert(first < last);
    assert(last <= b.size());
    usize bf = first / t + 1;
    usize bl = last / t;
    if (bf >= bl) {
      s_node cur(0, 0);
      for (usize i = first; i != last; i += 1) {
        const b_node &e = b[i];
        const std::vector<usize> &v = q[e.value];
        usize idx;
        while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last)
          cur = s_node(e.value, cur.freq + 1);
      }
      return cur.freq;
    }
    s_node cur = s[bf][bl];
    for (usize i = first; i != bf * t; i += 1) {
      const b_node &e = b[i];
      const std::vector<usize> &v = q[e.value];
      usize idx;
      while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last)
        cur = s_node(e.value, cur.freq + 1);
    }
    for (usize i = bl * t; i != last; i += 1) {
      const b_node &e = b[i];
      const std::vector<usize> &v = q[e.value];
      usize idx;
      while ((idx = e.rank - cur.freq) < v.size() && v[idx] >= first)
        cur = s_node(e.value, cur.freq + 1);
    }
    return cur.freq;
  }
};
#include<iostream>
int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  int N,Q;
  std::cin>>N>>Q;
  std::vector<usize> v(N);
  for(auto& x:v){
    std::cin>>x;
    --x;
  }
  range_mode_query solve(v);
  while(Q--){
    usize l,r;
    std::cin>>l>>r;
    auto x=solve.query(--l,r);
    auto y=r-l-x;
    if(x<=y+1)std::cout<<"1\n";
    else std::cout<<x-y<<'\n';
  }
}