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

int N,K;
int P[3002],MP[3002];
int mat[3001][3001];
int nu;


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K;
    FOR(i,N) cin>>P[i];
    for(i=N-1;i>=0;i--) MP[i]=max(MP[i+1],P[i]);
    
    nu=1;
    mat[0][1]=1;
    set<pair<int,int> > S,S2;
    S.insert(make_pair(0,1));
    FOR(i,K) {
        S2.clear();
        ITR(it,S) {
            int cur=it->first;
            int ne=it->second;
            
            if(cur>=N-1) continue;
            if(ne>=N) continue;
            if(P[cur]!=0 && MP[ne]!=0 ) {
                if(ne+1<N && mat[ne+1][ne+2]==0) {
                    nu++;
                    mat[ne+1][ne+2]=1;
                    S2.insert(make_pair(ne+1,ne+2));
                }
                if(ne==N-1 && mat[0][0]==0) {
                    nu++;
                    mat[0][0]=1;
                }
            }
            if(P[cur]!=0 && MP[ne]!=100 ) {
                if(mat[cur][ne+1]==0) {
                    nu++;
                    mat[cur][ne+1]=1;
                    S2.insert(make_pair(cur,ne+1));
                }
            }
            if(P[cur]!=100 && MP[ne]!=0 ) {
                if(mat[ne][ne+1]==0) {
                    nu++;
                    mat[ne][ne+1]=1;
                    S2.insert(make_pair(ne,ne+1));
                }
            }
        }
        swap(S,S2);
    }
    
    _P("%d\n",nu);
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}