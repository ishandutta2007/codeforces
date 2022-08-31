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

vector<pi> intv[200005];

bool enclose(int x, int y){
	if(intv[y].size() && intv[y][0].first <= x && x <= intv[y][0].second) return 1;
	return 0;
}
int main(){
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	for(int i=0; i<m; i++){
		int s, e, x;
		scanf("%d %d %d",&x,&s,&e);
		if(x > 2 * n) break;
		intv[x].emplace_back(s, e);
	}
	for(int i=1; s != e; i++){
		int st = s;
		int ed = (s < e ? (s+1) : (s-1));
		if(enclose(st, i) || enclose(ed, i)){
			putchar('X');
		}
		else{
			putchar(st < ed ? 'R' : 'L');
			s = ed;
		}
	}
}