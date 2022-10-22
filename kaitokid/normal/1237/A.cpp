#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(0);
int n,u=0,x;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x;
    if(x%2==0){cout<<(x/2)<<endl;continue;}
    int r=ceil(x/2.0);
    if(u%2==1)cout<<r<<endl;
    else cout<<r-1<<endl;
    u++;
}
    return 0;
}