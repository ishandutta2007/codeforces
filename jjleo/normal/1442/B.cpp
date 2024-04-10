#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int t;
int n, k;
int a[maxn], b[maxn], A[maxn];
bool tag[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), A[a[i]] = i;
		for(int i = 1;i <= k;i++) scanf("%d", &b[i]), tag[b[i]] = true;
		int ans = 1;
		for(int i = 1;i <= k;i++){
			int j = A[b[i]], x = 0;
			if(j > 1 && !tag[a[j - 1]]) x++;
			if(j < n && !tag[a[j + 1]]) x++;
			ans = ans * x % p;
			tag[b[i]] = false;
		}
		printf("%d\n", ans);
	}
}