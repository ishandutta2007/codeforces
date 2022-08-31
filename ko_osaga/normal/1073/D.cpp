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

int n, a[MAXN];
lint t;

int main(){
	cin >> n >> t;
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	lint ans = 0;
	while(t){
		lint sum = accumulate(a, a + n, 0ll);
		ans += (t / sum) * (n - count(a, a + n, 0));
		t %= sum;
		int pos = 0;
		for(int i=0; i<n; i++){
			if(a[i] && t >= a[i]){
				t -= a[i];
				ans++;
			}
			else if(a[i]){
				pos = i;
				break;
			}
		}
		a[pos] = 0;
		rotate(a, a + pos, a + n);
		bool good = false;
		for(int i=0; i<n; i++){
			if(a[i] && t >= a[i]) good = true; 
			else a[i] = 0;
		}
		if(!good) break;
	}
	cout << ans << endl; 
}