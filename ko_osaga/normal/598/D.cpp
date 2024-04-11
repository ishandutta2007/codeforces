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
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct disj{
	int pa[1000005], cnt[1000005];
	void init(int n){
		for(int i=0; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		cnt[p] += cnt[q];
		return 1;
	}
}disj;

char str[1005][1005];
int n, m, q;

int main(){
	cin >> n >> m >> q;
	for(int i=0; i<n; i++) cin >> str[i];
	disj.init(n*m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(str[i][j] == '*') continue;
			for(int k=0; k<4; k++){
				if(i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] >= n || j + dy[k] >= m){
					continue;
				}
				if(str[i+dx[k]][j+dy[k]] == '*') disj.cnt[i*m+j]++;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m-1; j++){
			if(str[i][j] != '*' && str[i][j+1] != '*'){
				disj.uni(i*m+j, i*m+j+1);
			}
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m; j++){
			if(str[i][j] != '*' && str[i+1][j] != '*'){
				disj.uni(i*m+j, i*m+j+m);
			}
		}
	}
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		x--;
		y--;
		if(str[x][y] == '*'){
			puts("0");
		}
		else{
			printf("%d\n",disj.cnt[disj.find(x*m+y)]);
		}
	}
}