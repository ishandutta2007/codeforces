#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

char s[MAXN];
int a[MAXN];
int cnt[MAXN], f[MAXN];

int main(){
	int n, T;
	cin>>n>>T;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		sum = max(sum ,cnt[a[i]]);
	}
	for(int j = n + 1; j <= n * n; j++)
		a[j] = a[j - n];
	for(int i = 0; i <= 301; i++)
		f[i] = 0;
	int ans = 0;
	for(int i = 1; i <= min(n, T) * n; i++){
		int k = 0;
		for(int j = 0; j <= a[i]; j++)
			if (f[j] > f[k])
				k = j;
		f[a[i]] = f[k] + 1;
		ans = max(f[a[i]], ans);
	}
	//cout<<ans<<endl;
	cout<<ans + sum * (T - min(n, T))<<endl;
	return 0;
}