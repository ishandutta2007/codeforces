#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, par[1005], ind[1005], lf[1005];

int main()
{
	cin >> n;
	for(int i=2;i<=n;i++) {
		scanf("%d",&par[i]);
		ind[par[i]]++;
	}
	for(int i=1;i<=n;i++) {
		if(ind[i] == 0) lf[par[i]]++;
	}
	for(int i=1;i<=n;i++) {
		if(ind[i] == 0 || lf[i] >= 3) continue;
		puts("No"); return 0;
	}
	puts("Yes");
}