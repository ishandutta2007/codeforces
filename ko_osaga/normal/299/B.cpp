#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int ok[300005], n, k;
string s;

int main(){
	cin >> n >> k >> s;
	ok[n-1] = 1;
	int p = n-1;
	for(int i=n-2; i>=0; i--){
		if(s[i] != '.') continue;
		while(p > i + k) p--;
		while(p > i && !ok[p]) p--;
		ok[i] = ok[p];
	}
	cout << (ok[0] ? "YES" : "NO");
}