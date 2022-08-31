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

int n, x, y; 
char str[MAXN];
int dx[256], dy[256];
int sum1[MAXN], sum2[MAXN];
bool bad(int s, int e){
	if(s > e) return 0;
	int px = x, py = y;
	px += sum1[s] - sum1[e];
	py += sum2[s] - sum2[e];
	px = abs(px);
	py = abs(py);
	if((px + py) % 2 != (e - s) % 2) return false;
	if(px + py <= e - s) return true;
	return false;
}

int main(){
	scanf("%d %s %d %d",&n,str,&x,&y);
	dy['U'] = 1;
	dy['D'] = -1;
	dx['L'] = -1;
	dx['R'] = 1;
	for(int i=0; i<n; i++){
		x -= dx[str[i]];
		y -= dy[str[i]];
	}
	for(int i=n-1; i>=0; i--){
		sum1[i] = dx[str[i]];
		sum2[i] = dy[str[i]];
		sum1[i] += sum1[i+1];
		sum2[i] += sum2[i+1];
	}
	int e = 0;
	int ret = 1e9;
	for(int i=0; i<n; i++){
		while(e < n && !bad(i, e)) e++;
		if(bad(i, e)) ret = min(ret, e - i);
	}
	if(ret > n) ret = -1;
	cout << ret << endl;
}