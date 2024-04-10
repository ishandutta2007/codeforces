#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, m;
char s[maxn];
int a[maxn];
int A[maxn], B[maxn], C[maxn], D[maxn];
int l, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &m, s + 1);
		for(int i = 1;i <= n;i++) a[i] = a[i - 1] + (s[i] == '+' ? 1 : -1);
		A[0] = C[n + 1] = -1e9, B[0] = D[n + 1] = 1e9;
		for(int i = 1;i <= n;i++) A[i] = max(A[i - 1], a[i]), B[i] = min(B[i - 1], a[i]);
		for(int i = n;i;i--) C[i] = max(C[i + 1], a[i]), D[i] = min(D[i + 1], a[i]);
		while(m--){
			scanf("%d%d", &l, &r);
			printf("%d\n", max(0, max(A[l - 1], C[r + 1] - (a[r] - a[l - 1]))) - min(0, min(B[l - 1], D[r + 1] - (a[r] - a[l - 1]))) + 1);
		}
	}
}