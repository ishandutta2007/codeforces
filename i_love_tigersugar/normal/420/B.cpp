#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
bool ok[MAX];
int n,m;
ii eve[MAX];
set<int> cur;
bool prev[MAX];
vector<ii> all[MAX];
int sz[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) ok[i]=true;
    FOR(i,1,m) {
        char c;
        int p;
        scanf(" %c %d",&c,&p);
        eve[i]=ii(p,(c=='+')?1:-1);
        if (!prev[p] && c=='-') cur.insert(p);
        prev[p]=true;
        all[p].push_back(ii(i,eve[i].se));
    }
    sz[0]=(!cur.empty());
    FOR(i,1,m) {
        if (eve[i].se>0) cur.insert(eve[i].fi);
        else cur.erase(eve[i].fi);
        sz[i]=sz[i-1]+(!cur.empty());
    }
    //FOR(i,0,m) printf("%d ",sz[i]); printf("\n");
}
bool check(int x) {
    //printf("CHECK %d\n",x);
    if (all[x].empty()) return (true);
    //FORE(it,all[x]) printf("%d %d\n",it->fi,it->se);
    //printf("CHECK %d\n",x);
    REP(i,all[x].size()-1) if (all[x][i].se<0 && all[x][i+1].se>0) {
        int l=all[x][i].fi;
        int r=all[x][i+1].fi;
        if (sz[r-1]>sz[l-1]) return (false);
    }
    //printf("CHECK %d\n",x);
    if (all[x][0].se>0) {
        int t=all[x][0].fi;
        if (sz[t-1]>0) return (false);
    }
    //printf("CHECK %d\n",x);
    if (all[x][all[x].size()-1].se<0) {
        int t=all[x][all[x].size()-1].fi;
        //printf("LAST of %d is %d\n",x,t);
        if (sz[m]>sz[t-1]) return (false);
    }
    return (true);
}
void process(void) {
    vector<int> res;
    FOR(i,1,n) if (check(i)) res.push_back(i);
    printf("%d\n",res.size());
    FORE(it,res) printf("%d ",*it);
}
int main(void) {
    init();
    process();
    return 0;
}