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

int N,K,A[10000];

void solve() {
    int f,i,j,k,l,x,y,r;
    cin>>N>>K;
    FOR(i,N) cin>>A[i];
    int ma=-1000000;
    FOR(l,N) for(r=l;r<N;r++) {
        vector<int> V1,V2;
        FOR(i,N) {
            if(i>=l && i<=r) V1.push_back(A[i]);
            else V2.push_back(A[i]);
        }
        sort(V1.begin(),V1.end());
        sort(V2.begin(),V2.end());
        FOR(i,min(min(K,(int)V1.size()),(int)V2.size())+1) {
            int t=0;
            FOR(j,V1.size()) {
                if(j<i) t+=V2[V2.size()-1-j];
                else t+=V1[j];
            }
            ma=max(ma,t);
        }
    }
    cout<<ma<<endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}