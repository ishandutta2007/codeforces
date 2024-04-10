#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll; 

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n;
int f[maxn];
int p[maxn], mu[maxn], cnt, tag[maxn];
int g[maxn], ans;
vector<int> d[maxn];

int main(){
	n = read();
	while(n--) f[read()] = 1;
	n = 1e6;
	for(int i = 1;i <= n;i++) for(int j = i;j <= n;j += i) d[j].push_back(i);
	mu[1] = 1;
	for(int i = 2;i <= n;i++){
		if(!tag[i]) p[++cnt] = i, mu[i] = -1;
		for(int j = 1;j <= cnt && p[j] * i <= n;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0){
				mu[p[j] * i] = 0;
				break;
			}
			mu[p[j] * i] = -mu[i];
		}
	}
	for(int i = n;i;i--){
		if(f[i]){
			for(auto j : d[i]) g[j]++;
			continue;
		}
		vector<int> v;
		ll sum = 0;
		for(int j = i;j <= n;j += i) sum += 1ll * mu[j / i] * g[j] * (g[j] - 1) / 2;
		if(sum){
			ans++, f[i] = 1;
			for(auto j : d[i]) g[j]++;
			//printf("%d--\n", i);
		}
	}
	printf("%d", ans);
}