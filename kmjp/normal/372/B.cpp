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

int H,W,Q;
string S[100];
int num[42][42][42][42];
ll snum[42][42][42][42];
ll snum2[42][42][42][42];
ll res[42][42][42][42];

void solve() {
    int f,i,j,k,l,x,y,xx1,yy1,xx2,yy2;
    
    cin>>H>>W>>Q;
    FOR(y,H) cin>>S[y];
    FOR(y,H) FOR(x,W) {
        int r=100;
        FOR(i,H-y) {
            FOR(j,min(W-x,r)) {
                if(S[y+i][x+j]=='1') break;
                num[y][x][i][j]=1;
            }
            r=min(r,j);
        }
        FOR(i,H-y) {
            FOR(j,W-x) {
                snum[y][x][i][j]=num[y][x][i][j];
                if(i>0 && j>0) {
                    snum[y][x][i][j]+=snum[y][x][i-1][j]+snum[y][x][i][j-1]-snum[y][x][i-1][j-1];
                }
                else if(i>0) snum[y][x][i][j]+=snum[y][x][i-1][j];
                else if(j>0) snum[y][x][i][j]+=snum[y][x][i][j-1];
            }
        }
    }
    for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) {
        FOR(i,y+1) FOR(j,x+1) {
            snum2[y][x][i][j]=snum[y-i][x-j][i][j];
            if(i>0 && j>0) {
                snum2[y][x][i][j]+=snum2[y][x][i-1][j]+snum2[y][x][i][j-1]-snum2[y][x][i-1][j-1];
            }
            else if(i>0) snum2[y][x][i][j]+=snum2[y][x][i-1][j];
            else if(j>0) snum2[y][x][i][j]+=snum2[y][x][i][j-1];
        }
    }
    
    FOR(i,Q) {
        cin>>yy1>>xx1>>yy2>>xx2;
        cout << snum2[yy2-1][xx2-1][yy2-yy1][xx2-xx1] << endl;
    }
    
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}