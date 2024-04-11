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

int N,A[300000];
int state[6][300000];
vector<int> P;

void solve() {
    int f,i,j,k,l,x,y;
    
    P.push_back(0);
    cin>>N;
    FOR(x,N) {
        cin>>A[x+1];
        if(A[x+1]) P.push_back(x+1);
    }
    if(P.size()==1) {
        _P("%d\n",N/2);
        FOR(i,N/2) _P("%d %d ",i+1,i+1);
        if(N%2) _P("%d",N/2);
        _P("\n");
        return;
    }
    
    state[5][0]=1;
    for(i=1;i<P.size();i++) {
        if(A[P[i-1]]>A[P[i]]) return _P("-1\n");
        if(A[P[i-1]]==A[P[i]]) {
            for(x=P[i-1]+1;x<P[i];x++) A[x]=A[P[i]];
            for(y=1;y<=5;y++) if(state[y][P[i-1]] && y+(P[i]-P[i-1])<=5) state[y+(P[i]-P[i-1])][P[i]] |= 1<<y;
        }
        else {
            FOR(x,5) for(y=1;y<=5;y++) {
                l=P[i]-P[i-1]-x-y;
                if(l>=2*(A[P[i]]-A[P[i-1]]-1) && l<=5*(A[P[i]]-A[P[i-1]]-1)) {
                    for(j=1;j<=5;j++) if(state[j][P[i-1]] && x+j>=2 && x+j<=5) state[y][P[i]] |= 1<<(x*6+j);
                }
            }
        }
    }
    
    int r=0;
    for(x=1;x<=5;x++) {
        if(state[x][P.back()]==0) continue;
        y=N-P.back();
        if(x==1 && y==0) continue;
        if(x==1) y--;
        if(x==5 && y==1) continue;
        y=A[P.back()]+y/2;
        if(y>r) l=x,r=y;
    }
    if(r==0) return _P("-1\n");
    _P("%d\n",r);
    x=P.back()+1;
    if(l==1) A[x]=A[x-1],x++;
    if((N-x+1)%2) A[x]=A[x-1],x++;
    while(x<N) A[x]=A[x+1]=A[x-1]+1,x+=2;
    
    for(i=P.size()-1;i>0;i--) {
        if(P[i-1]==P[i]){ l-=P[i]-P[i-1]; continue;}
        FOR(x,l) A[P[i]-x]=A[P[i]];
        //_P("++%x\n",state[l][P[i]]);
        FOR(x,30) if(state[l][P[i]] & (1<<x)) {
            y=x/6;
            FOR(j,y) A[P[i-1]+j+1]=A[P[i-1]];
            for(j=P[i-1]+y+1;j<=P[i]-l;j++) {
                A[j]=A[P[i-1]]+1+ (A[P[i]]-(A[P[i-1]]+1))*(j-(P[i-1]+y))/(P[i]-l+1-(P[i-1]+y));
            }
            l=x%6;
            break;
        }
    }
    FOR(x,N) _P("%d ",A[x+1]);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}