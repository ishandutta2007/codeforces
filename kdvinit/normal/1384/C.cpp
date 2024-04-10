/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n,ans=0;
    cin>>n;

    char a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    for(int i=1;i<=n;i++)
        if(a[i]>b[i]) { cout<<-1<<endl; return; }

    for(char x='a';x<='t';x++)
    {
        char y='z';
        for(int i=1;i<=n;i++)
            if(a[i]==x && b[i]!=x) y=min(y,b[i]);

        if(y=='z') continue;
        ans++;
        for(int i=1;i<=n;i++)
            if(a[i]==x && b[i]!=x) a[i]=y;
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