#include<bits/stdc++.h>
using namespace std;
long long dwa=2;
void solve()
{
    long long a,b,maks=0;
    cin>>a>>b;
    bool czy=false;
    long long c;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        if(c==b)
            czy=true;
        maks=max(maks,c);
    }
    long long pom=b/maks;
    if(b%maks!=0)
        pom++;
    pom=max(pom,dwa);
    if(czy)
        pom=1;
    cout<<pom<<'\n';
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