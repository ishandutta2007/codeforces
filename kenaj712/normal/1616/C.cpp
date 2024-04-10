#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
map<pair<int,int> , int> m;
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    int maks = 0;
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<=a;y++)
        {
            if(y != x)
            {
                int c = tab[x] - tab[y], d = x - y;
                int pom = __gcd(c,d);
                c/=pom;
                d/=pom;
                m[{c,d}]++;
            }
        }
        for(auto x:m)
            maks = max(maks,x.second);
        m.clear();
    }
    cout<<a-maks-1<<'\n';
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