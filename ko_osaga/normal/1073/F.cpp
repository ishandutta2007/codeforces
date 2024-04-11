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
using pi = pair<int, int>;
const int MAXN = 200005;

int n, par[MAXN], dep[MAXN];
vector<int> gph[MAXN];
vector<int> dfn;

void dfs(int x){
	dfn.push_back(x);
	for(auto &i : gph[x]){
		par[i] = x;
		dep[i] = dep[x] + 1;
		gph[i].erase(find(gph[i].begin(), gph[i].end(),x));
		dfs(i);
	}
}

int L(int x, int y){
	if(dep[x] > dep[y]) return L(y, x);
	if(x == y) return x;
	return L(x, par[y]);
}

pi dfs2(int x, int p){
	pi ret(0, x);
	for(auto &i : gph[x]){
		if(i != p){
			auto l = dfs2(i, x);
			l.first++;
			ret = max(ret, l);
		}
	}
	return ret;
}

struct Fsomething{
	int first, second;
	int fsomething;
	Fsomething(int x, int y, int z){
		first = x;
		second = y;
		fsomething = z;
	}
	Fsomething(){}
	bool operator<(const Fsomething &f)const{
		return pi(first, fsomething) < pi(f.first, f.fsomething);
	}
}dp[MAXN], pdp[MAXN];
int far[MAXN], pfar[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1);
	reverse(dfn.begin(), dfn.end());
	for(auto &x : dfn){
		for(auto &i : gph[x]){
			far[x] = max(far[x], far[i] + 1);
		}
	}
	reverse(dfn.begin(), dfn.end());
	for(auto &x : dfn){
		int fmax = 0, fv = x;
		for(auto &i : gph[x]){
			if(fmax < far[i] + 1){
				fmax = far[i] + 1;
				fv = i;
			}
		}
		for(auto &i : gph[x]){
			if(fv == i){
				for(auto &j : gph[x]){
					if(i != j) pfar[i] = max(pfar[i], far[j] + 1);
				}
			}
			else pfar[i] = fmax;
			if(x != 1) pfar[i] = max(pfar[i], pfar[x] + 1);
		}
	}
	vector<vector<int>> Fsomethinging(n + 1);
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]) Fsomethinging[i].push_back(far[j]);
		sort(Fsomethinging[i].rbegin(), Fsomethinging[i].rend());
	}
	auto GTFO = [&](int x){
		return Fsomethinging[x][0] + Fsomethinging[x][1];
	};
	auto GTFO2 = [&](int x){
		vector<int> v;
		if(par[x] != 1) v.push_back(pfar[par[x]]);
		if(Fsomethinging[x].size() >= 1) v.push_back(Fsomethinging[x][0]);
		if(Fsomethinging[x].size() >= 2) v.push_back(Fsomethinging[x][1]);
		sort(v.rbegin(), v.rend());
		return v[0] + v[1];
	};
	reverse(dfn.begin(), dfn.end());
	for(auto &x : dfn){
		if(gph[x].size() >= 2) dp[x] = Fsomething(0, x, GTFO(x));
		else dp[x] = Fsomething(-1e9, 0, -1e9);
		for(auto &j : gph[x]){
			dp[x] = max(dp[x], Fsomething(dp[j].first + 1, dp[j].second, dp[j].fsomething));
		}
	}
	reverse(dfn.begin(), dfn.end());
	for(auto &x : dfn){
		if(gph[x].size() == 0) continue;
		Fsomething bburim = Fsomething(-1e9, 0, -1e9);
		if(gph[x].size() + (x != 1) >= 3) bburim = Fsomething(0, x, GTFO2(x));
		if(x != 1) bburim = max(bburim, Fsomething(pdp[x].first + 1, pdp[x].second, pdp[x].fsomething));
		Fsomething cur(-1e9, -1e9, -1e9); int curpos;
		for(auto &j : gph[x]){
			if(cur < dp[j]){
				cur = dp[j];
				curpos = j;
			}
		}
		Fsomething bburim1 = bburim;
		Fsomething bburim2 = bburim;
		for(auto &j : gph[x]){
			if(j != curpos){
				bburim1 = max(bburim1, Fsomething(dp[j].first + 1, dp[j].second, dp[j].fsomething));
			}
			bburim2 = max(bburim2, Fsomething(dp[j].first + 1, dp[j].second, dp[j].fsomething));
		}
		for(auto &j : gph[x]){
			if(j == curpos) pdp[j] = bburim1;
			else pdp[j] = bburim2;
		}
	}
	pi maxlen(-1, -1);
	int st = -1, ed = -1;
	for(int i=2; i<=n; i++){
	//	printf("%d %d %d %d\n", dp[i].first, dp[i].second, pdp[i].first, pdp[i].second);
		if(pdp[i].first >= 0 && dp[i].first >= 0){
			int Fsomething111 = pdp[i].first + dp[i].first + 1;
			int Fsomething222 = pdp[i].fsomething + dp[i].fsomething;
			if(maxlen < pi(Fsomething111, Fsomething222)){
				maxlen = pi(Fsomething111, Fsomething222);
				st = pdp[i].second;
				ed = dp[i].second;
			}
		}
		gph[i].push_back(par[i]);
	}
//	printf("%d %d %d\n", maxlen, st, ed);
	int lca = L(st, ed);
	for(int i=st; i!=lca; i=par[i]){
		gph[i].erase(find(gph[i].begin(), gph[i].end(), par[i]));
		gph[par[i]].erase(find(gph[par[i]].begin(), gph[par[i]].end(), i));
	}
	for(int i=ed; i!=lca; i=par[i]){
		gph[i].erase(find(gph[i].begin(), gph[i].end(), par[i]));
		gph[par[i]].erase(find(gph[par[i]].begin(), gph[par[i]].end(), i));
	}
	int st1 = dfs2(st, -1).second;
	int st2 = dfs2(st1, -1).second;
	int ed1 = dfs2(ed, -1).second;
	int ed2 = dfs2(ed1, -1).second;
	printf("%d %d\n%d %d", st1, ed1, st2, ed2);
}