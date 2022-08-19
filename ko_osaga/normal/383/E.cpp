#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <chrono>
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
const int mod = 1e9 + 7;
const int offset = 10000;

int dp[1<<24];
int cnt[1<<24];

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int msk = 0;
		for(auto &i : s){
			msk |= (1<<(i - 'a'));
		}
		msk ^= (1<<24) - 1;
		cnt[msk]++;
	}
	int ret = 0;
	for(int i=0; i<24; i++){
		for(int j=0; j<(1<<24); j++){
			if((j >> i) % 2 == 0){
				cnt[j] += cnt[j + (1<<i)];
			}
		}
	}
	for(int i=0; i<(1<<24); i++){
		ret ^= (n - cnt[i]) * (n - cnt[i]);
	}
	cout << ret;
}