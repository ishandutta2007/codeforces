#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long wynik=1;
int tab[1000005];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    long long pom=0;
    for(int x=a-b+1;x<=a;x++)
        pom+=x;
    cout<<pom<<" ";
    bool czy=false;
    int licz=1;
    for(int x=0;x<a;x++)
    {
        if(tab[x]>a-b)
        {
            if(czy==true)
            {
                wynik=(wynik*licz)%mod;
                licz=1;
            }

            else
            {
                licz=1;
                czy=true;
            }
        }
        else
            licz++;
    }
    cout<<wynik;
	return 0;
}