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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,K;
ll mo=1000000007;
ll dpdp[205][205][16];
const int CN=20;
ll C[CN][CN];

ll dodp(int level,int num,int mask) {
    int ma,i,j,k[5],l;
    if(num==0) return 1;
    if(num<0 || mask==0) return 0;
    if(dpdp[level][num][mask]!=-1) return dpdp[level][num][mask];
    /*
    if(mask==13 || mask==11 || mask==14) return dpdp[level][num][mask]=dodp(level,num,7); //used 1
    if(mask==9|| mask==6 || mask==12) return dpdp[level][num][mask]=dodp(level,num,3); //used 2
    if(mask==10) return dpdp[level][num][mask]=dodp(level,num,5); //used 2
    if(mask==2|| mask==4 || mask==8) return dpdp[level][num][mask]=dodp(level,num,1); //used 3
    */
    
    ll ret=0;
    FOR(ma,16) {
        if((mask & ma)!=ma) continue;
        
        //get whole block
        int bi=__builtin_popcount(ma);
        k[0]=k[1]=k[2]=k[3]=k[4]=0;
        k[bi]=1;
        if(bi==2 && (ma!=5) && (ma!=10)) k[1]++;
        if(bi==3) k[2]+=2;
        if(bi==4) k[2]+=2,k[3]+=4;
        
        // get boarder
        if(level>0) {
            int ma2=mask^ma;
            if(ma2==13 || ma2==11 || ma2==14) ma2=7;
            if(ma2==9 || ma2==6 || ma2==12) ma2=3;
            if(ma2==10) ma2=5;
            if(ma2==2 || ma2==4 || ma2==8) ma2=1;
            
            int x,y;
            FOR(l,5){
                if(k[l]==0) continue;
                if(num-l<0) continue;
                if(ma2==0) x=0,y=0;
                else if(ma2==1) x=3,y=0;
                else if(ma2==5) x=6,y=0;
                else if(ma2==3) x=6,y=1;
                else if(ma2==7) x=9,y=2;
                else if(ma2==15) x=12,y=4;
                FOR(i,y+1) FOR(j,x-i*2+1) ret += dodp(level-1,num-l-(i+j),ma2) * ((k[l]* C[y][i] * C[x-i*2][j])%mo);
            }
        }
        else {
            FOR(l,5) ret += (num==l) * k[l];
        }
    }
    
    return dpdp[level][num][mask]=(ret%=mo);
}

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>N>>K;
    FOR(x,CN) C[x][0]=C[x][x]=1;
    for(i=1;i<CN;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
    MINUSL(dpdp);
    
    ll ret=dodp(N,K,15);
    FOR(i,K) ret=(ret*(i+1))%mo;
    cout << ret << endl;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}