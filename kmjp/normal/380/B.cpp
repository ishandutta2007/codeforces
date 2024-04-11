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
int cnt[7010];
int up[200010][15];

int S;
int LV[10000],L[10000],R[10000],X[10000];


int num(int leflv, int pos) {
    int i;
    for(i=14;i>=0;i--) if(leflv&(1<<i)) {
        pos=up[pos][i];
        if(pos>=200000) break;
    }
    return pos;
}

void solve() {
    int f,i,j,k,x,y,l,r;
    
    for(i=1;i<=200000;i++) {
        int j=0;
        while(1<<(j+1) <= i) j++;
        up[i][0]=i+j+1;
    }
    FOR(x,14) {
        for(i=0;i<=200000;i++) {
            if(up[i][x]>=200000) up[i][x+1]=200001;
            else if(up[up[i][x]][x]>=200000) up[i][x+1]=200001;
            else up[i][x+1]=up[up[i][x]][x];
        }
    }
    
    cin>>N>>M;
    
    FOR(i,M) {
        cin>>x;
        if(x==1) {
            cin>>LV[S]>>L[S]>>R[S]>>X[S];
            S++;
        }
        else {
            cin>>l>>r;
            set<int> SS;
            FOR(j,S) {
                if(LV[j]<l) continue;
                int nr=num(LV[j]-l,r);
                int nl=num(LV[j]-l,r-1)+1;
                if(nl>R[j]) continue;
                if(nr<L[j]) continue;
                SS.insert(X[j]);
            }
            cout << SS.size() << endl;
            
        }
        
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