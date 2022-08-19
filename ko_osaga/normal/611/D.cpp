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

int n;
char str[5005];
int sfx[5005], ord[5005], neword[5005], rev[5005], lcp[5005];
int crit = 1;

bool cmp(int a, int b){
    if(ord[a] != ord[b]) return ord[a] < ord[b];
    return ord[a + crit] < ord[b + crit];
}

int spa[5005][15], lg[5005];

void input(){
	scanf("%d %s",&n,str);
	n = strlen(str);
	for(int i=0; i<n; i++){
		ord[i] = str[i];
		sfx[i] = i;
	}
	ord[n] = -1;
	while(1){
		sort(sfx, sfx + n, cmp);
		if(crit * 2 >= n) break;
		neword[sfx[0]] = 0;
        for(int i=1; i<n; i++){
            neword[sfx[i]] = neword[sfx[i-1]];
            if(cmp(sfx[i-1], sfx[i])) neword[sfx[i]]++;
        }
        for(int i=0; i<n; i++){
            ord[i] = neword[i];
        }
        crit <<= 1;
	}
	for(int i=0; i<n; i++){
		rev[sfx[i]] = i;
	}
	int h = 0;
    for(int i=0; i<n; i++){
        if(rev[i]){
            int j = sfx[rev[i] - 1];
            while(str[i+h] == str[j+h]) h++;
            lcp[rev[i]] = h;
        }
        h = max(h-1, 0);
    }
    memset(spa, 0x3f, sizeof(spa));
    for(int i=1; i<n; i++){
    	spa[i][0] = lcp[i];
    	for(int j=1; j<15; j++){
    		if(i > (1<<(j-1))) 
    			spa[i][j] = min(spa[i][j-1], spa[i-(1<<(j-1))][j-1]);
    	}
    	lg[i] = lg[i-1];
    	while((1 << (lg[i] + 1)) <= i) lg[i]++;
    }
}

int getlcp(int s, int e){
	int t = rev[s];
	int u = rev[e];
	if(t > u) swap(t, u);
	int len = lg[u - t];
	return min(spa[u][len], spa[t + (1<<len)][len]);
}
bool compare(int s, int e, int x){
	int t = getlcp(s, e);
	if(t >= x) return 0;
	return str[s+t] < str[e+t];
}

int dp[5005][5005];
const int mod = 1e9 + 7;

int main(){
	input();
	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>=i; j--){
			dp[i][j] = dp[i][j+1];
			if(j == n-1){
				dp[i][j]++;
				dp[i][j] %= mod;
			}
			if(str[j+1] == '0') continue;
			if(2 * j - i + 1 >= n){
				continue;
			}
			int t = 2 * j - i + 1; // which is lower than n
			if(compare(i, j+1, j-i+1)){
				dp[i][j] += dp[j+1][t];
			}
			else{
				dp[i][j] += dp[j+1][t+1];
			}
			dp[i][j] %= mod;
		}
	}
	cout << dp[0][0];
}