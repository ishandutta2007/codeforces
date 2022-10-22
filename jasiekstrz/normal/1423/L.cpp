#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 1000 + 10, kax = 35, S = 20, INF = 1e9 + 10;

#define _GLIBCXX_BITSET_BITS_PER_WORD  (__CHAR_BIT__ * __SIZEOF_LONG__)
#define _GLIBCXX_BITSET_WORDS(__n) \
  ((__n) / _GLIBCXX_BITSET_BITS_PER_WORD + \
   ((__n) % _GLIBCXX_BITSET_BITS_PER_WORD == 0 ? 0 : 1))

namespace std
{
    template<size_t N>
    bool operator<(const bitset<N>& lhs, const bitset<N>& rhs)
    {
        typedef array<unsigned long, _GLIBCXX_BITSET_WORDS(N)> wordarr_t;
        return *reinterpret_cast<const wordarr_t*>(&lhs) < *reinterpret_cast<const wordarr_t*>(&rhs);
    }
    template<size_t N>
    bool operator>(const bitset<N>& lhs, const bitset<N>& rhs) { return rhs < lhs; }
}

int n,s,d;
bitset<nax> state[kax], cur, tmp;
map<bitset<nax>, int>mp;
bitset<nax> xd[(1<<20)];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> d;
	for(int i = 0; i < s; ++i) {
		int c;
		cin >> c;
		for(int x, j = 0; j < c; ++j) {
			cin >> x;
			x--;
			state[i][x] = 1;
		}
	}
	for(int mask = 0; mask < (1 << min(s, S)); ++mask) {
		//cur.reset();
		int cnt = __builtin_popcount(mask);
		for(int i = 0; i < min(s, S); ++i) {
			if((1 << i) & mask) {
				xd[mask] = xd[mask ^ (1 << i)] ^ state[i];
			}
		}
		if(!mp.count(xd[mask])) mp[xd[mask]] = cnt;
		else mp[xd[mask]] = min(mp[xd[mask]], cnt);
	}
	while(d--) {
		int c;
		cin >> c;
		cur.reset();
		for(int x, i = 0; i < c; ++i) {
			cin >> x;
			x--;
			cur[x] = 1;
		}
		int ans = INF;
		for(int mask = 0; mask < (1 << (max(0, s - S))); ++mask) {
			tmp.reset();
			int cnt = 0;
			for(int i = S; i < s; ++i) {
				if((1 << (i - S)) & mask) {
					tmp ^= state[i];
					cnt++;
				}
			}
			tmp ^= cur;
			if(mp.count(tmp)) {
				ans = min(ans, mp[tmp] + cnt);
			}
		}
		if(ans == INF) {
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
	}
}