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

int tab[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int I[8];
int OX[8][3];
int X[8],Y[8],Z[8];

int okok() {
    ll TX=0,TY=0,TZ=0,LL[8],L2[8][8];
    ll XX[8],YY[8],ZZ[8];
    int i,j;
    
    FOR(i,8) {
        TX+=OX[i][tab[I[i]][0]]*6;
        TY+=OX[i][tab[I[i]][1]]*6;
        TZ+=OX[i][tab[I[i]][2]]*6;
    }
    TX/=8; TY/=8; TZ/=8;
    
    // same len?
    FOR(i,8) {
        XX[i]=OX[i][tab[I[i]][0]]*6-TX;
        YY[i]=OX[i][tab[I[i]][1]]*6-TY;
        ZZ[i]=OX[i][tab[I[i]][2]]*6-TZ;
        LL[i]=XX[i]*XX[i]+YY[i]*YY[i]+ZZ[i]*ZZ[i];
        if(LL[i]!=LL[0]) return 0;
    }
    if(LL[0]==0) return 0;
    
    FOR(i,8) FOR(j,8) {
        L2[i][j]=(XX[j]-XX[i])*(XX[j]-XX[i])+(YY[j]-YY[i])*(YY[j]-YY[i])+(ZZ[j]-ZZ[i])*(ZZ[j]-ZZ[i]);
    }
    
    // dist from V[0]
    vector<int> V1,V2,V3;
    for(i=1;i<8;i++) {
        if(L2[0][i]==LL[0]*4) V3.push_back(i);
        if(L2[0][i]*3==LL[0]*4) V1.push_back(i);
        if(L2[0][i]*3==LL[0]*8) V2.push_back(i);
    }
    if(V1.size()!=3 || V2.size()!=3 || V3.size()!=1) return 0;
    if(L2[V1[0]][V1[1]]!=L2[0][V1[1]]*2) return 0;
    if(L2[V1[1]][V1[2]]!=L2[0][V1[0]]*2) return 0;
    if(L2[V1[0]][V1[2]]!=L2[0][V1[0]]*2) return 0;
    //if(L2[V3[0]][V1[0]]*3!=LL[0]*8) return 0;
    //  if(L2[V3[0]][V1[0]]*3!=LL[0]*8) return 0;
    //  if(L2[V3[0]][V1[0]]*3!=LL[0]*8) return 0;
    if(L2[V2[0]][V2[1]]!=L2[0][V1[1]]*2) return 0;
    if(L2[V2[1]][V2[2]]!=L2[0][V1[0]]*2) return 0;
    if(L2[V2[0]][V2[2]]!=L2[0][V1[0]]*2) return 0;
    
    FOR(i,3) {
        int ok=0;
        if(L2[V1[i]][V2[0]]*3!=LL[0]*4) ok++;
        if(L2[V1[i]][V2[1]]*3!=LL[0]*4) ok++;
        if(L2[V1[i]][V2[2]]*3!=LL[0]*4) ok++;
        if(ok!=1) return 0;
    }
    
    _P("YES\n");
    FOR(i,8) _P("%d %d %d\n",OX[i][tab[I[i]][0]],OX[i][tab[I[i]][1]],OX[i][tab[I[i]][2]]);
    return 1;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    FOR(i,8) cin>>OX[i][0]>>OX[i][1]>>OX[i][2];
    FOR(i,6*6*6*6*6*6*6) {
        j=i;
        FOR(k,7) I[k+1]=j%6, j/=6;
        if(okok()) return;
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