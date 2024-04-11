#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,D;
int P[30300];
int ma;
map<int,int> M[30300];
int sk[60300];
int mama[60300];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>D;
    FOR(i,N) cin>>x, P[x]++;
    
    M[D][D]=P[D];
    for(i=D;i<=30000;i++) {
        ITR(it,M[i]) {
            ma=max(ma,it->second);
            x=it->first;
            if(sk[x+10]==i && it->second<=mama[x+10]) continue;
            for(j=-2;j<=2;j++) {
                sk[x*2+j+10]=i;
                mama[x*2+j+10]=it->second;
            }
            
            if(x>1 && i+x-1<=30000) M[i+x-1][x-1]=max(M[i+x-1][x-1], P[i+x-1]+it->second);
            if(i+x<=30000)          M[i+x][x]    =max(M[i+x][x],     P[i+x]+it->second);
            if(i+x+1<=30000)        M[i+x+1][x+1]=max(M[i+x+1][x+1], P[i+x+1]+it->second);
        }
    }
    
    
    cout<<ma<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}