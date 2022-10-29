#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

char s[MAXN];
int a[MAXN], b[MAXN];
int ans[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		a[i] = 0, b[i] = 0;
	int cnt = 0;
	for(int i = 1; i <= n * n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if (!a[x] && !b[y]){
			ans[++cnt] = i;
			a[x] = b[y] = 1;
		}
	}
	for(int i = 1; i <= cnt; i++)
		printf("%d%c", ans[i], " \n"[i == cnt]);
	return 0;
}