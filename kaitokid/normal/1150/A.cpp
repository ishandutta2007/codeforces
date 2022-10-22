#include <iostream>

using namespace std;

int n,m,r,mn=30000,mx=-1000;
int main()
{
    cin>>n>>m>>r;
    int x;
    for(int i=0;i<n;i++){cin>>x;mn=min(x,mn);}
    for(int i=0;i<m;i++){cin>>x; mx=max(mx,x);}
    if(mx<=mn){cout<<r;return 0;}
    int ans =r%mn+((r/mn)*mx);
    cout<<ans;
    return 0;
}