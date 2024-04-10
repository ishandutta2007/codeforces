#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
map<int,vector<ii> > mp;
int n;
void init(void) {
    scanf("%d",&n);
    REP(zz,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x].push_back(ii(x,y));
    }
}
int minEnd(const vector<ii> &v,int lim) {
    vector<int> tmp;
    FORE(it,v) if (it->se>=lim) tmp.push_back(it->se); else tmp.push_back(it->fi);
    sort(tmp.begin(),tmp.end());
    return (tmp.back());
}
void process(void) {
    int res=0;
    FORE(it,mp) if (!it->se.empty()) res=minEnd(it->se,res);
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}