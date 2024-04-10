#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
int x;
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = i, vis[i] = false;
		int now = n + 1;
		bool tag = true;
		for(int i = 1;i <= n;i++){
			if(now > n || vis[now]) now = a[i];
			if(a[i] != now){
				tag = false;
				break;
			}
			vis[now++] = true;
		}
		puts(tag ? "Yes" : "No");
	}
}