#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X1[100050],X2[100050],Y1[100050],Y2[100050];
int A[3005][3005],ID[3005][3005],S[3005][3005];
int ngv[3005][3005],ngh[3005][3005];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    MINUS(ID);
    FOR(i,N) {
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
        X1[i]++;Y1[i]++;X2[i]++;Y2[i]++;
        FOR(x,X2[i]-X1[i]) FOR(y,Y2[i]-Y1[i]) A[y+Y1[i]][x+X1[i]]=1, ID[y+Y1[i]][x+X1[i]]=i;
    }
    FOR(y,3003) {
        FOR(x,3003) S[y+1][x+1]=S[y+1][x]+A[y][x];
        FOR(x,3003) S[y+1][x+1]+=S[y][x+1];
    }
    FOR(y,3003) FOR(x,3003) ngh[y][x]=(x?ngh[y][x-1]:0)+(ID[y][x]==ID[y+1][x] && ID[y][x]!=-1);
    FOR(y,3003) FOR(x,3003) ngv[y][x]=(y?ngv[y-1][x]:0)+(ID[y][x]==ID[y][x+1] && ID[y][x]!=-1);
    
    FOR(i,N) {
        for(int w=1;;w++) {
            if(S[Y1[i]+w][X1[i]+w]-S[Y1[i]+w][X1[i]]-S[Y1[i]][X1[i]+w]+S[Y1[i]][X1[i]]<w*w) break;
            int ng=0;
            if(ngv[Y1[i]-1][X1[i]-1]!=ngv[Y1[i]+w-1][X1[i]-1]) break;
            if(ngh[Y1[i]-1][X1[i]-1]!=ngh[Y1[i]-1][X1[i]+w-1]) break;
            if(ngv[Y1[i]-1][X1[i]+w-1]!=ngv[Y1[i]+w-1][X1[i]+w-1]) continue;
            if(ngh[Y1[i]+w-1][X1[i]-1]!=ngh[Y1[i]+w-1][X1[i]+w-1]) continue;
            
            set<int> S;
            FOR(x,w) FOR(y,w) S.insert(ID[Y1[i]+y][X1[i]+x]+1);
            _P("YES %d\n",S.size());
            ITR(s,S) _P("%d ",*s);
            _P("\n");
            return;
        }
    }
    _P("NO\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}