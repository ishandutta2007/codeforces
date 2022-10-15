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

    int a[2*n+1],b[2*n+1],c[n+1]={0},cntr=0;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    int mx=a[1],mi=1;

    for(int i=2;i<=2*n;i++) if(a[i]>mx) { b[++cntr]=i-mi; mx=a[i]; mi=i; }
    b[++cntr]=2*n+1-mi;
    sort(b+1,b+cntr+1);

    c[0]=1;
    for(int i=1;i<=cntr;i++) { if(c[i]>=n) break; for(int j=n;j>0;j--) if(j>=b[i] && c[j]==0 && c[j-b[i]]==1 ) c[j]=1; }

    if(c[n]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}