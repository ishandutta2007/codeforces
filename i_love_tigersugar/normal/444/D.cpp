#include<bits/stdc++.h>
#define MAXL   50050
#define MAXH   500500
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int pw[]={0,26,26*26,26*26*26,26*26*26*26};
typedef pair<int,int> ii;
char s[MAXL];
vector<int> occ[MAXH];
map<ii,int> que;
int n,q;
inline void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
inline int hash(const string &t) {
    int sum=0;
    REP(i,t.size()) sum+=pw[i];
    int tmp=0;
    FORE(it,t) tmp=tmp*26+*it-'a';
    return (tmp+sum);
}
void init(void) {
    scanf("%s",s+1);
    n=strlen(s+1);
    FOR(i,1,n) FOR(j,1,4) if (i+j-1<=n) occ[hash(string(s+i,j))].push_back(i);
}
bool issub(const string &s,const string &t) {
    if (s.size()>t.size()) return (false);
    REP(i,t.size()) if (t.substr(i,s.size())==s) return (true);
    return (false);
}
int mindis(const vector<int> &a,const vector<int> &b,int la,int lb) {
    int ans=MAXL;
    FORE(it,a) {
        int p=upper_bound(b.begin(),b.end(),*it)-b.begin();
        if (p<b.size()) minimize(ans,b[p]-*it+lb);
        if (p>0) minimize(ans,*it-b[p-1]+la);
    }
    return (ans>n?-1:ans);
}
int answer(string &a,string &b) {
    int ha=hash(a);
    int hb=hash(b);
    if (occ[ha].empty() || occ[hb].empty()) return (-1);
    if (issub(a,b)) return (b.size());
    if (issub(b,a)) return (a.size());
    if (occ[ha].size()>occ[hb].size() || (occ[ha].size()==occ[hb].size() && ha>hb)) {
        swap(ha,hb);
        swap(a,b);
    }
    __typeof(que.begin()) it=que.find(ii(ha,hb));
    if (it!=que.end()) return (it->se);
    int ret=mindis(occ[ha],occ[hb],a.size(),b.size());
    que[ii(ha,hb)]=ret;
    return (ret);
}
void process(void) {
    scanf("%d",&q);
    REP(zz,q) {
        string a,b;
        cin>>a>>b;
        printf("%d\n",answer(a,b));
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}