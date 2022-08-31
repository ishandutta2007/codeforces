#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	int l[4];
	l[0] = a+b;
	l[1] = b+d;
	l[2] = c+d;
	l[3] = a+c;
	sort(l,l+4);
	int diff = l[3]-l[0];
	ll res = max(0LL,(n - diff)*1ll*n);
	cout<<res<<endl;
	return 0; 
}