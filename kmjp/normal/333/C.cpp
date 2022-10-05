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


int K,M;
set<int> S4[10000],S3[1000],S2[100],S1[10000],REV[10000];


void add(set<int> &t,set<int> &s1,set<int> &s2) {
    ITR(it1,s1) ITR(it2,s2) {
        t.insert(*it1+*it2);
        t.insert(*it1-*it2);
        t.insert(-*it1+*it2);
        t.insert(-*it1-*it2);
        t.insert(*it1**it2);
        t.insert(-*it1**it2);
    }
}

void dodo1(int c) {
    if(S1[c].empty()) {
        S1[c].insert(c);
        S1[c].insert(-c);
    }
}
void dodo2(int c) {
    if(!S2[c].empty()) return;
    
    S2[c].insert(c);
    S2[c].insert(-c);
    
    int s1,s2;
    s1=c/10,s2=c%10;
    dodo1(s1);dodo1(s2);
    add(S2[c],S1[s1],S1[s2]);
}

void dodo3(int c) {
    if(!S3[c].empty()) return;
    
    S3[c].insert(c);
    S3[c].insert(-c);
    
    int s1,s2;
    s1=c/100,s2=c%100;
    dodo1(s1);dodo2(s2);
    add(S3[c],S1[s1],S2[s2]);
    
    s1=c/10,s2=c%10;
    dodo2(s1);dodo1(s2);
    add(S3[c],S2[s1],S1[s2]);
}

void dodo4(int c) {
    int s1,s2;
    S4[c].insert(c);
    S4[c].insert(-c);
    
    s1=c/1000,s2=c%1000;
    dodo1(s1);dodo3(s2);
    add(S4[c],S1[s1],S3[s2]);
    
    s1=c/100,s2=c%100;
    dodo2(s1);dodo2(s2);
    add(S4[c],S2[s1],S2[s2]);
    
    s1=c/10,s2=c%10;
    dodo3(s1);dodo2(s1);
    add(S4[c],S3[s1],S1[s2]);
}


void solve() {
    int f,i,j,k,l, x,y;
    ll r=0;
    
    cin>>K>>M;
    FOR(i,10000) {
        dodo4(i);
        ITR(it,S4[i]) if(*it>=0) REV[*it].insert(i);
    }
    
    set<int> R;
    FOR(x,10000) {
        y = abs(x-K);
        if(y==10000) continue;
        ITR(it,REV[x]) {
            ITR(it2,REV[y]) R.insert(*it*10000+*it2);
            if(R.size()>=M) break;
        }
        if(R.size()>=M) break;
    }
    x=0;
    ITR(it,R) {
        if(x++>=M) break;
        _P("%08d\n",*it);
    }
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}