#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn];
int mn;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mn = 1e9;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), mn = min(a[i], mn), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(a[i] % mn && b[i] != a[i]){
				tag = true;
				break;
			}
		}
		puts(tag ? "NO" : "YES");
	}
}