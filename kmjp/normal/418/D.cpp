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

int N,M;
vector<int> E[100005];
int P[21][100005];
int up[21][100005];
int down[21][100005];
int D[100005];
vector<int> MD[100005];

void dfs(int cur) {
    MD[cur].push_back(0);
    MD[cur].push_back(0);
    MD[cur].push_back(0);
    FORR(tar,E[cur]) if(tar!=P[0][cur]) {
        D[tar]=D[cur]+1;
        P[0][tar]=cur;
        dfs(tar);
        MD[cur].push_back(MD[tar][0]+1);
    }
    sort(MD[cur].begin(),MD[cur].end());
    reverse(MD[cur].begin(),MD[cur].end());
    MD[cur].resize(3);
}

int getpar(int cur,int up) {
    int i;
    FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
    return cur;
}

int lca(int a,int b) {
    int ret=0,i,aa=a,bb=b;
    if(D[aa]>D[bb]) swap(aa,bb);
    for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
    for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
    return (aa==bb)?aa:P[0][aa];               // vertex
}

int getfar(int cur,int d=-100, bool typeup=true) {
    if(d==-100) d=D[cur];
    if(d<=0) return 0;
    int ret=0;
    int v=cur;
    for(int i=19;i>=0;i--) if(d&(1<<i)) {
        if(typeup) ret=max(ret,up[i][v]+D[cur]-D[v]);
        else ret=max(ret,down[i][v]+D[P[i][v]] - (D[cur]-d));
        v=P[i][v];
    }
    return ret;
}

void solve() {
    int i,j,k,l,r,x,y; string s;

    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0);
    FOR(x,N) down[0][x]=(MD[x][0]+1==MD[P[0][x]][0]?MD[P[0][x]][1]:MD[P[0][x]][0]), up[0][x]=down[0][x]+1;

    FOR(i,19) FOR(x,N) {
        P[i+1][x]=P[i][P[i][x]];
        up[i+1][x]=max(up[i][x], up[i][P[i][x]]+D[x]-D[P[i][x]]);
        down[i+1][x]=max(down[i][P[i][x]],down[i][x] + D[P[i][x]]-D[P[i+1][x]]);
    }

    cin>>M;
    FOR(i,M) {
        cin>>x>>y;
        x--,y--;
        if(D[x]<D[y]) swap(x,y);

        int ca = lca(x,y);
        int dist=D[x]+D[y]-2*D[ca];
        int mid=getpar(x,(dist+1)/2);

        // under x
        int ret=MD[x][0];
        // x to mid
        ret=max(ret,dist/2);
        // x to mid-1
        if(D[x]-D[mid]>=2) ret=max(ret,getfar(x,D[x]-D[mid]-1));
        // y to ca-1
        if(D[y]-D[ca]>=2) ret=max(ret,getfar(y,D[y]-D[ca]-1));
        // over ca
        ret=max(ret,getfar(ca)+D[y]-D[ca]);
        
        int cax = getpar(x,D[x]-D[ca]-1);
        int cay = getpar(y,D[y]-D[ca]-1);
        int mix = getpar(x,D[x]-D[mid]-1);
        
        if(ca==y) {
            // under ca except x->y
            ret=max(ret,(MD[ca][0]==MD[cax][0]+1)?MD[ca][1]:MD[ca][0]);
        }
        else {
            // under y
            ret=max(ret,MD[y][0]);
            // under ca
            int xy[2]={ MD[cax][0]+1,MD[cay][0]+1};
            sort(xy,xy+2);

            j=0;
            if(MD[ca][j]==xy[1]) j++;
            if(MD[ca][j]==xy[0]) j++;
            ret=max(ret,MD[ca][j]+D[y]-D[ca]);
            
        }
        // under mid except x->mid
        if(mid!=ca) ret=max(ret,((MD[mid][0]==MD[mix][0]+1)?MD[mid][1]:MD[mid][0]) + dist/2);
        // mid to ca-1
        if(D[mid]-D[ca]>=2) ret=max(ret,getfar(mid,D[mid]-D[ca]-1,false)+1+D[y]-D[ca]);
        
        cout<<ret<<endl;
    }

}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}