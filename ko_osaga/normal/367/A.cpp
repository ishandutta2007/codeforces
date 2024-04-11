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

int n;
char str[100005];
int sx[100005], sy[100005], sz[100005];

int main(){
	cin >> (str + 1);
	n = strlen(str+1);
	for(int i=1; i<=n; i++){
		sx[i] = sx[i-1] + (str[i] == 'x');
		sy[i] = sy[i-1] + (str[i] == 'y');
		sz[i] = sz[i-1] + (str[i] == 'z');
	}
	int q;
	cin >> q;
	while(q--){
		int s, e;
		scanf("%d %d",&s,&e);
		if(e - s + 1 <= 2){
			puts("YES");
			continue;
		}
		vector<int> v, w;
		v.push_back(sz[e] - sz[s-1]);
		v.push_back(sy[e] - sy[s-1]);
		v.push_back(sx[e] - sx[s-1]);
		w.push_back((e - s + 1) / 3 + ((e - s + 1) % 3 > 2));
		w.push_back((e - s + 1) / 3 + ((e - s + 1) % 3 > 1));
		w.push_back((e - s + 1) / 3 + ((e - s + 1) % 3 > 0));
		bool ok = 0;
		for(int i=0; i<3; i++){
			rotate(v.begin(), v.begin() + 1, v.end());
			if(v == w) ok = 1;
		}
		puts(ok ? "YES" : "NO");
	}
}