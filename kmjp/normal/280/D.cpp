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

const int NV=1<<17,KK=22;
int neg[NV*2];
int val[4][NV*2][2][2];
int LL[4][NV*2][2][2];
int RR[4][NV*2][2][2];
int N,M;

void update_val(int entry, int t) {
    int (&v)[2][2]=val[t][entry], (&c0)[2][2]=val[t][entry*2], (&c1)[2][2]=val[t][entry*2+1];
    int (&L)[2][2]=LL[t][entry], (&L0)[2][2]=LL[t][entry*2], (&L1)[2][2]=LL[t][entry*2+1];
    int (&R)[2][2]=RR[t][entry], (&R0)[2][2]=RR[t][entry*2], (&R1)[2][2]=RR[t][entry*2+1];
    
    v[0][0]=v[0][1]=v[1][0]=v[1][1]=-100000000;
    if(v[1][1]<c0[1][1]+c1[1][1]) v[1][1]=c0[1][1]+c1[1][1], L[1][1]=L0[1][1], R[1][1]=R1[1][1];
    
    if(v[1][0]<c0[1][0])          v[1][0]=c0[1][0],          L[1][0]=L0[1][0], R[1][0]=R0[1][0];
    if(v[1][0]<c0[1][1])          v[1][0]=c0[1][1],          L[1][0]=L0[1][1], R[1][0]=R0[1][1];
    if(v[1][0]<c0[1][1]+c1[1][0]) v[1][0]=c0[1][1]+c1[1][0], L[1][0]=L0[1][1], R[1][0]=R1[1][0];
    
    if(v[0][1]<c1[0][1])          v[0][1]=c1[0][1],          L[0][1]=L1[0][1], R[0][1]=R1[0][1];
    if(v[0][1]<c1[1][1])          v[0][1]=c1[1][1],          L[0][1]=L1[1][1], R[0][1]=R1[1][1];
    if(v[0][1]<c0[0][1]+c1[1][1]) v[0][1]=c0[0][1]+c1[1][1], L[0][1]=L0[0][1], R[0][1]=R1[1][1];
    
    if(v[0][0]<c0[0][0])          v[0][0]=c0[0][0],          L[0][0]=L0[0][0], R[0][0]=R0[0][0];
    if(v[0][0]<c0[0][1])          v[0][0]=c0[0][1],          L[0][0]=L0[0][1], R[0][0]=R0[0][1];
    if(v[0][0]<c1[0][0])          v[0][0]=c1[0][0],          L[0][0]=L1[0][0], R[0][0]=R1[0][0];
    if(v[0][0]<c1[1][0])          v[0][0]=c1[1][0],          L[0][0]=L1[1][0], R[0][0]=R1[1][0];
    if(v[0][0]<c0[0][1]+c1[1][0]) v[0][0]=c0[0][1]+c1[1][0], L[0][0]=L0[0][1], R[0][0]=R1[1][0];
}

void getval(int x,int y,int l,int r,int k) {
    int m=(l+r)/2;
    if(r<=x || y<=l) return;
    if(x<=l && y>=r && neg[k]>=0) {
        memmove(val[2][k],val[neg[k]][k],sizeof(val[2][k]));
        memmove(LL[2][k],LL[neg[k]][k],sizeof(LL[2][k]));
        memmove(RR[2][k],RR[neg[k]][k],sizeof(RR[2][k]));
        return;
    }
    
    if(neg[k]>-1) neg[k*2]=neg[k*2+1]=neg[k], neg[k]=-1;
    
    if(y<=m) {
        getval(x,y,l,m,k*2);
        memmove(val[2][k],val[2][k*2],sizeof(val[2][k]));
        memmove(LL[2][k],LL[2][k*2],sizeof(LL[2][k]));
        memmove(RR[2][k],RR[2][k*2],sizeof(RR[2][k]));
        return;
    }
    if(x>=m) {
        getval(x,y,m,r,k*2+1);
        memmove(val[2][k],val[2][k*2+1],sizeof(val[2][k]));
        memmove(LL[2][k],LL[2][k*2+1],sizeof(LL[2][k]));
        memmove(RR[2][k],RR[2][k*2+1],sizeof(RR[2][k]));
        return;
    }
    getval(x,y,l,m,k*2);
    getval(x,y,m,r,k*2+1);
    update_val(k,2);
}

void negateseg(int x,int y,int l,int r,int k) {
    int m=(l+r)/2;
    if(r<=x || y<=l) return;
    if(x<=l && y>=r && neg[k]>=0) {
        neg[k]^=1;
        return;
    }
    
    if(neg[k]>-1) neg[k*2]=neg[k*2+1]=neg[k], neg[k]=-1;
    negateseg(x,y,l,m,k*2);
    negateseg(x,y,m,r,k*2+1);
}

void update(int t, int entry,  int v) {
    int x,y,ma=1;
    entry += NV;
    
    val[t][entry][0][0]=val[t][entry][0][1]=val[t][entry][1][0]=-100000000;
    val[t][entry][1][1]=v;
    LL[t][entry][1][1]=entry-NV;
    RR[t][entry][1][1]=entry-NV+1;
    
    while(entry>1) {
        entry>>=1;
        update_val(entry,t);
    }
}



void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    
    FOR(i,NV*2) val[0][i][0][0]=val[0][i][0][1]=val[0][i][1][0]=val[0][i][1][1]=-100000000;
    FOR(i,NV*2) val[1][i][0][0]=val[1][i][0][1]=val[1][i][1][0]=val[1][i][1][1]=-100000000;
    FOR(i,N) {
        cin>>r;
        update(0,i+1,r);
        update(1,i+1,-r);
    }
    
    cin>>M;
    while(M--) {
        cin>>x>>l>>r;
        if(x==0) {
            update(0,l,r);
            update(1,l,-r);
        }
        else {
            cin>>k;
            int ret=0, ma=1;
            neg[1]=0;
            while(k-->0) {
                getval(l,r+1,0,NV,1);
                int ma=0;
                int l2=NV,r2=0;
                if(ma<val[2][1][0][0]) ma=val[2][1][0][0], l2=LL[2][1][0][0], r2=RR[2][1][0][0];
                if(ma<val[2][1][0][1]) ma=val[2][1][0][1], l2=LL[2][1][0][1], r2=RR[2][1][0][1];
                if(ma<val[2][1][1][0]) ma=val[2][1][1][0], l2=LL[2][1][1][0], r2=RR[2][1][1][0];
                if(ma<val[2][1][1][1]) ma=val[2][1][1][1], l2=LL[2][1][1][1], r2=RR[2][1][1][1];
                if(ma<=0) break;
                ret+=ma;
                negateseg(l2,r2,0,NV,1);
            }
            cout << ret << endl;
        }
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}