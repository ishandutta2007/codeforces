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

#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
int GETi() { int i;scanf("%d",&i); return i;}

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


int N;
vector<int> E[100001];
char C[100001];
int num[100001];
char CN[100001];


int dfs_num(int cur,int pre) {
    int i;
    int ma=-1;
    
    num[cur]=1;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) continue;
        if(C[tar]) CN[cur] = max(CN[cur],C[tar]);
        else num[cur]+= dfs_num(tar,cur), CN[cur] = max(CN[cur],CN[tar]);
    }
    return num[cur];
}

pair<int,int> dfs_center(int cur,int pre,int nu) {
    int i;
    pair<int,int> res=make_pair(1<<30,-1);
    int ma=0,c=1;
    
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre || C[tar]) continue;
        res=min(res,dfs_center(tar,cur,nu));
        
        ma=max(ma,num[tar]);
        c+=num[tar];
    }
    return min(res,make_pair(max(ma,nu-c),cur));
}

void solve() {
    int r,i,j,k,l,x,y,tx,ty;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    
    FOR(i,N) {
        while(C[i]==0) {
            dfs_num(i,-1);
            pair<int,int> p=dfs_center(i,-1,num[i]);
            C[p.second] = CN[i]+1;
            if(C[p.second]==1) C[p.second]='A';
            if(p.first==0) break;
        }
    }
    
    FOR(i,N) _P("%c ",C[i]);
    _P("\n");
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}