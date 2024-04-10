#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, s, k;
map<int, bool> mp;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &s, &k);
		mp.clear();
		while(k--){
			scanf("%d", &x);
			mp[x] = true;
		}
		for(int i = 0;;i++){
			if(s + i <= n && !mp[s + i]){
				printf("%d\n", i);
				break;
			}
			if(s - i > 0 && !mp[s - i]){
				printf("%d\n", i);
				break;
			}
		}
	}
}