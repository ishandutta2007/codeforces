#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M;
int D[300001];
int id;
int L[300001],R[300001];
vector<int> C[300001];
ll mo=1000000007;

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    BIT(){clear();};
    void clear() {ZERO(bit);};

    V total(int entry) {
        V s=0;
        entry++;
        while(entry>0) {
            s+=bit[entry-1], entry -= entry & -entry;
            s%=mo;
            if(s<0) s+=mo;
        }
        return s;
    }
    void update(int entry, V val) {
        entry++;
        while(entry <= (1<<ME)) {
            bit[entry-1] += val;
            bit[entry-1] %= mo;
            if(bit[entry-1]<mo) bit[entry-1]+=mo;
            entry += entry & -entry;
        }
    }
};
BIT<ll,20> bt1,bt2;

void dfs(int cur) {
    L[cur]=id++;
    ITR(it,C[cur]) dfs(*it);
    R[cur]=id;
}

void solve() {
    int f,i,j,k,l,x,y,v;
    cin>>N;
    
    FOR(i,N-1) {
        cin>>x;
        D[i+2]=D[x]+1;
        C[x].push_back(i+2);
    }
    dfs(1);
    cin>>M;
    FOR(i,M) {
        cin>>j;
        if(j==1) {
            cin>>v>>x>>k;
            bt1.update(L[v],x+k*(ll)D[v]%mo);
            bt1.update(R[v],-(x+k*(ll)D[v]%mo));
            bt2.update(L[v],-k);
            bt2.update(R[v],k);
        }
        else {
            cin>>v;
            ll vv=bt1.total(L[v])+D[v]*bt2.total(L[v])%mo;
            vv%=mo;
            if(vv<0) vv+=mo;
            cout << vv << endl;
        }
    }
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}