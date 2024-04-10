#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,cnt[201][100005],k[100005],q[100005],er[100005];
int maxl,ans=INF,cur,tmp,cans;
struct Leg{
    int l,p;
}leg[100005];

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&leg[i].l);
        maxl=max(maxl,leg[i].l);
    }
    for(i=0;i<n;i++) {
        scanf("%d",&leg[i].p);
        cnt[leg[i].p][leg[i].l]++;
    }
    for(i=1;i<=200;i++) {
        for(j=1;j<=maxl;j++) {
            cnt[i][j]+=cnt[i][j-1];
        }
    }
    for(i=0;i<n;i++) {
        k[leg[i].l]++;
        q[leg[i].l]+=leg[i].p;
    }
    for(i=maxl;i>=1;i--) {
        er[i]=er[i+1]+q[i];
    }
    for(i=1;i<=maxl;i++) {
        cur+=k[i];
        tmp=cur-(k[i]*2-1);
        for(j=1;j<=200;j++) {
            if(tmp<=0){break;}
            cans+=min(tmp,cnt[j][i-1])*j;
            tmp-=min(tmp,cnt[j][i-1]);
        }
        if(tmp<=0)ans=min(ans,cans+er[i+1]);
        cans=0;
    }
    printf("%d",ans);
}