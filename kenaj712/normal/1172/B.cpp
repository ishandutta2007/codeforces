#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
const int mod=998244353;
long long silnia(int a)
{
    long long pom=1;
    for(int x=1;x<=a;x++)
        pom=(pom*x)%mod;
    return pom;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int c,d;
    for(int x=1;x<a;x++)
    {
        cin>>c>>d;
        tab[c]++;
        tab[d]++;
    }
    long long mnoz=a;
    for(int x=1;x<=a;x++)
        mnoz=(mnoz*silnia(tab[x]))%mod;
    cout<<mnoz;
	return 0;
}