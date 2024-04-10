#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

map<ll, int> mp;

int t, n;
int vis[maxn];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		//mp.clear();
		bool suc = true;
		for(int i = 0;i < n;i++) vis[i] = 0;
		for(int i = 0;i < n;i++){
			scanf("%d", &x), vis[((i + x) % n + n) % n]++;
			if(vis[((i + x) % n + n) % n] > 1) suc = false;
		}
		puts(suc ? "YES" : "NO");
	}
}