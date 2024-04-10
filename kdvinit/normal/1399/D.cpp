/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int a[n+1],b[n+1]={0};
    for(int i=1;i<=n;i++) { char x; cin>>x; a[i]=x-48; }

    int nd1=0,nd0=0,cnt=0,a0[n+1],a1[n+1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            if(nd1==0) { a0[++nd0]=++cnt; b[i]=cnt; }
            else { a0[++nd0]=a1[nd1--]; b[i]=a0[nd0]; }
        }
        else
        {
            if(nd0==0) { a1[++nd1]=++cnt; b[i]=cnt; }
            else { a1[++nd1]=a0[nd0--]; b[i]=a1[nd1]; }
        }
    }

    cout<<cnt<<endl;
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}