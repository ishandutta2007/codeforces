#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b,c;
    cin>>a>>b;
    int licz=0;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        while(c>0)
        {
            if(b>=x)
            {
                licz++;
                b-=x;
                c--;
            }
            else
                break;
        }
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