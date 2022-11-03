#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 100002;

int main()
{
	int n,k;
	cin >> n >> k;
	int ans=k,a,b;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ans = max(ans,a+b);
	}
	cout << ans;
}