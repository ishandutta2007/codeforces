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

int n, m, q;
int a[105][105];
int t[10005], qa[10005], qb[10005], qc[10005];

int main(){
	cin >> n >> m >> q;
	for(int i=0; i<q; i++){
		cin >> t[i];
		if(t[i] == 3){
			cin >> qa[i] >> qb[i] >> qc[i];
		}
		else{
			cin >> qa[i];
		}
	}
	for(int i=q-1; i>=0; i--){
		if(t[i] == 1){
			int lst = a[qa[i]][m];
			for(int j=m-1; j; j--){
				a[qa[i]][j+1] = a[qa[i]][j];
			}
			a[qa[i]][1] = lst;
		}
		if(t[i] == 2){
			int lst = a[n][qa[i]];
			for(int j=n-1; j; j--){
				a[j+1][qa[i]] = a[j][qa[i]];
			}
			a[1][qa[i]] = lst;
		}
		if(t[i] == 3){
			a[qa[i]][qb[i]] = qc[i];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
}