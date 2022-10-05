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

int N;
int A[10000];


ll dodo(int L,int R,int H) {
    if(L>R) return 0;
    vector<pair<int,int> > V;
    
    int mi=1000000001,x;
    for(x=L;x<=R;x++) mi=min(mi,A[x]);
    int ret=mi-H;
    int pre=-1;
    for(x=L;x<=R+1;x++) {
        if(A[x]>mi && pre==-1) pre=x;
        if(A[x]<=mi && pre>=0) {
            ret+=dodo(pre,x-1,mi);
            pre=-1;
        }
    }
    return min(R-L+1,ret);
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    cout << dodo(0,N-1,0) << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}