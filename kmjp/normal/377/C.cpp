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

int N,M;
ll S[1001];
string cm[100];
int ct[100];

ll dpdp[2][1<<21];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>S[i];
    cin>>M;
    
    sort(S,S+N);
    reverse(S,S+N);
    
    FOR(j,1<<M) dpdp[0][j]=-1LL<<60;
    dpdp[0][0]=0;
    FOR(i,M) cin>>cm[M-1-i]>>ct[M-1-i];
    FOR(i,M) {
        int cur=i%2,tar=cur^1;
        
        FOR(j,1<<M) dpdp[tar][j]=-1LL<<60;
        
        FOR(j,1<<M) {
            if(dpdp[cur][j]==-1LL<<60) continue;
            FOR(x,M) if((j&(1<<x))==0) {
                ll mm = dpdp[tar][j|(1<<x)];
                if(ct[i]==1) {
                    if(cm[i][0]=='p') mm=max(mm,dpdp[cur][j] + S[x]);
                    else mm=max(mm,dpdp[cur][j]);
                }
                else if(ct[i]==2) {
                    if(mm==-1LL<<60) mm=1LL<<60;
                    if(cm[i][0]=='p') mm=min(mm,dpdp[cur][j] - S[x]);
                    else mm=min(mm,dpdp[cur][j]);
                }
                dpdp[tar][j|(1<<x)] = mm;
            }
        }
    }
    
    ll ret=-1LL<<60;
    FOR(i,1<<M) ret=max(ret,dpdp[M%2][i]);
    cout << ret << endl;
}


int main(int argc,char** argv){
    string s;
    ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}