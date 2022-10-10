#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        int now=1;
        for(k=0;now<=n;k++){
            int tl=a[now]-m,tr=a[now]+m;
            ++now;
            while(now<=n){
                int ul=max(tl,a[now]-m),ur=min(tr,a[now]+m);
                //cerr<<"now="<<now<<' '<<tl<<' '<<tr<<' '<<ul<<' '<<ur<<endl;
                if(ul<=ur){
                    tl=ul;tr=ur;
                    ++now;
                }else break;
            }//cerr<<"now="<<now<<endl;
        }printf("%d\n",k-1);
    }
}