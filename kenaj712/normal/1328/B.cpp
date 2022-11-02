#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
    {
        if(b-x<=0)
        {
            for(int y=1;y<=a;y++)
            {
                if(y==a-x || y==a-x+(x-b+1))
                    cout<<'b';
                else
                    cout<<'a';
            }
            cout<<'\n';
            return;
        }
        b-=x;
    }
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