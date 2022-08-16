#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 105;

int x[N];
int f[N];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i], f[x[i]]++;
	sort(x + 1, x + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(ans * x[i] + ans < i) ans++;
	}
	printf("%d\n", ans);
}