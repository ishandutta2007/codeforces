/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int r,g,b,w,y,cnt=0;
    cin>>r>>g>>b>>w;

    y=min(r,g);
    y=min(y,b);

    r-=y;
    g-=y;
    b-=y;
    w+=3*y;

    if(r%2==1) cnt++;
    if(g%2==1) cnt++;
    if(b%2==1) cnt++;
    if(w%2==1) cnt++;

    if(y==0)
    {
        if(cnt==1 || cnt==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }
    else
    {
        if(cnt!=2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}