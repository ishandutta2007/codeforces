#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int sx, sy;
int x, y;
map<pair<int, int>, int> mp;
int ans;
pair<int, int> p;

int main(){
	scanf("%d%d%d", &n, &sx, &sy);
	while(n--){
		scanf("%d%d", &x, &y);
		if(x ^ sx){
			mp[{x > sx ? 1 : -1, 0}]++;
			if(mp[{x > sx ? 1 : -1, 0}] > ans) ans = mp[{x > sx ? 1 : -1, 0}], p = {x > sx ? 1 : -1, 0};
		}
		if(y ^ sy){
			mp[{0, y > sy ? 1 : -1}]++;
			if(mp[{0, y > sy ? 1 : -1}] > ans) ans = mp[{0, y > sy ? 1 : -1}], p = {0, y > sy ? 1 : -1};
		}
		
	}
	printf("%d\n", ans);
	printf("%d %d", sx + p.first, sy + p.second);
	
}