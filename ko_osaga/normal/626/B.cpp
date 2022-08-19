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
const int mod = 1e9 + 9;

bool vis[205][205][205];

void dfs(int x, int y, int z){
	if(x < 0 || y < 0 || z < 0) return;
	if(vis[x][y][z]) return;
	vis[x][y][z] = 1;
	dfs(x-1, y-1, z+1);
	dfs(x-1, y+1, z-1);
	dfs(x+1, y-1, z-1);
	if(x>1)dfs(x-1, y, z);
	if(y>1)dfs(x, y-1, z);
	if(z>1)dfs(x, y, z-1);
}

int main(){
	int n;
	char str[205];
	cin >> n >> str;
	int c1 = count(str, str+n, 'R');
	int c2 = count(str, str+n, 'G');
	int c3 = count(str, str+n, 'B');
	dfs(c1, c2, c3);
	if(vis[0][0][1]) putchar('B');
	if(vis[0][1][0]) putchar('G');
	if(vis[1][0][0]) putchar('R');
}