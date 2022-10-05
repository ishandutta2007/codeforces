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

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    BIT(){clear();};
    void clear() {ZERO(bit);};
    
    V total(int entry) {
        V s=0;
        entry++;
        while(entry>0) s+=bit[entry-1], entry -= entry & -entry;
        return s;
    }
    void update(int entry, V val) {
        entry++;
        while(entry <= (1<<ME)) bit[entry-1] += val, entry += entry & -entry;
    }
};
BIT<int,20> bt;


int N,P;
vector<int> E[300001];
int inin[300001];
void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>P;
    FOR(i,N) {
        cin>>x>>y;
        x--,y--;
        if(x>y) swap(x,y);
        E[x].push_back(y);
        inin[x]++;
        inin[y]++;
    }
    
    ll tot=0;
    
    for(i=N-1;i>=0;i--) {
        sort(E[i].begin(),E[i].end());
        FOR(j,E[i].size()) {
            bt.update(inin[E[i][j]]+1,-1);
            inin[E[i][j]]--;
            bt.update(inin[E[i][j]]+1,1);
        }
        j=inin[i];
        if(j>=P) {
            tot+=N-1-i;
        }
        else {
            tot+=N-1-i-bt.total(P-j);
        }
        
        FOR(j,E[i].size()) {
            bt.update(inin[E[i][j]]+1,-1);
            inin[E[i][j]]++;
            bt.update(inin[E[i][j]]+1,1);
        }
        
        bt.update(inin[i]+1,1);
    }
    cout << tot << endl;
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}