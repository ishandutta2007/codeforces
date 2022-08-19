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

int adj1[405][405], adj2[405][405];

int main(){
	int n, m;
	cin >> n >> m;
	memset(adj1,0x3f,sizeof(adj1));
	memset(adj2,0x3f,sizeof(adj2));
	while(m--){
		int s, e;
		cin >> s >> e;
		adj1[s][e] = adj1[e][s] = 1;
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(adj1[i][j] != 1){
				adj2[i][j] = adj2[j][i] = 1;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n;j++){
			for(int k=1; k<=n; k++){
				adj1[j][k] = min(adj1[j][k], adj1[j][i] + adj1[i][k]);
				adj2[j][k] = min(adj2[j][k], adj2[j][i] + adj2[i][k]);
			}
		}
	}
	int ret = max(adj1[1][n], adj2[1][n]);
	if(ret > 1e9) ret = -1;
	cout << ret;
}