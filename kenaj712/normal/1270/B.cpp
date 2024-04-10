#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a,b;
    cin>>a;
    int last;
    cin>>last;
    bool czy=false;
    for(int x=1;x<a;x++)
    {
        cin>>b;
        if(abs(last-b)>1 && czy==false)
        {
            cout<<"YES"<<'\n'<<x<<" "<<x+1<<'\n';
            czy=true;
        }
        last=b;
    }
    if(!czy)
        cout<<"NO"<<'\n';

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