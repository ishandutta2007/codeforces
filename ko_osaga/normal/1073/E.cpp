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
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 200005;
const int mod = 998244353;

pi dp[22][2][2][1024];
int pwr[22], popcnt[2000];
char str[22];
int l, k;;

pi g(int pos, int lez, int mtc, int msk){
	if(pos == l) return popcnt[msk] <= k ? pi(1, 0) : pi(0, 0);
	if(~dp[pos][lez][mtc][msk].first) return dp[pos][lez][mtc][msk];
	pi ret(0, 0);
	for(int i=0; i<10; i++){
		if(mtc && str[pos] < i) break;
		int nlez = lez & (i == 0);
		if(mtc && str[pos] == i){
			auto k = g(pos + 1, nlez, 1,nlez ? msk :( msk | (1<<i)));
			ret.first += k.first;
			ret.second += k.second;
			ret.second += (1ll * k.first * pwr[pos] % mod) * i % mod;
		}
		else{
			auto k =  g(pos + 1, nlez, 0, nlez ? msk : (msk | (1<<i)));
			ret.first += k.first;
			ret.second += k.second;
			ret.second += (1ll * k.first * pwr[pos] % mod) * i % mod;
		}
		ret.first %= mod;
		ret.second %= mod;
	}
	return dp[pos][lez][mtc][msk] = ret;
}

lint f(lint x, int _k){
	k = _k;
	l = 0;
	memset(str, 0, sizeof(str));
	while(x){
		str[l++] = x % 10;
		x /= 10;
	}
	reverse(str, str + l);
	pwr[l- 1] = 1;
	for(int i=l-2; i>=0; i--) pwr[i] = pwr[i+1] * 10ll % mod;
	for(int i=0; i<22; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++) for(int l=0; l<1024; l++){
		dp[i][j][k][l] = pi(-1, -1);
	}
	return g(0, 1, 1, 0).second;
}

int main(){
	for(int i=1; i<1024; i++){
		popcnt[i] = popcnt[i - (i & -i)] + 1;
	}
	lint l, r, k;
	cin >> l >> r >> k;
	cout << (f(r, k) - f(l-1, k) + mod) % mod << endl;
}