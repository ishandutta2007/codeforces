#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
int c[mn];
ll v[mn];
ll bec[mn];
int col;
ll bes,bes2;

int main()
{
    int n,q,i,j;
    cin>>n>>q;
    for(i=0;i<n;i++)cin>>v[i];
    for(i=0;i<n;i++)cin>>c[i];
    memset(bec,0xc0,sizeof(bec));
    bes=0;
    bes2=0xc0c0c0c0c0c0c0c0;
    while(q--){
        ll a,b;
        cin>>a>>b;
        for(i=0;i<n;i++){
            ll num=bec[c[i]]+a*v[i];
            if(c[i]!=col)num=max(num,bes+b*v[i]);
            else num=max(num,bes2+b*v[i]);
            bec[c[i]]=max(bec[c[i]],num);
            if(c[i]==col){
                bes=max(bes,num);
            }
            else{
                if(num>bes){
                    bes2=bes;
                    col=c[i];
                    bes=num;
                }
                else if(num>bes2){
                    bes2=num;
                }
            }
        }
        printf("%lld\n",bes);
        bes=0;
        bes2=0xc0c0c0c0c0c0c0c0;
        col=0;
        memset(bec,0xc0,sizeof(bec));
    }
}