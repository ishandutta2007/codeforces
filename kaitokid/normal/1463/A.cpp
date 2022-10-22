#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
ll t,a,b,c;
cin>>t;
while(t--)
{
cin>>a>>b>>c;
ll p=a+b+c;
if(p%9){cout<<"NO\n";continue;}
p/=9;
if(a<p||b<p||c<p){cout<<"NO\n";continue;}
cout<<"YES\n";


}

    return 0;
}