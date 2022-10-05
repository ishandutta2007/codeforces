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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,M,Q;
ll A[100011],ST[100011];
ll AC[100011];
vector<int> S[100001];
vector<int> li,he;
map<ll,int> intersection;

void solve() {
    int f,i,j,k,x,y,z,tx,ty;
    
    cin>>N>>M>>Q;
    FOR(i,N) cin>>A[i];
    FOR(i,M) {
        cin>>x;
        FOR(j,x) {
            cin>>y;
            y--;
            ST[i]+=A[y];
            S[i].push_back(y);
        }
        sort(S[i].begin(),S[i].end());
    }
    FOR(i,M) {
        if(S[i].size()<2000) li.push_back(i);
        else he.push_back(i);
    }
    
    FOR(x,N) FOR(y,he.size()) {
        vector<int> vv;
        set_intersection(S[x].begin(),S[x].end(),S[he[y]].begin(),S[he[y]].end(),back_inserter(vv));
        intersection[x*100000LL+he[y]]=vv.size();
    }
    
    FOR(i,Q) {
        string s;
        cin>>s>>k;
        k--;
        if(s[0]=='?') {
            ll r = 0;
            if(S[k].size()<2000) {
                FOR(j,S[k].size()) r+=A[S[k][j]];
                FOR(y,he.size()) r+= intersection[k*100000LL+he[y]]*AC[he[y]];
            }
            else r=ST[k];
            
            cout << r << endl;
        }
        else {
            cin>>x;
            if(S[k].size()<2000) FOR(j,S[k].size()) A[S[k][j]]+=x;
            else AC[k]+=x;
            FOR(y,he.size()) ST[he[y]] += intersection[k*100000LL+he[y]]*(ll)x;
        }
    }
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}