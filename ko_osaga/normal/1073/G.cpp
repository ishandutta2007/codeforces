#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif




using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 200005;
const int MAXT = 1050000;

struct sfxarray{
	int ord[MAXN], nord[MAXN], cnt[MAXN], aux[MAXN];
	void solve(int n, char *str, int *sfx, int *rev, int *lcp){
		int p = 1;
		memset(ord, 0, sizeof(ord));
		for(int i=0; i<n; i++){
			sfx[i] = i;
			ord[i] = str[i];
		}
		int pnt = 1;
		while(1){
			memset(cnt, 0, sizeof(cnt));
			for(int i=0; i<n; i++) cnt[ord[min(i+p, n)]]++;
			for(int i=1; i<=n || i<=255; i++) cnt[i] += cnt[i-1];
			for(int i=n-1; i>=0; i--)
				aux[--cnt[ord[min(i+p, n)]]] = i;
			memset(cnt, 0, sizeof(cnt));
			for(int i=0; i<n; i++) cnt[ord[i]]++;
			for(int i=1; i<=n || i<=255; i++) cnt[i] += cnt[i-1];
			for(int i=n-1; i>=0; i--)
				sfx[--cnt[ord[aux[i]]]] = aux[i];
			if(pnt == n) break;
			pnt = 1;
			nord[sfx[0]] = 1;
			for(int i=1; i<n; i++){
				if(ord[sfx[i-1]] != ord[sfx[i]] || ord[sfx[i-1] + p] != ord[sfx[i] + p]){
					pnt++;
				}
				nord[sfx[i]] = pnt;
			}
			memcpy(ord, nord, sizeof(int) * n);
			p *= 2;
		}
		for(int i=0; i<n; i++) rev[sfx[i]] = i;
		int h = 0;
		for(int i=0; i<n; i++){
			if(rev[i]){
				int prv = sfx[rev[i] - 1];
				while(str[prv + h] == str[i + h]) h++;
				lcp[rev[i]] = h;
			}
			h = max(h-1, 0);
		}
	}
}sfxa;

int n, q, sfx[MAXN], rev[MAXN], lcp[MAXN];
char str[MAXN];

struct seg{
	pi tree[MAXT]; int lim;
	void init(int n, int *a){
		for(lim = 1; lim <= n; lim <<= 1);
		fill(tree, tree + 2 * lim, pi(1e9, -1));
		for(int i=0; i<n; i++){
			tree[i + lim] = pi(a[i], i);
		}
		for(int i=lim-1; i; i--){
			tree[i] = min(tree[2*i], tree[2*i+1]);
		}
	}
	pi query(int s, int e){
		s += lim;
		e += lim;
		pi ret(1e9, -1);
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}seg1, seg2;

vector<pi> v;
int sai[2 * MAXN];
int psum[2][2 * MAXN];

int sum(int v, int l, int r){
	return psum[v][r] - (l ? psum[v][l-1] : 0);
}

lint solve(int s, int e){
	if(s == e) return 0;
	auto k = seg2.query(s + 1, e);
	lint ans = solve(s, k.second - 1) + solve(k.second, e);
	ans += 1ll * sum(0, s, k.second - 1) * sum(1, k.second, e) * k.first;
	ans += 1ll * sum(1, s, k.second - 1) * sum(0, k.second, e) * k.first;
	return ans;
}

int main(){
	scanf("%d %d %s",&n,&q,str);
	sfxa.solve(n, str, sfx, rev, lcp);
	seg1.init(n, lcp);
	while(q--){
		int p, q; scanf("%d %d",&p,&q);
		v.clear();
		for(int i=0; i<p; i++){
			int x; scanf("%d",&x);
			v.emplace_back(rev[x-1], 0);
		}
		for(int i=0; i<q; i++){
			int x; scanf("%d",&x);
			v.emplace_back(rev[x-1], 1);
		}
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++){
			psum[v[i].second][i] = 1;
			psum[v[i].second^1][i] = 0;
			if(i > 0){
				psum[0][i] += psum[0][i-1];
				psum[1][i] += psum[1][i-1];
			}
		}
		for(int i=1; i<v.size(); i++){
			if(v[i-1].first == v[i].first) sai[i] = n - sfx[v[i].first];
			else sai[i] = seg1.query(v[i-1].first + 1, v[i].first).first;
		}
		seg2.init(v.size(), sai);
		printf("%lld\n", solve(0, v.size() - 1));
	}
}