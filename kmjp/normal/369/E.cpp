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
    V bit[ME];
    BIT(){clear();};
    void clear() {ZERO(bit);};

    //V* bit;
    //BIT(){bit=new V[ME];memset(bit,0,sizeof(V)*ME);}

    
    V total(int entry) {
        V s=0;
        entry++;
        while(entry>0) {
            s+=bit[entry-1];
            entry -= entry & -entry;
        }
        return s;
    }
    void update(int entry, V val) {
        entry++;
        while(entry <= ME) {
            bit[entry-1] += val;
            entry += entry & -entry;
        }
    }
};

BIT<ll,1<<21> bt;

int N,M;
int L[1000011];
vector<int> R[1000011];
vector<int> Q[1000011];
vector<int> RQ[1000011];
int NU[1000011];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) {
        cin>>x>>y;
        L[x]++;
        R[y].push_back(x);
    }
    
    FOR(i,M) {
        NU[i]=N;
        cin>>x;
        Q[i].push_back(0);
        FOR(j,x) {
            cin>>y;
            Q[i].push_back(y);
            RQ[y].push_back(i);
        }
        reverse(Q[i].begin(),Q[i].end());
    }
    for(x=1;x<=1000000;x++) {
        //if(L[x]) bt.update(x,L[x]);
        FOR(i,RQ[x].size()) {
            y=RQ[x][i];
            //_P("%d %d %d %d\n",x,Q[y].back(),y,bt.total(x-1)-bt.total(Q[y].back()));
            NU[y] -= bt.total(x-1)-bt.total(Q[y].back());
            Q[y].resize(Q[y].size()-1);
        }
        FOR(i,R[x].size()) bt.update(R[x][i],1);
    }
    FOR(y,M) NU[y] -= bt.total(1000001)-bt.total(Q[y].back());
    FOR(i,M) _P("%d\n",NU[i]);
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}