#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    tab[a+1] = 0;
    long long licz = 0;
    for(int x=1;x<=a;x++)
        if(tab[x] > tab[x-1] && tab[x] > tab[x+1])
        {
            int pom = max(tab[x-1] , tab[x+1]);
            licz += tab[x] - pom;
            tab[x] = pom;
        }
    licz += tab[0];
    for(int x=1;x<=a;x++)
    {
        if(tab[x] > tab[x-1])
            licz += (tab[x] - tab[x-1])*2;
    }
    cout<<licz<<'\n';
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