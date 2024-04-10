#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long jeden[100010];
long long pot[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,q,l,r,i;
	string s;
	cin>>n>>q;
	cin>>s;
	for(i=0;i<n;i++)
	{
		jeden[i+1]=jeden[i];
		if(s[i]=='1')
			jeden[i+1]++;
	}
	pot[0]=1;
	for(i=1;i<=n;i++)
		pot[i]=(2*pot[i-1])%mod;
	for(i=1;i<=q;i++)
	{
		cin>>l>>r;
		cout<<(((pot[r-l+1-jeden[r]+jeden[l-1]]*(pot[jeden[r]-jeden[l-1]]-1))%mod)+mod)%mod<<"\n";
	}
	return 0;
}