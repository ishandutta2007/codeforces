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

int K,N,M;
ll X;
ll sl[110];
ll sln[110][2];
ll slhd[110][2];
ll slcn[110][4];


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>K>>X>>N>>M;
    sl[1]=N;
    sl[2]=M;
    sln[1][0]=1;
    sln[2][1]=1;
    slhd[1][0]=0;
    slhd[1][1]=0;
    slhd[2][0]=1;
    slhd[2][1]=1;
    
    
    for(i=3;i<=K;i++) {
        sl[i]=sl[i-2]+sl[i-1];
        slhd[i][0]=slhd[i-2][0]; //head
        slhd[i][1]=slhd[i-1][1]; //tail
        sln[i][0]=sln[i-2][0]+sln[i-1][0]; //nums1
        sln[i][1]=sln[i-2][1]+sln[i-1][1]; //nums2
        slcn[i][0]=slcn[i-2][0]+slcn[i-1][0]; // num s1-s1
        slcn[i][1]=slcn[i-2][1]+slcn[i-1][1]; // s1-s2
        slcn[i][2]=slcn[i-2][2]+slcn[i-1][2]; // s2-s1
        slcn[i][3]=slcn[i-2][3]+slcn[i-1][3]; // s2-s2
        slcn[i][slhd[i-2][1]*2+slhd[i-1][0]]++;
    }
    
    if(N==1 && M==1) {
        if(slcn[K][1]==X) _P("A\nC\n");
        else if(slcn[K][2]==X) _P("C\nA\n");
        else _P("Happy new year!\n");
        return;
    }
    
    string rr1,rr2;
    FOR(j,N) rr1+='B';
    FOR(j,M) rr2+='B';
    for(x=0;x<=N/2;x++) for(y=0;y<=M/2;y++) {
        ll tot=x*sln[K][0]+y*sln[K][1];
        
        string r1=rr1,r2=rr2;
        for(r1[0]='A';r1[0]<='C';r1[0]++) for(r2[0]='A';r2[0]<='C';r2[0]++) {
            FOR(i,3) FOR(j,3) {
                if(N==1 && r1[0]-'A' != i) continue;
                if(M==1 && r2[0]-'A' != j) continue;
                r1[N-1]='A'+i;
                r2[M-1]='A'+j;
                
                ll tot2=tot;
                if(r1[N-1]=='A' && r1[0]=='C') tot2+=slcn[K][0];
                if(r1[N-1]=='A' && r2[0]=='C') tot2+=slcn[K][1];
                if(r2[M-1]=='A' && r1[0]=='C') tot2+=slcn[K][2];
                if(r2[M-1]=='A' && r2[0]=='C') tot2+=slcn[K][3];
                
                if(tot2!=X) continue;
                
                l=N;
                if(r1[0]!='B') l--;
                if(N!=1 && r1[N-1]!='B') l--;
                if(2*x>l) continue;
                l=M;
                if(r2[0]!='B') l--;
                if(M!=1 && r2[M-1]!='B') l--;
                if(2*y>l) continue;
                l=(r1[0]!='B');
                FOR(k,x) {
                    r1[l+k*2] ='A';
                    r1[l+k*2+1] ='C';
                }
                l=(r2[0]!='B');
                FOR(k,y) {
                    r2[l+k*2] ='A';
                    r2[l+k*2+1] ='C';
                }
                cout << r1 << endl;
                cout << r2 << endl;
                return;
            }
        
        }
    }
    _P("Happy new year!\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}