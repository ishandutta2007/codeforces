#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		v.clear();
		for(int i = 1;i <= n;i++) if(!(a[i] & 1)) v.push_back(a[i]);
		for(int i = 1;i <= n;i++) if(a[i] & 1) v.push_back(a[i]);
		int ans = 0;
		for(int i = 0;i < v.size();i++){
			for(int j = i + 1;j < v.size();j++){
				ans += __gcd(v[i], 2 * v[j]) > 1;
			}
		}
		printf("%d\n", ans);
	}
}