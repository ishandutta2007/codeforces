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

int G[5][5];

void solve() {
    int f,i,j,k,l,x,y;
    FOR(y,5) FOR(x,5) cin>>G[y][x];
    vector<int> V;
    int ma=0;
    FOR(i,5) V.push_back(i);
    
    do{
        x=G[V[0]][V[1]]+G[V[1]][V[0]]+G[V[1]][V[2]]+G[V[2]][V[1]];
        x+=2*(G[V[2]][V[3]]+G[V[3]][V[2]]+G[V[3]][V[4]]+G[V[4]][V[3]]);
        ma=max(ma,x);
    } while(next_permutation(V.begin(),V.end()));
    
    
    cout << ma << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}