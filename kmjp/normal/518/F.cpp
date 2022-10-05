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

int H,W;
string A[2020];
int SV[2020][2020];
int SH[2020][2020];

ll ret;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H>>W;
    FOR(y,H) cin>>A[y];
    A[0][0]=A[H-1][W-1]=A[H-1][0]=A[0][W-1]='#';
    //FOR(y,H) cout<<A[y]<<endl;
    
    FOR(y,H) FOR(x,W) {
        SV[y+1][x+1]=SV[y][x+1]+(A[y][x]=='#');
        SH[y+1][x+1]=SH[y+1][x]+(A[y][x]=='#');
    }
    
    for(y=1;y<H-1;y++) if(SH[y+1][W]-SH[y+1][0]==0) ret++;
    for(x=1;x<W-1;x++) if(SV[H][x+1]-SV[0][x+1]==0) ret++;
    
    for(y=1;y<H-1;y++) for(x=1;x<W-1;x++) {
        if(SH[y+1][x+1]-SH[y+1][0]==0 && SV[y+1][x+1]-SV[0][x+1]==0) ret++;
        if(SH[y+1][x+1]-SH[y+1][0]==0 && SV[H][x+1]-SV[y][x+1]==0) ret++;
        if(SH[y+1][W]-SH[y+1][x]==0 && SV[y+1][x+1]-SV[0][x+1]==0) ret++;
        if(SH[y+1][W]-SH[y+1][x]==0 && SV[H][x+1]-SV[y][x+1]==0) ret++;
    }
    for(y=1;y<H-1;y++) {
        int s[2][2020]={};
        int su[2][2020]={};
        for(x=1;x<W-1;x++) {
            if(SV[y+1][x+1]-SV[0][x+1]==0) s[0][x]=1;
            if(SV[H][x+1]-SV[y][x+1]==0) s[1][x]=1;
            if(A[y][x]=='.') {
                if(A[y][x-1]=='.') {
                    if(s[0][x]) ret+=su[1][x-1];
                    if(s[0][x]&& x>=2) ret+=su[0][x-2];
                    if(s[1][x]) ret+=su[0][x-1];
                    if(s[1][x]&& x>=2) ret+=su[1][x-2];
                }
                su[0][x]=su[0][x-1]+s[0][x];
                su[1][x]=su[1][x-1]+s[1][x];
            }
        }
    }
    for(x=1;x<W-1;x++) {
        int s[2][2020]={};
        int su[2][2020]={};
        for(y=1;y<H-1;y++) {
            if(SH[y+1][x+1]-SH[y+1][0]==0) s[0][y]=1;
            if(SH[y+1][W]-SH[y+1][x]==0) s[1][y]=1;
            if(A[y][x]=='.') {
                if(A[y-1][x]=='.') {
                    if(s[0][y]) ret+=su[1][y-1];
                    if(s[0][y]&& y>=2) ret+=su[0][y-2];
                    if(s[1][y]) ret+=su[0][y-1];
                    if(s[1][y]&& y>=2) ret+=su[1][y-2];
                }
                su[0][y]=su[0][y-1]+s[0][y];
                su[1][y]=su[1][y-1]+s[1][y];
            }
        }
    }
    
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}