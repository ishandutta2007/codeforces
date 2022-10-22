#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[200009],r[200009];
int main()
{
int t;
cin>>t;
while(t--)
{
    int n,x,y,z;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)l[i]=r[i]=0;
    for(int i=0;i<x;i++){cin>>z;l[z]++;}
    for(int i=0;i<y;i++){cin>>z;r[z]++;}
    int u=0,v=0,d1=0,d2=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(l[i]>r[i]){u+=l[i]-r[i];
        d1+=(l[i]-r[i])/2;}

        if(l[i]<r[i]){v+=r[i]-l[i];
        d2+=(r[i]-l[i])/2;}
    }
    if(u<v){swap(u,v);swap(d1,d2);}
    ans=v;

            u-=v;
            u/=2;
            int r=min(u,d1);
            ans+=r;
            ans+=(2*(u-r));
            cout<<ans<<endl;


}


    return 0;
}