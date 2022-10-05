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

int N,M,Q;
int A[1001][1001];
int B[4][1024][1024];

void solve() {
    int f,i,j,k,l,x,y,ty,tx;
    cin>>N>>M>>Q;
    
    FOR(y,N) FOR(x,M) cin>>A[y][x];
    FOR(y,N) FOR(x,M) B[0][y][x]=(A[y][x])?(1+((x>0)?B[0][y][x-1]:0)):0;
    FOR(y,N) for(x=M-1;x>=0;x--) B[1][y][x]=(A[y][x])?(1+(B[1][y][x+1])):0;
    FOR(y,N) FOR(x,M) B[2][y][x]=(A[y][x])?(1+((y>0)?B[2][y-1][x]:0)):0;
    for(y=N-1;y>=0;y--) FOR(x,M) B[3][y][x]=(A[y][x])?(1+(B[3][y+1][x])):0;
    
    while(Q--) {
        cin>>i>>ty>>tx;
        tx--,ty--;
        if(i==1) {
            A[ty][tx]^=1;
            FOR(x,M) B[0][ty][x]=(A[ty][x])?(1+((x>0)?B[0][ty][x-1]:0)):0;
            for(x=M-1;x>=0;x--) B[1][ty][x]=(A[ty][x])?(1+(B[1][ty][x+1])):0;
            FOR(y,N) B[2][y][tx]=(A[y][tx])?(1+((y>0)?B[2][y-1][tx]:0)):0;
            for(y=N-1;y>=0;y--) B[3][y][tx]=(A[y][tx])?(1+(B[3][y+1][tx])):0;
            
        }
        else if(A[ty][tx]==0) cout << 0 << endl;
        else {
            ll ret=1;
            FOR(i,4) {
                vector<pair<int,int> > V;
                V.push_back(make_pair(0,-1));
                if(i<2) {
                    j=B[i][ty][tx];
                    for(y=ty-(B[2][ty][tx]-1);y<=ty;y++) {
                        k=min(j,B[i][y][tx]);
                        while(V.size()>1 && V[V.size()-2].first>=k) V.pop_back();
                        if(V.back().first>=k) V.back().first=k;
                        else V.push_back(make_pair(k,y));
                    }
                    for(y=ty;y<ty+B[3][ty][tx];y++) {
                        j=min(j,B[i][y][tx]);
                        while(V.size()>1 && V[V.size()-2].first>=j) {
                            ret=max(ret,V.back().first*(ll)(y-V.back().second));
                            V.pop_back();
                        }
                        ret=max(ret,V.back().first*(ll)(y-V.back().second));
                        V.back().first=min(V.back().first,j);
                    }
                    ITR(it,V) ret=max(ret,min(j,it->first)*(ll)(ty+B[3][ty][tx]-it->second));
                }
                else {
                    j=B[i][ty][tx];
                    for(x=tx-(B[0][ty][tx]-1);x<=tx;x++) {
                        k=min(j,B[i][ty][x]);
                        while(V.size()>1 && V[V.size()-2].first>=k) V.pop_back();
                        if(V.back().first>=k) V.back().first=k;
                        else V.push_back(make_pair(k,x));
                    }
                    for(x=tx;x<tx+B[1][ty][tx];x++) {
                        j=min(j,B[i][ty][x]);
                        while(V.size()>1 && V[V.size()-2].first>=j) {
                            ret=max(ret,V.back().first*(ll)(x-V.back().second));
                            V.pop_back();
                        }
                        ret=max(ret,V.back().first*(ll)(x-V.back().second));
                        V.back().first=min(V.back().first,j);
                    }
                    ITR(it,V) ret=max(ret,min(j,it->first)*(ll)(tx+B[1][ty][tx]-it->second));
                }
            }
            cout << ret << endl;
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