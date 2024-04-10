/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    string a;
    cin>>a;

    int n=a.size();
    int b[n+1],cnt=0,pos=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='1')
        {
            cnt++;
        }
        else
        {
            if(cnt==0) continue;
            else b[++pos]=cnt;
            cnt=0;
        }
    }
    if(cnt!=0) b[++pos]=cnt;

    if(pos==0) { cout<<0<<endl; return; }

    long long int ans=0;
    sort(b+1,b+pos+1);
    for(int i=0;i<pos;i+=2)
    {
        ans+=b[pos-i];
    }

    cout<<ans<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}