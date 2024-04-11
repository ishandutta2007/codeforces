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

int X[2],Y[2],T[2];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>X[0]>>Y[0]>>X[1]>>Y[1];
    
    if(X[0]<=X[1]&&Y[0]<=Y[1]) return _P("Polycarp\n");
    if(X[0]+Y[0]<=max(X[1],Y[1])) return _P("Polycarp\n");
    return _P("Vasiliy\n");
    
    while(1) {
        if(X[0]==X[1]) {
            if(X[0]) X[0]--;
            else if(Y[0]) Y[0]--;
        }
        else if(Y[0]==Y[1]) {
            if(Y[0]) Y[0]--;
            else if(X[0]) X[0]--;
        }
        else if(X[0]>X[1]) X[0]--;
        else if(Y[0]>Y[1]) Y[0]--;
        else if(X[0]) X[0]--;
        else if(Y[0]) Y[0]--;
        
        if(X[0]+1==X[1] && Y[0]+1==Y[1]) {
            if(X[1]) X[1]--;
            else if(Y[1]) Y[1]--;
        }
        else {
            X[1]=max(X[1]-1,0);
            Y[1]=max(Y[1]-1,0);
        }
        
        if(X[0]==0 && Y[0]==0) return _P("Polycarp\n");
        if(X[1]==0 && Y[1]==0) return _P("Vasiliy\n");
    }
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}