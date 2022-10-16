#include<bits/stdc++.h>
#define MAX   100100
#define NMOD   2
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int mod[]={(int)1e9+2277,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
int base;
void precalc(void) {
    srand(time(NULL));
    base=227+rand()%227;
}
struct Hash {
    int len,val[NMOD];
    Hash() {
        len=0;
        memset(val,0,sizeof val);
    }
    Hash(const string &s) {
        len=s.size();
        memset(val,0,sizeof val);
        FORE(it,s) REP(j,NMOD) val[j]=(1LL*val[j]*base+*it)%mod[j];
    }
    bool operator < (const Hash &x) const {
        if (len!=x.len) return (len<x.len);
        REP(i,NMOD) if (val[i]!=x.val[i]) return (val[i]<x.val[i]);
        return (false);
    }
};
const string webPrefix="http://";
map<string,set<string> > allWeb;
map<Hash,vector<string> > allGroup;
pair<string,string> detect(const string &s) {
    FOR(i,webPrefix.size(),(int)s.size()-1) if (s[i]=='/')
        return (make_pair(s.substr(0,i),s.substr(i,s.size())));
    return (make_pair(s,""));
}
Hash hashSet(const set<string> &s) {
    string code;
    FORE(it,s) {
        code+=*it;
        code+="$";
    }
    return (Hash(code));
}
void process(void) {
    int n;
    cin>>n;
    REP(love,n) {
        string s;
        cin>>s;
        pair<string,string> tmp=detect(s);
        allWeb[tmp.fi].insert(tmp.se);
    }
    FORE(it,allWeb) allGroup[hashSet(it->se)].push_back(it->fi);
    int cnt=0;
    FORE(it,allGroup) if (it->se.size()>1) cnt++;
    cout<<cnt<<endl;
    FORE(it,allGroup) if (it->se.size()>1) {
        FORE(jt,it->se) cout<<*jt<<" ";
        cout<<"\n";
    }
}
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    precalc();
    process();
    return 0;
}