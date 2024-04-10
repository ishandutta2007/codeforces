#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n;
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		v.clear();
		if(n & 1){
			puts("-1");
			continue;
		}
		while(n){
			for(int i = 63;~i;i--){
				if((1ll << i) - 2 <= n){
					v.push_back(1);
					for(int j = 1;j <= i - 2;j++) v.push_back(0);
					n -= (1ll << i) - 2;
					break;
				}
			}
		}
		printf("%d\n", v.size());
		for(int i = 0;i < v.size();i++) printf("%d ", v[i]);
		puts("");
	}
}