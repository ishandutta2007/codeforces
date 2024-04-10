#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAX   888
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
const double eps=1e-9;
const double INF=1e9+7;
double c[MAX][MAX];
double fx[MAX],fy[MAX],d[MAX];
int matx[MAX],maty[MAX],t[MAX],argu[MAX];
ii a[MAX];
int n,k,sta,fin;
queue<int> q;
double dis(const ii &a,const ii &b) {
    return (hypot(a.fi-b.fi,a.se-b.se));
}
double Fabs(const double &x) {
    if (x<0) return (-x); else return (x);
}
void minimize(double &x,const double &y) {
    if (x>y+eps) x=y;
}
void readinp(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&a[i].fi);
        scanf("%d",&a[i].se);
    }
}
void loadgraph(void) {
    k=2*n;
    FOR(i,1,k) FOR(j,1,k) c[i][j]=INF;
    FOR(i,1,n) FOR(j,1,n) if (a[i].se>a[j].se) {
        c[i][j]=dis(a[i],a[j]);
        c[n+i][j]=dis(a[i],a[j]);
    }
    FOR(i,1,k) {
        fx[i]=INF;
        FOR(j,1,k) minimize(fx[i],c[i][j]);
    }
    FOR(j,1,k) {
        fy[j]=INF;
        FOR(i,1,k) minimize(fy[j],c[i][j]-fx[i]);
    }
}
double cost(int x,int y) {
    return (c[x][y]-fx[x]-fy[y]);
}
void initBFS(void) {
    while (!q.empty()) q.pop();
    q.push(sta);
    memset(t,0,sizeof t);
    FOR(i,1,k) {
        d[i]=cost(sta,i);
        argu[i]=sta;
    }
    fin=0;
}
void findway(void) {
    while (!q.empty()) {
        int i=q.front();q.pop();
        FOR(j,1,k) if (t[j]==0) {
            double w=cost(i,j);
            if (Fabs(w)<=eps) {
                t[j]=i;
                if (maty[j]==0) {
                    fin=j;
                    return;
                }
                else q.push(maty[j]);
            }
            if (d[j]>w+eps) {
                d[j]=w;
                argu[j]=i;
            }
        }
    }
}
void subxaddy(void) {
    double del=INF;
    FOR(j,1,k) if (t[j]==0) minimize(del,d[j]);
    fx[sta]+=del;
    FOR(j,1,k) {
        if (t[j]!=0) {
            int i=maty[j];
            fy[j]-=del;
            fx[i]+=del;
        }
        else d[j]-=del;
    }
    FOR(j,1,k) if (t[j]==0 && Fabs(d[j])<=eps) {
        t[j]=argu[j];
        if (maty[j]==0) {
            fin=j;
            return;
        }
        else q.push(maty[j]);
    }
}
void enlarge(void) {
    int cur,next;
    cur=fin;
    do {
        next=matx[t[cur]];
        maty[cur]=t[cur];
        matx[t[cur]]=cur;
        cur=next;
    }
    while (cur>0);
}
void maxmatching(void) {
    FOR(i,1,k) {
        sta=i;
        initBFS();
        do {
            findway();
            if (fin==0) subxaddy();
        }
        while (fin==0);
        enlarge();
    }
    double res=0.0;
    int cnt=0;
    FOR(i,1,k) if (c[i][matx[i]]+eps<INF) {
        res+=c[i][matx[i]];
        cnt++;
    }
    if (cnt==n-1) printf("%.9lf",res);
    else printf("-1");
}
int main(void) {
    readinp();
    loadgraph();
    maxmatching();
    return 0;
}