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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N;
int A[8];
vector<int> R;
void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>N;
    FOR(i,N) A[GETi()]++;
    
    while(R.size()<N/3) {
        if(A[4] && A[2] && A[1]) {
            R.push_back(42);
            A[4]--;A[2]--;A[1]--;
        }
        else if(A[6] && A[3] && A[1]) {
            R.push_back(63);
            A[6]--;A[3]--;A[1]--;
        }
        else if(A[6] && A[2] && A[1]) {
            R.push_back(62);
            A[6]--;A[2]--;A[1]--;
        }
        else break;
    }
    
    if(R.size()==N/3) FOR(i,R.size()) _P("1 %d %d\n",R[i]%10,R[i]/10);
    else _P("-1\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}