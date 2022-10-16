//This code is based on cgy4ever's solution
#include<bits/stdc++.h>
#define MAX   2020
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)5e6+7;
const char no[]="Poor Sereja!";
typedef pair<int,int> ii;
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
struct line {
    int x1,y1,x2,y2;
    line() {
        x1=0;y1=0;x2=0;y2=0;
    }
    line(const ii &p,int d,bool t) {
        if (t) {
            x1=p.fi;
            x2=p.fi;
            y1=p.se-2*d;
            y2=p.se+2*d;
        }
        else {
            y1=p.se;
            y2=p.se;
            x1=p.fi-2*d;
            x2=p.fi+2*d;
        }
    }
    bool intersect(const line &a) const {
        if (a.x2<x1) return (false);
        if (a.x1>x2) return (false);
        if (a.y2<y1) return (false);
        if (a.y1>y2) return (false);
        return (true);
    }
    void join(const line &a) {
        minimize(x1,a.x1);
        maximize(x2,a.x2);
        minimize(y1,a.y1);
        maximize(y2,a.y2);
    }
};
line lred[MAX],lblue[MAX];
ii pred[MAX],pblue[MAX];
bool same[MAX][MAX];
int nred,nblue;
bool cmpx(const line &a,const line &b) {
    if (a.x1<b.x1) return (true);
    if (a.x1>b.x1) return (false);
    return (a.y1<b.y1);
}
bool cmpy(const line &a,const line &b) {
    if (a.y1<b.y1) return (true);
    if (a.y1>b.y1) return (false);
    return (a.x1<b.x1);
}
void init(void) {
    scanf("%d",&nblue);
    scanf("%d",&nred);
    FOR(i,1,nblue) {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        pblue[i]=ii(x+y,x-y);
    }
    FOR(i,1,nred) {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        pred[i]=ii(x+y,x-y);
    }
}
bool ok(int d) {
    FOR(i,1,nblue) lblue[i]=line(pblue[i],d,1);
    FOR(i,1,nred) lred[i]=line(pred[i],d,0);
    memset(same,false,sizeof same);
    sort(lblue+1,lblue+nblue+1,cmpx);
    sort(lred+1,lred+nred+1,cmpy);
    vector<line> ablue,ared;
    FOR(i,1,nblue) {
        if (ablue.empty() || !ablue[ablue.size()-1].intersect(lblue[i])) ablue.push_back(lblue[i]);
        else ablue[ablue.size()-1].join(lblue[i]);
    }
    FOR(i,1,nred) {
        if (ared.empty() || !ared[ared.size()-1].intersect(lred[i])) ared.push_back(lred[i]);
        else ared[ared.size()-1].join(lred[i]);
    }
    REP(i,ablue.size()) {
        vector<int> interid;
        REP(j,ared.size()) if (ablue[i].intersect(ared[j])) interid.push_back(j);
        REP(j,interid.size()) FOR(k,j+1,interid.size()-1) {
            int x=interid[j];
            int y=interid[k];
            if (same[x][y]) return (true);
            same[x][y]=true;
            same[y][x]=true;
        }
    }
    return (false);
}
void process(void) {
    int l=0;
    int r=INF;
    if (!ok(INF)) {
        printf("%s",no);
        return;
    }
    while (true) {
        if (l==r) {
            printf("%d",r);
            return;
        }
        if (r-l==1) {
            if (ok(l)) printf("%d",l);
            else printf("%d",r);
            return;
        }
        int m=(l+r)>>1;
        if (ok(m)) r=m; else l=m+1;
    }
}
int main(void) {
    init();
    process();
    return 0;
}