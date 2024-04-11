#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 100005;

int main(){
	string s;
	cin >> s;
	if(!is_sorted(s.begin(), s.end())){
		puts("NO");
		return 0;
	}
	int c1 = count(s.begin(), s.end(), 'a');
	int c2 = count(s.begin(), s.end(), 'b');
	int c3 = count(s.begin(), s.end(), 'c');
	if(c1 > 0 && c2 > 0 && (c3 == c1 || c3 == c2)){
		puts("YES");
	}
	else puts("NO");
}