#include<cstdio>
#include<vector>
using namespace std;
int n,k,tmp,bup,t;
int where[100005],idx[100005];

struct Chain{
    int cnt,top;
    vector<int>v;
}chain[100005];

int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++) {
        scanf("%d",&chain[i].cnt);
        chain[i].top=chain[i].cnt-1;
        for(j=0;j<chain[i].cnt;j++) {
            scanf("%d",&tmp);
            where[tmp]=i;
            idx[tmp]=j;
            chain[i].v.push_back(tmp);
        }
    }
    bup=chain[where[1]].top;
    for(i=0;i<chain[where[1]].cnt;i++) {
        if(chain[where[1]].v[i]==i+1) {
            j=i+2;
            chain[where[1]].top=i;
        }
    }
    t+=bup-chain[where[1]].top;
    for(i=j;i<=n;i++) {
        if(chain[where[i]].top>idx[i]) {
            t+=chain[where[i]].top-idx[i]+1;
            chain[where[i]].top=idx[i]-1;
        }
        else t++;
    }
    printf("%d",t);
}