#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    ll n,m,a,b;
    cin>>a>>b>>n>>m;
    if(n+m>a+b){cout<<"NO\n";continue;}
    if(a>b)swap(a,b);
    if(a<m){cout<<"NO\n";continue;}
    cout<<"YES\n";


}
return 0;
}