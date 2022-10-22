#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

    string s;
    int a[4],n,u,r,l,d;
    bool ch()
    {
        int b[4];
         b[0]=a[0]+a[1];
         b[1]=a[1]+a[2];
         b[2]=a[2]+a[3];
         b[3]=a[3]+a[0];
         if(u<b[0]||u>b[0]+n-2)return false;
         if(r<b[1]||r>b[1]+n-2)return false;
         if(d<b[2]||d>b[2]+n-2)return false;
         if(l<b[3]||l>b[3]+n-2)return false;
return true;
    }
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>u>>r>>d>>l;
    bool ans=false;
    for( a[0]=0;a[0]<2;a[0]++)
    for( a[1]=0;a[1]<2;a[1]++)
    for( a[2]=0;a[2]<2;a[2]++)
    for(a[3]=0;a[3]<2;a[3]++)
    {
        if(ch()){ans=true;break;}
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}
    return 0;
}