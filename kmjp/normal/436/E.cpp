#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,W;
int A[400000],B[400000];
set<pair<int,int> > S1,S2;
pair<int,int> P[400000];
int ok[400000],ok2[400000];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>W;
    FOR(i,N) {
        cin>>A[i]>>B[i];
        S1.insert(make_pair(A[i],i));
        S2.insert(make_pair(B[i],i));
    }
    
    ll ret=0;
    FOR(i,W) {
        if(i<W-1 && !S2.empty() && S1.size()>1) {
            pair<int,int> p1=*S1.begin();
            S1.erase(S1.begin());
            pair<int,int> p2=*S1.begin();
            S1.erase(S1.begin());
            if(S2.begin()->first < p1.first+p2.first) {
                pair<int,int> p=*S2.begin();
                S2.erase(S2.begin());
                ret+=A[p.second];
                ok[p.second]++;
                S1.insert(p1);
                S1.insert(p2);
                S1.erase(make_pair(A[p.second],p.second));
                S1.insert(make_pair(B[p.second]-A[p.second],p.second));
                continue;
            }
            S1.insert(p1);
            S1.insert(p2);
        }
        pair<int,int> p=*S1.begin();
        S1.erase(S1.begin());
        ret+=p.first;
        ok[p.second]++;
        if(ok[p.second]==1) {
            S2.erase(make_pair(B[p.second],p.second));
            S1.insert(make_pair(B[p.second]-A[p.second],p.second));
        }
    }
    
    _P("%lld\n",ret);
    FOR(i,N) _P("%d",ok[i]);
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}