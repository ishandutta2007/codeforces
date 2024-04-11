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

int N,M;
int A[5005],C[5005];
set<int> S;

map<int,int> memo;

int calc(int hoge) {
    int num=0;
    int org=hoge;
    if(memo.find(hoge)!=memo.end()) return memo[hoge];
    if(hoge==1) return 0;
    int i;
    for(i=2;i*i<=hoge;i++) {
        while(hoge%i==0) {
            if(S.find(i)==S.end()) num++;
            else num--;
            hoge/=i;
        }
    }
    if(hoge>1) {
        if(S.find(hoge)==S.end()) num++;
        else num--;
    }
    return num;
    //return memo[org]=num;
}


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) cin>>A[i];
    FOR(i,M) {
        cin>>x;
        S.insert(x);
    }
    
    C[0]=A[0];
    FOR(i,N-1) C[i+1]=__gcd(C[i],A[i+1]);
    int gc=1;
    ll res=0;
    
    for(i=N-1;i>=0;i--) {
        if(calc(C[i]/gc)<0) gc=C[i];
        res += calc(A[i]/gc);
    }
    cout << res << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}