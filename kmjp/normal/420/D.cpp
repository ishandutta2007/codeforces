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
int num[1000008];
int used[1000008];
vector<int> V[3000];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    
    FOR(i,N) V[i/1000].push_back(i);
    
    FOR(i,M) {
        cin>>x>>y;
        FOR(j,3000) {
            if(y<=V[j].size()) break;
            y-=V[j].size();
        }
        y--;
        k=V[j][y];
        if(num[k]!=0 && num[k]!=x) return _P("-1\n");
        if(num[k]==0 && used[x]) return _P("-1\n");
        num[k]=x;
        used[x]=1;
        
        V[j].erase(V[j].begin()+y);
        if(V[0].size()>1000) {
            for(j=2998;j>=0;j--) swap(V[j+1],V[j]);
            V[0].clear();
            V[0].push_back(k);
        }
        else {
            V[0].resize(V[0].size()+1);
            for(j=V[0].size()-1;j>=1;j--) V[0][j]=V[0][j-1];
            V[0][0]=k;
        }
    }
    
    x=1;
    FOR(i,N) {
        while(used[x]) x++;
        if(num[i]==0) num[i]=x++;
        _P("%d ",num[i]);
    }
    _P("\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}