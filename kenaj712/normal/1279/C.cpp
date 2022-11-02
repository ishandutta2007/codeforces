#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int gdzie[1000005];
bool odw[1000005];
void solve()
{
    int a,b,c;
    cin>>a>>b;
    int licz=0;
    long long suma=0;
    int maks=0;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        gdzie[tab[x]]=x;
    }

    for(int x=1;x<=b;x++)
    {
        cin>>c;
        if(maks>=gdzie[c])
        {
           suma++;
           licz++;
        }
        else
        {
            suma+=(2*(gdzie[c]-licz)-1);
            maks=max(maks,gdzie[c]);
            licz++;
        }
    }
    cout<<suma<<'\n';

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}