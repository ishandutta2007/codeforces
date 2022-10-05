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

int N;
string S,T;
int id[256][256],id2[256];
pair<int,int> sw;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>S>>T;
    MINUS(id);
    MINUS(id2);
    sw.first=sw.second=-1;
    FOR(i,N) if(S[i]!=T[i]) {
        if(id[T[i]][S[i]]>=0) {
            sw.first=id[T[i]][S[i]]+1;
            sw.second=i+1;
            swap(T[i],T[id[T[i]][S[i]]]);
            goto hoge;
        }
        id[S[i]][T[i]] = id2[T[i]]=i;
    }
    FOR(i,N) if(S[i]!=T[i]) {
        if(id2[S[i]]>=0) {
            sw.first=id2[S[i]]+1;
            sw.second=i+1;
            swap(T[i],T[id2[S[i]]]);
            goto hoge;
        }
    }
    hoge:
    x=0;
    FOR(i,N) x+=S[i]!=T[i];
    _P("%d\n%d %d\n",x,sw.first,sw.second);
    
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}