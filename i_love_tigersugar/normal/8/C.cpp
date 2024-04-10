#include<bits/stdc++.h>
#define MAX   24
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> point;
const int INF=(int)1e9;
int f[(1<<MAX)+7];
int t[(1<<MAX)+7];
int tohb[MAX+7];
int dis[MAX+7][MAX+7];
point hb;
point a[MAX+7];
int n;
vector<int> res;
int distan(const point &a,const point &b) {
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init(void) {
    scanf("%d",&hb.x);
    scanf("%d",&hb.y);
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i=i+1) {
        scanf("%d",&a[i].x);
        scanf("%d",&a[i].y);
    }
}
void precount(void) {
    int i,j;
    for (i=0;i<n;i=i+1) {
        tohb[i]=distan(hb,a[i]);
        for (j=0;j<n;j=j+1) dis[i][j]=distan(a[i],a[j]);
    }
}
void optimize(void) {
    int i,j,k;
    for (i=0;i<(1<<n);i=i+1) f[i]=INF;
    f[0]=0;
    for (i=0;i<(1<<n);i=i+1)
        if (f[i]<INF)
            for (j=0;j<n;j=j+1)
                if ((i|(1<<j))!=i) {
                    if (f[i]+2*tohb[j]<f[i|(1<<j)]) {
                        f[i|(1<<j)]=f[i]+2*tohb[j];
                        t[i|(1<<j)]=-j-n;
                    }
                    for (k=0;k<n;k=k+1)
                        if ((i|(1<<k))!=i && k!=j) {
                            if (f[i]+tohb[j]+tohb[k]+dis[j][k]<f[(i|(1<<j))|(1<<k)]) {
                                f[(i|(1<<j))|(1<<k)]=f[i]+tohb[j]+tohb[k]+dis[j][k];
                                t[(i|(1<<j))|(1<<k)]=j*n+k;
                            }
                        }
                    break;
                }
}
void trace(void) {
    int cur,u,v;
    res.clear();
    res.push_back(-1);
    cur=(1<<n)-1;
    printf("%d\n",f[cur]);
    while (cur>0) {
        if (t[cur]<0) {
            v=-t[cur]-n;
            res.push_back(v);
            cur=cur-(1<<v);
            res.push_back(-1);
        }
        else {
            u=t[cur]%n;
            v=t[cur]/n;
            res.push_back(u);
            res.push_back(v);
            cur=cur-(1<<u)-(1<<v);
            res.push_back(-1);
        }
    }   
    int i;  
    for (i=(int)res.size()-1;i>=0;i=i-1) printf("%d ",res[i]+1);
}
int main(void) {
    init();
    precount();
    optimize();
    trace();
    return 0;
}