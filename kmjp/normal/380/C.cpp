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

string S;
int N,M;
int ML[1000010];
vector<pair<int,int> > Q[1000100];
int ret[1000100];

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
BIT<int,21> bt;


void solve() {
    int f,i,j,k,x,y,l,r;
    
    cin>>S;
    N=S.size();
    cin>>M;
    FOR(i,M) {
        cin>>l>>r;
        Q[r-1].push_back(make_pair(l-1,i));
    }
    
    stack<int> ST;
    y=0;
    FOR(i,N) {
        if(S[i]=='(') ST.push(i);
        else if(!ST.empty()) {
            ML[ST.top()]=i;
            bt.update(ST.top()+1,1);
            ST.pop();
            y++;
        }
        FOR(j,Q[i].size()) {
            ret[Q[i][j].second] = y-bt.total(Q[i][j].first);
        }
    }
    
    FOR(i,M) _P("%d\n",2*ret[i]);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}