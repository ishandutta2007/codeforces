#include<bits/stdc++.h>
#define MAX   3000300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
int mod,sta[2],goal[2],mul[2],add[2],fst[2],cyc[2];
int dist[MAX];
void init(void) {
    cin>>mod;
    REP(i,2) cin>>sta[i]>>goal[i]>>mul[i]>>add[i];
}
vector<int> haveGoal(int id) {
    int cur=sta[id];
    vector<int> res;
    FOR(i,1,MAX) {
        cur=(1LL*cur*mul[id]+add[id])%mod;
        if (cur==goal[id] && res.size()<2) res.push_back(i);
    }
    return (res);
}
void answer(long long x) {
    cout<<x<<endl;
    exit(0);
}
long long gcd(long long a,long long b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
long long lcm(long long a,long long b) {
    return (a/gcd(a,b)*b);
}
long long bfs(void) {
    memset(dist,-1,sizeof dist);
    queue<int> q;
    dist[fst[0]%cyc[1]]=0;
    q.push(fst[0]%cyc[1]);
    while (!q.empty()) {
        int u=q.front();q.pop();
        if (u==fst[1]%cyc[1]) return (fst[0]+1LL*dist[u]*cyc[0]);
        int v=(u+cyc[0])%cyc[1];
        if (dist[v]<0) {
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
    return (-1);
}
void process(void) {
    vector<int> tmp[2];
    REP(i,2) tmp[i]=haveGoal(i);
    if (tmp[0].empty() || tmp[1].empty()) answer(-1);
    if (tmp[0].size()==1 && tmp[1].size()==1) answer(tmp[0][0]==tmp[1][0]?tmp[0][0]:-1);
    REP(i,2) if (tmp[i].size()==1) {
        int cycSize=tmp[i^1][1]-tmp[i^1][0];
        if (tmp[i][0]>=tmp[i^1][0] && (tmp[i][0]-tmp[i^1][0])%cycSize==0) answer(tmp[i][0]);
        else answer(-1);
    }
    REP(i,2) {
        fst[i]=tmp[i][0];
        cyc[i]=tmp[i][1]-tmp[i][0];
    }
    long long val=bfs();
    if (val<0) answer(-1);
    long long jump=lcm(cyc[0],cyc[1]);
    while (val<fst[1]) val+=jump;
    answer(val);
}
int main(void) {
    init();
    process();
    return 0;
}