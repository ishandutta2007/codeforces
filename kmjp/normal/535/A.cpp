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

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>x;
    if(x==0) _P("zero\n");
    else if(x==1) _P("one\n");
    else if(x==2) _P("two\n");
    else if(x==3) _P("three\n");
    else if(x==4) _P("four\n");
    else if(x==5) _P("five\n");
    else if(x==6) _P("six\n");
    else if(x==7) _P("seven\n");
    else if(x==8) _P("eight\n");
    else if(x==9) _P("nine\n");
    else if(x==10) _P("ten\n");
    else if(x==11) _P("eleven\n");
    else if(x==12) _P("twelve\n");
    else if(x==13) _P("thirteen\n");
    else if(x==14) _P("fourteen\n");
    else if(x==15) _P("fifteen\n");
    else if(x==16) _P("sixteen\n");
    else if(x==17) _P("seventeen\n");
    else if(x==18) _P("eighteen\n");
    else if(x==19) _P("nineteen\n");
    else {
        if(x/10==2) _P("twenty");
        if(x/10==3) _P("thirty");
        if(x/10==4) _P("forty");
        if(x/10==5) _P("fifty");
        if(x/10==6) _P("sixty");
        if(x/10==7) _P("seventy");
        if(x/10==8) _P("eighty");
        if(x/10==9) _P("ninety");
        if(x%10==0) _P("\n");
        if(x%10==1) _P("-one\n");
        if(x%10==2) _P("-two\n");
        if(x%10==3) _P("-three\n");
        if(x%10==4) _P("-four\n");
        if(x%10==5) _P("-five\n");
        if(x%10==6) _P("-six\n");
        if(x%10==7) _P("-seven\n");
        if(x%10==8) _P("-eight\n");
        if(x%10==9) _P("-nine\n");
        
    }
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}