#include<bits/stdc++.h>
using namespace std;
bool odw[1000005];
void solve()
{
    int a,b;
    cin>>a>>b;
    while(b--)
    {
        int c,d,e;
        cin>>c>>d>>e;
        odw[d] = true;
    }
    for(int x=1;x<=a;x++)
        if(!odw[x])
        {
            for(int y=1;y<=a;y++)
                if(x != y)
                    cout<<x<<" "<<y<<'\n';
            break;
        }
    for(int x=1;x<=a;x++)
        odw[x] = false;
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