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


int N,M;
ll A[300100],AS[300100];
ll S[300100];
ll F[300100];
ll mo=1000000009;
vector<pair<int,int> > P;
ll sum[300100];

void solve() {
    int f,i,j,k,l,x,y,r;
    cin>>N>>M;
    FOR(i,N) cin>>A[i+1],AS[i+1]=(AS[i]+A[i+1])%mo;
    
    F[1]=F[2]=S[1]=1;
    S[2]=2;
    for(i=3;i<=300005;i++) {
        F[i]=(F[i-1]+F[i-2])%mo;
        S[i]=(S[i-1]+F[i])%mo;
    }
    
    while(M--) {
        cin>>f>>l>>r;
        if(f==1) {
            P.push_back(make_pair(l,r));
            sum[l]=(sum[l]+1)%mo;
            sum[r+1]=(sum[r+1]+mo-F[r+2-l])%mo;
            sum[r+2]=(sum[r+2]+mo-F[r+1-l])%mo;
            if(P.size()>600) {
                for(i=1;i<=300005;i++) {
                    if(i>=2) {
                        sum[i]=(sum[i]+sum[i-1]+sum[i-2]);
                        while(sum[i]>=mo) sum[i]-=mo;
                    }
                    A[i]+=sum[i];
                    if(A[i]>=mo) A[i]-=mo;
                    AS[i]=AS[i-1]+A[i];
                    if(AS[i]>=mo) AS[i]-=mo;
                }
                ZERO(sum);
                P.clear();
            }
        }
        else {
            ll ret=0;
            
            FOR(i,P.size()) {
                f=P[i].first;
                x=max(l,P[i].first);
                y=min(r,P[i].second);
                if(x>y) continue;
                ret+=S[y-f+1];
                ret-=S[x-f];
                if(ret>mo) ret-=mo;
                if(ret<0) ret+=mo;
            }
            
            ret=(mo+(ret+AS[r]-AS[l-1])%mo)%mo;
            cout<<ret<<endl;
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