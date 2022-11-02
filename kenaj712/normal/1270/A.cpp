#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c;
    int maks1=-1e9-1,maks2=-1e9-1;
    for(int x=0;x<b;x++)
    {
        cin>>d;
        maks1=max(maks1,d);
    }
    for(int x=0;x<c;x++)
    {
        cin>>d;
        maks2=max(maks2,d);
    }
    if(maks1>maks2)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<'\n';
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