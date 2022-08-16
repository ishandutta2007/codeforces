#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";

const int N = 2e5 + 10;
int a[N];
int main(){
	int n; sd(n);
	int cnt = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if(a[i] == 0) ans += cnt;
		else cnt++;
	}
	printf("%lld", ans);
}