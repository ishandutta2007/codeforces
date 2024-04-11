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

int N;
vector<int> Eok[100001];
vector<int> Eng[100001];
set<int> rep;

bool dpdp(int cur,int pre,bool pro) {
    int i,x;
    bool rp=false;
    
    FOR(i,Eng[cur].size()) if(Eng[cur][i]!=pre) rp |= dpdp(Eng[cur][i],cur,true);
    FOR(i,Eok[cur].size()) if(Eok[cur][i]!=pre) rp |= dpdp(Eok[cur][i],cur,false);
    
    if(!rp && pro) {
        rep.insert(cur+1);
        rp = true;
    }
    return rp;
}


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y>>f;
        if(f==1) {
            Eok[x-1].push_back(y-1);
            Eok[y-1].push_back(x-1);
        }
        else {
            Eng[x-1].push_back(y-1);
            Eng[y-1].push_back(x-1);
        }
    }
    dpdp(0,-1,false);
    _P("%d\n",rep.size());
    ITR(it,rep) _P("%d ",*it);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}