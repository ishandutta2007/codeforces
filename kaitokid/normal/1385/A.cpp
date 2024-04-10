#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int t,x,y,z;
cin>>t;
while(t--)
{
    cin>>x>>y>>z;
    if(x==y&&x>=z){cout<<"YES\n";cout<<x<<" "<<z<<" "<<z<<endl;continue;}
    if(x==z&&x>=y){cout<<"YES\n";cout<<y<<" "<<x<<" "<<y<<endl;continue;}
    if(y==z&&y>=x){cout<<"YES\n";cout<<x<<" "<<x<<" "<<y<<endl;continue;}
cout<<"NO\n";

}
    return 0;
}