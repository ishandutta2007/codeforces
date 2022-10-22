#include <bits/stdc++.h>
using namespace std;
long double pr[2][1002];
vector<long double> prr;
long double eps=1e-15;
int main()
{
    int k,q,i,j;
    scanf("%d%d",&k,&q);
    pr[0][0]=1;
    prr.push_back(0);
    for(i=1;1;i++){
        memset(pr[i&1],0,sizeof(pr[i&1]));
        for(j=0;j<=k;j++){
            pr[i&1][j]+=pr[i&1^1][j]*j/k;
            pr[i&1][j+1]+=pr[i&1^1][j]*(k-j)/k;
        }
        prr.push_back(pr[i&1][k]);
        if(pr[i&1][k]>0.5001)break;
    }
    while(q--){
        int p;
        scanf("%d",&p);
        int cur=0;
        for(i=1<<30;i;i>>=1){
            if(cur+i>=prr.size())continue;
            if(prr[cur+i]*2000+eps<p)cur+=i;
        }
        printf("%d\n",cur+1);
    }
}