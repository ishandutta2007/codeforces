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

int N,K;
ll X[400001],A[400001],S[400001];
pair<ll,int> ST[400001];
double ave[400001];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N;
    FOR(i,N) {
        cin>>X[i];
        X[i]+=100000000;
        ST[i]=make_pair(X[i],i+1);
    }
    sort(ST,ST+N);
    FOR(i,N) {
        A[i]=ST[i].first;
        S[i+1]=S[i]+A[i];
    }
    
    cin>>K;
    double tot=0;
    FOR(i,K) {
        tot += (S[K]-S[i+1])-(A[i]*(K-(i+1)));
        tot += (A[i]*(i))-S[i];
    }
    ave[0] = tot;
    for(i=K;i<N;i++) {
        tot -= 2*((S[i]-S[i-K+1])-(A[i-K]*(K-1)));
        tot += 2*((A[i]*(K-1))-(S[i]-S[i-K+1]));
        ave[i-(K-1)] = tot;
    }
    double mi=1e200;
    x=-1;
    FOR(i,N-K+1) if(ave[i]<mi) x=i,mi=ave[i];
    FOR(i,K) _P("%d ",ST[x+i].second);
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}