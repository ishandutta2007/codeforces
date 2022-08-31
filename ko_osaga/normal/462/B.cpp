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
const int B = 300;

int cnt[26];
int main(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	for(auto &i : s){
		cnt[i - 'A']++;
	}
	sort(cnt, cnt + 26);
	lint ret = 0;
	for(int i=25; i>=0; i--){
		int dx = min(k, cnt[i]);
		ret += 1ll * dx * dx;
		k -= dx;
	}
	cout << ret;
}