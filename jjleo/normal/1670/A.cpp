#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

bool solve(){
	scanf("%d", &n);
	int sum = 0;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i] < 0, a[i] = abs(a[i]);
	for(int i = 1;i < sum;i++) if(a[i] < a[i + 1]) return false;
	for(int i = sum + 1;i < n;i++) if(a[i] > a[i + 1]) return false;
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
}