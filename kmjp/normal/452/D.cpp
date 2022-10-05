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

int K,N[3],T[3];
priority_queue<int,vector<int>,greater<int> > A[3];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>K>>N[0]>>N[1]>>N[2]>>T[0]>>T[1]>>T[2];
    
    FOR(i,N[0]) A[0].push(0);
    FOR(i,N[1]) A[1].push(0);
    FOR(i,N[2]) A[2].push(0);
    
    int ret=0;
    FOR(i,K) {
        x=max(0,A[0].top());
        x=max(x,A[1].top()-T[0]);
        x=max(x,A[2].top()-T[0]-T[1]);
        ret=max(ret,x+T[0]+T[1]+T[2]);
        A[0].pop();
        A[1].pop();
        A[2].pop();
        A[0].push(x+T[0]);
        A[1].push(x+T[0]+T[1]);
        A[2].push(x+T[0]+T[1]+T[2]);
    }
    cout << ret << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}