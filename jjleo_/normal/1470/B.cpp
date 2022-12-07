#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n;
int prm[maxn], cnt;
bool tag[maxn];
int a[maxn];
vector<int> v;
int x;
int q;

int main(){
	for(int i = 2;i <= 1000;i++){
		if(!tag[i]) prm[++cnt] = i;
		for(int j = 1;j <= cnt && prm[j] * i <= 1000;j++){
			tag[prm[j] * i] = true;
			if(i % prm[j] == 0) break;
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int ans1 = 0, ans2 = 0; 
		v.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			for(int j = 1;j <= cnt;j++){
				int y = 0;
				while(x % prm[j] == 0) y++, x /= prm[j];
				if(y & 1) x *= prm[j];
			}
			v.push_back(x);
			a[x]++;
			ans1 = max(ans1, a[x]);
		}
		for(int i = 0;i < v.size();i++){
			if(a[v[i]] % 2 == 0 || v[i] == 1) ans2 += a[v[i]];
			a[v[i]] = 0;
		}
		ans2 = max(ans2, ans1);
		scanf("%d", &q);
		while(q--){
			long long x;
			scanf("%lld", &x);
			printf("%d\n", x ? ans2 : ans1);
		}
	}
}