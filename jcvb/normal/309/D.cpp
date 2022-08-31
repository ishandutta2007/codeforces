#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int n,m;
int L;
int main()
{
    scanf("%d%d",&n,&m);L=n+1;
    ll ans=0;
    for (int a=m+1;a<<1<=L;a++){
        int lef=m+1,rig=min((a<<1)-1,n-m),mid;
        while(lef<=rig){
                        mid=lef+rig>>1;
                        ll t=L-(1ll*(L-a)*(-mid+2*a)-1)/(mid+a);
                        if(t<=m+1)lef=mid+1;
                        else rig=mid-1;
        }
        ll tmp=0;
        tmp+=(n-2*m)*(lef-m-1ll);
        int ri=min(2*a-1,n-m);
         for (int b=lef,t=L-(1ll*(L-a)*(-lef+(a<<1))-1)/(lef+a),bo=(L-a)*((a<<1)-b);b<=ri;b++,bo-=L-a){
             while(t<=n-m && (L-t)*(a+b)>=bo)t++;
            if(t<=n-m){
                      tmp+=(n-m-t+1);                     
            }else break;
        }
        ans+=(a*2==L?1:2)*tmp;
    }
    cout<<ans*3<<endl;
    return 0;
}