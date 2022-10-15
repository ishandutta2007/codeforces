#include <iostream>
using namespace std;

void solve()
{
    int n,m,k,c,d;
    cin>>n>>m>>k;
    c=n/k;
    if(c>=m) { cout<<m<<endl; return; }
    d=(m-c)/(k-1);
    if((m-c)%(k-1)!=0) d++;
    cout<<c-d<<endl;
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