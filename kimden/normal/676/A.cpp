#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,p1,pn,ans;
	int a[1000];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==1){
			p1 = i;
		}
		if(a[i]==n){
			pn = i;
		}
	}
	ans = 0;
	ans = max(ans,p1);
	ans = max(ans,pn);
	ans = max(ans,n-1-p1);
	ans = max(ans,n-1-pn);
	cout << ans;
	return 0;
}