#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n;
char s[maxn];
vector<int> v[maxn];
int a[maxn];

int main(){
	for(int i = 1;i < maxn;i++) for(int j = i;j < maxn;j += i) v[j].push_back(i);
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n;i++) a[i] = 0;
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '1'){
				for(auto x : v[i]) a[x] = 1;
			}else{
				for(auto x : v[i]) if(!a[x]){
					ans += x;
					break;
				}
			}
		}
		printf("%lld\n", ans);
	}
}