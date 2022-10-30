#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int MOD=998244353;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    long long licz=tab[a-1];
    long long pom1=3,pom2=1;
    for(int x=a-2;x>=0;x--)
    {
        //cout<<pom1<<" "<<pom2<<'\n';
        long long pom=pom1*pom2;
        pom%=MOD;
        licz+=tab[x]*pom;
        licz%=MOD;
        pom2=(pom2*2)%MOD;
        pom1+=1;
    }
    cout<<licz;

	return 0;
}