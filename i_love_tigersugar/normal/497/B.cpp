#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
int a[MAX],cntWin[MAX],cntLose[MAX];
vector<int> posWin,posLose;
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&a[i]);
        cntWin[i]=cntWin[i-1]+(a[i]==1);
        cntLose[i]=cntLose[i-1]+(a[i]==2);
        if (a[i]==1) posWin.push_back(i); else posLose.push_back(i);
    }
}
int findPos(const vector<int> &v,int x) {
    return (x>v.size()?n+1:v[x-1]);
}
int findWinner(int pos,int req) {
    int prevWin=cntWin[pos-1];
    int prevLose=cntLose[pos-1];
    int nextWin=findPos(posWin,req+prevWin);
    int nextLose=findPos(posLose,req+prevLose);
    if (nextWin>n && nextLose>n) return (-1);
    return (min(nextWin,nextLose));
}
int ok(int t) {
    int pos=1;
    int pointWin=0;
    int pointLose=0;
    bool lastWin;
    while (pos<=n) {
        int tmp=findWinner(pos,t);
        if (tmp<0) return (-1);
        bool winner=(a[tmp]==1);
        if (winner) pointWin++; else pointLose++;
        lastWin=winner;
        pos=tmp+1;
    }
    if (lastWin) return (pointWin>pointLose?pointWin:-1);
    else return (pointLose>pointWin?pointLose:-1);
}
void process(void) {
    vector<pair<int,int> > res;
    FOR(t,1,n) {
        int s=ok(t);
        if (s>0) res.push_back(make_pair(s,t));
    }
    sort(res.begin(),res.end());
    res.resize(unique(res.begin(),res.end())-res.begin());
    printf("%d\n",(int)res.size());
    REP(i,res.size()) printf("%d %d\n",res[i].fi,res[i].se);
}
int main(void) {
    init();
    process();
    return 0;
}