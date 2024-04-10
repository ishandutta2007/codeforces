#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t, n;
char s[maxn];
map<pair<int, int>, int> mp; 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int x = 0, y = 0;
		mp.clear();
		for(int i = 1;i <= n;i++){
			if(s[i] == 'D') x++;
			else y++;
			int gcd = __gcd(x, y), xx = x / gcd, yy = y / gcd;
			printf("%d ", ++mp[{xx, yy}]);
		}
		puts("");
	}
}