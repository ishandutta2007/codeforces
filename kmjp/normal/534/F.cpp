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

int H,W;
int A[30],B[30];
string S[50];
set<int> cand[5];
int p12[6],tar;
map<pair<int,int>,pair<int,int> > from[21];

int ok(int curv,int c) {
    int i;
    FOR(i,H) {
        int seg=curv/p12[i]%12;
        if(seg>A[i]) return 0;
        if(seg+(W-c)/2+2 < A[i]) return 0;
    }
    return 1;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    p12[0]=1;
    FOR(i,5) p12[i+1]=p12[i]*12;
    
    cin>>H>>W;
    FOR(i,H) cin>>A[i], tar += p12[i]*A[i];
    FOR(i,W) cin>>B[i];
    
    FOR(i,1<<H) {
        x=0;
        FOR(y,10) if((i&(1<<y)) && ((i&(1<<(y+1)))==0)) x++;
        cand[x].insert(i);
    }
    
    from[0][make_pair(0,0)]=make_pair(0,0);
    FOR(i,W) {
        FORR(r,from[i]) {
            FORR(c,cand[B[i]]) {
                x = r.first.first;
                FOR(y,H) if((c&(1<<y)) && ((r.first.second&(1<<y))==0)) x += p12[y];
                if(ok(x,i)) from[i+1][make_pair(x, c)]=r.first;
            }
        }
    }
    
    pair<int,int> goal;
    FORR(r,from[W]) if(r.first.first==tar) goal=r.first;
    
    for(x=W-1;x>=0;x--) {
        FOR(y,H) S[y]+=".*"[(goal.second & (1<<y))>0];
        goal=from[x+1][goal];
    }
    
    FOR(y,H) {
        reverse(S[y].begin(),S[y].end());
        cout<<S[y]<<endl;
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}