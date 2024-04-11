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

bool vis[105][105];

int f2(int x1, int y1, int x2, int y2);

int f1(int x1, int y1, int x2, int y2){
	if(x1 == x2 && y1 == y2) return 1;
	if(!vis[x1][y1] && x1 != x2 && !f2(x1+1, y1, x2, y2)) return 1;
	if(!vis[x1][y1] && y1 != y2 && !f2(x1, y1+1, x2, y2)) return 1;
	if(!vis[x2][y2] && x1 != x2 && !f2(x1, y1, x2-1, y2)) return 1;
	if(!vis[x2][y2] && y1 != y2 && !f2(x1, y1, x2, y2-1)) return 1;
	return 0;
}

int f2(int x1, int y1, int x2, int y2){
	for(int i=x1; i<=x2; i++){
		for(int j=y1; j<=y2; j++){
			if(i == x1 && j == y1) continue;
			if(i == x2 && j == y2) continue;
			vis[i][j] = 1;
			int ret = 0;
			if(f1(x1, y1, x2, y2) == 0){
				ret = 1;
			}
			vis[i][j] = 0;
			if(ret == 1) return 1;
		}
	}
	return 0;
}

int main(){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			//printf("%d ",f1(1,1 , 1+i, 1+j));
		}
		//puts("");
	}
	scanf("%*d %*d");
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int dx1 = abs(x2 - x1), dy2 = abs(y2 - y1);
	if(max(dx1, dy2) <= 4 && dx1 + dy2 <= 6){
		cout << "First";
		return 0;
	}
	else{
		cout << "Second";
		return 0;
	}
}