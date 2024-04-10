#include<bits/stdc++.h>
using namespace std;
bool odw[1000005];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        int c;
        cin>>c;
        int b=x+c;
        b%=a;
        if(b<0)
            b+=a;
        odw[b]=true;
    }
    bool czy=true;
    for(int x=0;x<a;x++)
        if(odw[x]==false)
            czy=false;
    if(czy)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<'\n';
    for(int x=0;x<a;x++)
        odw[x]=false;
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