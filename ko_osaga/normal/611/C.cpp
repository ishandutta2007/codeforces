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

int n, m;
char str[505][505];
int s1[505][505], s2[505][505];

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> str[i]+1;
	}
	for(int i=1; i<=n; i++){
		for(int j=2; j<=m; j++){
			if(str[i][j-1] == '.' && str[i][j] == '.'){
				s1[i][j]++;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(str[i][j] == '.' && str[i-1][j] == '.'){
				s2[i][j]++;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			s1[i][j] += s1[i-1][j] + s1[i][j-1] - s1[i-1][j-1];
			s2[i][j] += s2[i-1][j] + s2[i][j-1] - s2[i-1][j-1];
		}
	}
	int ret = 0;
	int q;
	cin >> q;
	while(q--){
		int sx, ex, sy, ey;
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		int ret1 = s1[ex][ey] - s1[sx-1][ey] - s1[ex][sy] + s1[sx-1][sy];
		int ret2 = s2[ex][ey] - s2[sx][ey] - s2[ex][sy-1] + s2[sx][sy-1];
printf("%d\n",ret1 + ret2);
	}
}