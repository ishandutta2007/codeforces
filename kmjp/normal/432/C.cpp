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
int A[100001],B[100001];
int step[100005];
int NP,prime[100000];
const int prime_max = 1000000;
int p[prime_max];
void cprime() {
    
    int i,j;
    NP=0;
    for(i=2;i<prime_max;i++) {
        if(p[i]) continue;
        prime[NP++]=i;
        for(j=i*2;j<prime_max;j+=i) p[j]=i;
    }
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cprime();
    for(i=2;i<=100003;i++) {
        if(p[i]==0) step[i]=i;
        else if(i%2) step[i]=3;
        else {
            for(y=0;y<NP;y++) {
                if(p[i-prime[y]]==0) {
                    step[i]=i-prime[y];
                    break;
                }
            }
        }
    }
    
    vector<pair<int,int> > V;
    cin>>N;
    FOR(i,N) {
        cin>>x;
        A[i]=x-1;
        B[x-1]=i;
    }
    FOR(i,N) {
        while(A[i]!=i) {
            
            x=step[B[i]-i+1]-1;
            y=B[i]-x;
            V.push_back(make_pair(y,B[i]));
            swap(A[y],A[B[i]]);
            B[A[B[i]]]=B[i];
            B[A[y]]=y;
        }
    }
    _P("%d\n",V.size());
    FOR(i,V.size()) _P("%d %d\n",V[i].first+1,V[i].second+1);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}