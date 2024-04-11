#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

string s, t;

int main(){
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int v = max(s.size(), t.size());
	while(s.size() < v) s.push_back('0');
	while(t.size() < v) t.push_back('0');
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	if(s < t) puts("<");
	else if(s > t) puts(">");
	else puts("=");
}