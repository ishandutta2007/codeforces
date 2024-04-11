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

int N,M,K,S;
int A[2001][2001];
int num2[2][10][2];
int mat[10][10];

void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>N>>M>>K>>S;
    FOR(i,10) {
        num2[0][i][0]=4000;
        num2[0][i][1]=0;
        num2[1][i][0]=4000;
        num2[1][i][1]=0;
    }
    FOR(y,N) FOR(x,M) {
        cin>>r;
        num2[0][r][0]=min(num2[0][r][0],x+y);
        num2[0][r][1]=max(num2[0][r][1],x+y);
        num2[1][r][0]=min(num2[1][r][0],y-x+2000);
        num2[1][r][1]=max(num2[1][r][1],y-x+2000);
    }
    FOR(i,S) {
        cin>>x;
        if(i>0) mat[x][y]++,mat[y][x]++;
        y=x;
    }
    
    r=0;
    FOR(y,10) FOR(x,10) if(mat[x][y]) {
        r = max(r, abs(num2[0][x][0]-num2[0][y][0]));
        r = max(r, abs(num2[0][x][1]-num2[0][y][0]));
        r = max(r, abs(num2[0][x][0]-num2[0][y][1]));
        r = max(r, abs(num2[0][x][1]-num2[0][y][1]));
        r = max(r, abs(num2[1][x][0]-num2[1][y][0]));
        r = max(r, abs(num2[1][x][1]-num2[1][y][0]));
        r = max(r, abs(num2[1][x][0]-num2[1][y][1]));
        r = max(r, abs(num2[1][x][1]-num2[1][y][1]));
    }
    _P("%d\n",r);
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}