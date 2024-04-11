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
typedef pair<int, int> pi;

vector<int> v[22];
int n, m, d, chk[1<<20];
int rev[100005];

int main(){
	cin >> n >> m >> d;
	for(int i=0; i<m; i++){
		int t;
		scanf("%d",&t);
		v[i].resize(t+2);
		for(int j=1; j<=t; j++) scanf("%d",&v[i][j]), rev[v[i][j]] = i;
		v[i][t+1] = n+1;
	}
	int cnt[22] = {};
	for(int i=1; i<=d; i++) cnt[rev[i]]++;
	for(int i=0; i<=n-d; i++){
		int mask = 0;
		for(int j=0; j<m; j++){
			if(cnt[j]) mask |= (1<<j);
		}
		cnt[rev[i+1]]--;
		cnt[rev[i+d+1]]++;
		chk[((1<<m) - 1)^mask] = 1;
		// no select all of [i+1, i+d] -> wrong!
	}
	int ret = 1e9;
	for(int i=(1<<m)-1; i>=0; i--){
		int cnt = 0;
		for(int j=0; j<m; j++){
			if((i >> j) & 1) cnt++;
			if(chk[i|(1<<j)]) chk[i] = 1;
		}
		if(!chk[i]) ret = min(ret, cnt);
	}
	printf("%d\n", ret);
}