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

int n;
string s[15];

vector<int> v;
int nxt[16][500005];
int dp[1<<15][105];

int solve(){
	for(int i=0; i<n; i++){
		nxt[i][v.size()] = 1e9;
	}
	for(int i=v.size()-1; i>=0; i--){
		for(int j=0; j<n; j++){
			if(v[i] == j){
				nxt[j][i] = i;
			}
			else{
				nxt[j][i] = nxt[j][i+1];
			}
		}
	}
	fill(dp[0], dp[0] + 105, -1);
	for(int i=1; i<(1<<n); i++){
		for(int j=0; j<=(n * (n-1)) / 2; j++){
			dp[i][j] = 1e9;
			int cnt = 0;
			for(int k=n-1; k>=0; k--){
				if((i >> k) & 1){
					if(j >= cnt){
						int p = dp[i^(1<<k)][j - cnt] + 1;
						if(p < v.size()) dp[i][j] = min(dp[i][j], nxt[k][p]);
					}
					else break;
					cnt++;
				}
			}
		}
	}
	for(int i=0; i<=(n*(n-1))/2; i++){
		if(dp[(1<<n)-1][i] < v.size()) return i;
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
	int q;
	cin >> q;
	int retidx = -1, retval = 1e9;
	for(int i=1; i<=q; i++){
		int l;
		cin >> l;
		v.clear();
		bool vis[15] = {};
		while(l--){
			string t;
			cin >> t;
			for(int j=0; j<n; j++){
				if(s[j] == t){
					vis[j] = 1;
					v.push_back(j);
					break;
				}
			}
		}
		bool bad = 0;
		for(int i=0; i<n; i++){
			if(!vis[i]){
				bad = 1;
				break;
			}
		}
		if(bad) continue;
		int t = solve();
		if(retval > t){
			retval = t;
			retidx = i;
		}
	}
	if(retidx == -1){
		puts("Brand new problem!");
		return 0;
	}
	printf("%d\n",retidx);
	printf("[:");
	for(int j=0; j<n*(n-1)/2 + 1 - retval; j++){
		putchar('|');
	}
	printf(":]");
}