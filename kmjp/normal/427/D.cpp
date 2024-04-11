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

string S[2];
int L[2];

const int AR=5002;
int A0[AR][AR];
int A1[AR][AR];
int A01[AR][AR];
void LCP(string s1,string s2,int arr[AR][AR]) {
    int x,y;
    ZERO(arr);
    for(x=s1.size()-1;x>=0;x--) FOR(y,s2.size()) if(s1[x]==s2[y]) arr[x][y]=arr[x+1][y+1]+1;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>S[0];
    cin>>S[1];
    L[0]=S[0].size();
    L[1]=S[1].size();
    
    LCP(S[0],S[0],A0);
    LCP(S[1],S[1],A1);
    LCP(S[0],S[1],A01);
    
    int mi=5001;
    FOR(x,L[1]) {
        A1[x][x]=0;
        FOR(y,L[1]) if(x!=y) A1[x][x]=max(A1[x][x],A1[x][y]);
    }
    
    FOR(x,L[0]) {
        int ma=1;
        FOR(y,L[0]) if(x!=y) ma=max(ma,A0[x][y]+1);
        FOR(y,L[1]) if(A01[x][y]>=ma && A1[y][y]<A01[x][y]) mi=min(mi,max(A1[y][y]+1,ma));
    }
    
    if(mi>5000) _P("-1\n");
    else _P("%d\n",mi);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}