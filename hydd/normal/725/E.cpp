#include<bits/stdc++.h>
using namespace std;
int c,n,tot[210000],pre[210000];
int main(){
    scanf("%d%d",&c,&n); int w;
    for (int i=1;i<=n;i++){
        scanf("%d",&w);
        tot[w]++;
    }
    pre[0]=0;
    for (int i=1;i<=c;i++) pre[i]=(tot[i]?i:pre[i-1]);
    for (int ans=1;ans<=c;ans++){
        int v=c,now=pre[c]; bool used=false;
        while (now){
            if (ans>=now&&!used){
                used=true;
                if (v>=ans) v-=ans;
                now=pre[min(now,v)];
            } else{
                int tmp=min(tot[now],v/now);
                v-=tmp*now; now=pre[min(now-1,v)];
            }
        }
        if (!v) continue;
        printf("%d\n",ans); return 0;
    }
    puts("Greed is good");
    return 0;
}