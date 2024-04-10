#include<bits/stdc++.h>
using namespace std;
int tab[15];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int t = 1;
    for(int x=0;x<a;x++)
        t*=3;
    for(int x=1;x<t;x++)
    {
        int sum = 0;
        int xd = x;
        for(int y=0;y<a;y++)
        {
            int pom = xd % 3;
            xd /= 3;
            if(pom == 1)
                sum += tab[y];
            else if(pom == 2)
                sum -= tab[y];
        }
        if(sum == 0)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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