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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

lint s, x;

int main(){
	lint ret = 0;
	cin >> s >> x;
	vector<lint> knap;
	int cnt = 0;
	for(int i=50; i>=0; i--){
		if((x >> i) & 1){
			s -= (1ll<<i);
			cnt++;
		}
		else{
			knap.push_back((2ll << i));
		}
	}
	if(s < 0){
		puts("0");
		return 0;
	}
	if(s == 0){
		printf("%lld", (1ll<<cnt) - 2);
		return 0;
	}
	for(auto &i : knap){
		if(s >= i) s -= i;
	}
	if(s > 0){
		puts("0");
		return 0;
	}
	else{
		printf("%lld",1ll<<cnt);
	}
}