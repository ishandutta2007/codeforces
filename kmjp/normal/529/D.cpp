#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,T;
int V[30000],R[30000];
int ma,mau,num;
deque<pair<int,int> > Q;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    scanf("%d %d %d",&N,&M,&T);
    
    FOR(i,N) {
        scanf("%d:%d:%d",&x,&y,&r);
        V[i]=x*3600+y*60+r;
    }
    x=0;
    for(i=0;i<=86400;i++) {
        while(Q.size() && Q.front().first==i) Q.pop_front();
        
        while(x<N && V[x]==i) {
            if(Q.size()==M) {
                R[x]=Q.back().second;
                Q.pop_back();
            }
            else {
                R[x]=++mau;
            }
            Q.push_back(make_pair(i+T,R[x]));
            x++;
        }
        ma=max(ma,(int)Q.size());
    }
    if(ma<M) {
        cout<<"No solution"<<endl;
    }
    else {
        cout<<mau<<endl;
        FOR(i,N) cout<<R[i]<<endl;
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}