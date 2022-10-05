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

ll N,D,X;
ll A[100001],B[100001];
vector<int> BB;

ll getNextX() {
    return X=(X * 37 + 10007) % 1000000007;
}

void dosmall() {
    int f,i,j,k,l,x,y;
    
    FOR(i,N) {
        ll ma=0;
        FOR(j,BB.size()) if(BB[j]<=i) ma=max(A[i-BB[j]],ma);
        _P("%lld\n",ma);
    }
}

void dolarge(){
    int f,i,j,k,l,x,y;
    int ID[100001];
    FOR(i,N) ID[A[i]]=i;
    
    FOR(i,N) {
        int ok=0;
        for(j=N;j>=N-1000;j--) {
            if(ID[j]>i) continue;
            if(B[i-ID[j]]) {
                _P("%d\n",j);
                ok=1;
                break;
            }
        }
        if(ok) continue;
        ll ma=0;
        FOR(j,BB.size()) {
            if(BB[j]>i) break;
            ma=max(A[i-BB[j]],ma);
        }
        _P("%lld\n",ma);
    }
    
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>D>>X;
    FOR(i,N) A[i]=i+1;
    FOR(i,N) swap(A[i],A[getNextX()%(i+1)]);
    FOR(i,N) B[i]=(i<D);
    FOR(i,N) swap(B[i],B[getNextX()%(i+1)]);
    FOR(i,N) if(B[i]) BB.push_back(i);
    
    if(D<=1000) {
        dosmall();
    }
    else {
        dolarge();
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