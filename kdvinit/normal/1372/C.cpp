/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int a[n+1],strt,nd,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==i) cnt++;
    }

    if(cnt==n) { cout<<0<<endl; return; }

    for(strt=1;strt<=n;strt++) { if(a[strt]!=strt) break; }
    for(nd=n;nd>0;nd--) { if(a[nd]!=nd) break; }
    //cout<<strt<<" "<<nd<<endl;
    for(int i=strt;i<=nd;i++) { if(a[i]==i) {cout<<2<<endl; return; } }

    cout<<1<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}