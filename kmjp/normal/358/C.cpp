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

int N,A[100001],B[100001];
vector<pair<int,int> > P;

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>N;
    FOR(i,N){
        cin>>A[i];
        if(A[i]!=0) P.push_back(make_pair(A[i],i));
        else {
            sort(P.begin(),P.end());
            FOR(j,3) {
                if(!P.empty()) {
                    B[P.back().second]=1;
                    P.pop_back();
                }
            }
            P.clear();
        }
    }
    
    j=0;
    FOR(i,N) {
        if(A[i]==0) {
            _P("%d",j);
            if(j==3) _P(" popStack popQueue popFront");
            else if(j==2) _P(" popStack popQueue");
            else if(j==1) _P(" popStack");
            _P("\n");
            j=0;
        }
        else if(B[i]) {
            if(j==0) _P("pushStack\n");
            if(j==1) _P("pushQueue\n");
            if(j==2) _P("pushFront\n");
            j++;
        }
        else{
            _P("pushBack\n");
        }
    }
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}