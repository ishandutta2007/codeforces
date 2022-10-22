#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
long long pom[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,m,gcd,q,a,b,x,y,i;
	cin>>n>>m>>q;
	gcd=__gcd(n,m);
	n/=gcd;
	m/=gcd;
	pom[1]=n;
	pom[2]=m;
	for(i=1;i<=q;i++)
	{
		cin>>x>>a>>y>>b;
		a--;
		b--;
		if((a/pom[x])==(b/pom[y]))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}