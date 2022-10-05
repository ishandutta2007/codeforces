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
int A[5];

int dodo(int p4,int p3,int ma) {
    int B[5];
    int i,x,r=0;
    FOR(i,5) B[i]=A[i];
    while(p4) {
        if(r>=ma) return r;
        if(B[4]) {
            i=min(B[4],p4);
            B[4]-=i,p4-=i;
            continue;
        }
        if(B[3]) {
            i=min(B[3],p4);
            r+=i;
            B[3]-=i,p4-=i;
            continue;
        }
        if(B[2]) {
            i=min(B[2],p4);
            r+=2*i;
            B[2]-=i,p4-=i;
            continue;
        }
        if(B[1]) {
            i=min(B[1],p4);
            r+=3*i;
            B[1]-=i,p4-=i;
            continue;
        }
    }
    while(p3) {
        if(r>=ma) return r;
        if(B[4]) {
            i=min(B[4],p3);
            B[4]-=i,p3-=i;
            continue;
        }
        if(B[3]) {
            i=min(B[3],p3);
            B[3]-=i,p3-=i;
            continue;
        }
        if(B[2]) {
            i=min(B[2],p3);
            r+=i;
            B[2]-=i,p3-=i;
            continue;
        }
        if(B[1]) {
            i=min(B[1],p3);
            r+=2*i;
            B[1]-=i,p3-=i;
            continue;
        }
    }
    return r;
    
}

void solve() {
    int f,i,j,k,l,r, x,y;
    
    cin>>N;
    FOR(i,N) A[GETi()]++;
    int tot=A[1]+A[2]*2+A[3]*3+A[4]*4;
    if(tot<3 || tot==5) return _P("-1\n");
    
    int ma=1<<30;
    FOR(i,5) if((tot-i*3)%4==0) break;
    for(;i<=min(N+1,tot/3+1);i+=4) {
        x=(tot-i*3)/4;
        if(x<0 || i+x>N) continue;
        ma=min(ma,dodo(x,i,ma));
    }
    cout << ma << endl;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}