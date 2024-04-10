#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=300000;
int n;
int val[MAXN];
ll mask[MAXN];
ll s,tot;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%I64d",&val[i],&mask[i]);
    for(int i=0;i<n;++i)
        tot+=val[i];
    for(int i=0;i<62;++i){
        ll sum=0;
        for(int j=0;j<n;++j)
            if((mask[j]>>i)==1)
                sum+=val[j];
        if(1.0*sum*tot>0){
            for(int j=0;j<n;++j)
                if((mask[j]&(1ll<<i))>0)
                    val[j]=-val[j];
            s|=1ll<<i;
        }
    }
    tot=0;
    for(int i=0;i<n;++i)
        tot+=val[i];
    printf("%I64d\n",s);
    return 0;
}