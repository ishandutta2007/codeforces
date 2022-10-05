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

int K;
int R[5001];
set<int> S[64];
int pr[]={2,3,5,7,11,13};


int check(int id) {
    int i,x,y;
    int num[6],rn;
    int snum[64];
    vector<int> mask[7];
    vector<int> S2[64];
    
    for(x=1;x<1<<id;x++) mask[__builtin_popcount(x)].push_back(x);
    
    FOR(i,64) snum[i]=S[i].size();
    ZERO(snum);
    rn=0;
    for(i=id;i>=0&&rn<K;i--) {
        while(1) {
            y=rn;
            FOR(x,mask[i].size()) {
                if(snum[mask[i][x]]>=S[mask[i][x]].size()) goto out;
                if(rn==K) goto out;
                snum[mask[i][x]]++;
                rn++;
            }
            if(y==rn) break;
        }
        out:
        ;
    }
    for(i=id;i>=0&&rn<K;i--) {
        FOR(x,mask[i].size()) {
            y=min(K-rn,(int)S[mask[i][x]].size()-snum[mask[i][x]]);
            rn+=y;
            snum[mask[i][x]]+=y;
        }
    }
    if(rn<K) return 0;
    ZERO(num);
    FOR(i,1<<id) FOR(x,id) if(i&(1<<x)) num[x]+=snum[i];
    FOR(x,id) if(num[x]<K/2) return 0;
    
    FOR(i,1<<id) {
        ITR(it,S[i]) {
            if(snum[i]--==0) break;
            _P("%d ",*it);
        }
    }
    _P("\n");
    return 1;
}

set<int> lup(int id) {
    int i,x;
    set<int> s1,s2,s3;
    
    x=1;
    FOR(i,6) if(id&(1<<i)) x*=pr[i];
    if(x>2*K*K) return s1;
    s1.insert(x);
    s2.insert(x);
    while(!s2.empty()) {
        s3.clear();
        FOR(i,6) if(id&(1<<i)) ITR(it,s2) {
            if(*it*pr[i]<=2*K*K) {
                s1.insert(*it*pr[i]);
                s3.insert(*it*pr[i]);
            }
        }
        s2=s3;
    }
    return s1;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>K;
    for(x=1;x<=63;x++) S[x]=lup(x);
    for(i=1;i<=6;i++) if(check(i)) break;
    
    
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}