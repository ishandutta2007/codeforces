#include <iostream>
using namespace std;
int n,m,i,j;
long long int a[201], ab[201][201], ans=0, b;
bool check(long long int x)
{
    for(i=1;i<=n;i++) { for(j=1;j<=m;j++) if((x|ab[i][j])==x) break; if(j>m) return false; }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    for(j=1;j<=m;j++) { cin>>b; for(int i=1;i<=n;i++) ab[i][j]=(a[i] & b); }
    while(1) { if(check(ans)) break; ans++; }
    cout<<ans<<endl;
	return 0;
}