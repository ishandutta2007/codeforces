#include<cstdio>
#include<vector>
#include<cstring>
#define MAX   333
using namespace std;
struct state {
    int d,f,l;
    state(){}
    state(const int &_d,const int &_f,const int &_l) {
        d=_d;f=_f;l=_l;
    }
};
int sp[MAX][5][5];
bool v[MAX];
vector<state> fst;
void reset(void) {
    memset(v,false,sizeof v);
}
int get(void) {
    int i;
    for (i=0;i<MAX;i=i+1)
        if (!v[i]) return (i);
}
void sprague(void) {
    int i,j,k;
    sp[1][0][0]=1;
    sp[1][1][1]=1;
    sp[1][1][2]=1;  
    sp[1][0][2]=1;
    sp[1][2][1]=1;
    sp[1][2][0]=1;
    sp[1][2][2]=1;
    for (i=2;i<=111;i=i+1) {
        //0 0
        reset();
        for (j=1;j<=i;j=j+1) v[sp[j-1][0][0]^sp[i-j][0][0]]=true;
        for (j=2;j<i;j=j+1) v[sp[j-1][0][1]^sp[i-j][1][0]]=true;
        sp[i][0][0]=get();
        //0 1
        reset();
        for (j=1;j<i;j=j+1) v[sp[j-1][0][0]^sp[i-j][0][1]]=true;
        for (j=2;j<=i;j=j+1) v[sp[j-1][0][1]^sp[i-j][1][1]]=true;
        sp[i][0][1]=get();
        //0 2
        reset();
        for (j=1;j<=i;j=j+1) v[sp[j-1][0][0]^sp[i-j][0][2]]=true;
        for (j=2;j<=i;j=j+1) v[sp[j-1][0][1]^sp[i-j][1][2]]=true;
        sp[i][0][2]=get();
        //1 0
        reset();
        for (j=2;j<=i;j=j+1) v[sp[j-1][1][0]^sp[i-j][0][0]]=true;
        for (j=1;j<i;j=j+1) v[sp[j-1][1][1]^sp[i-j][1][0]]=true;
        sp[i][1][0]=get();
        //1 1
        reset();
        for (j=2;j<i;j=j+1) v[sp[j-1][1][0]^sp[i-j][0][1]]=true;
        for (j=1;j<=i;j=j+1) v[sp[j-1][1][1]^sp[i-j][1][1]]=true;
        sp[i][1][1]=get();
        //1 2
        reset();
        for (j=2;j<=i;j=j+1) v[sp[j-1][1][0]^sp[i-j][0][2]]=true;
        for (j=1;j<=i;j=j+1) v[sp[j-1][1][1]^sp[i-j][1][2]]=true;
        sp[i][1][2]=get();
        //2 0
        reset();
        for (j=1;j<=i;j=j+1) v[sp[j-1][2][0]^sp[i-j][0][0]]=true;
        for (j=1;j<i;j=j+1) v[sp[j-1][2][1]^sp[i-j][1][0]]=true;
        sp[i][2][0]=get();
        //2 1
        reset();
        for (j=1;j<i;j=j+1) v[sp[j-1][2][0]^sp[i-j][0][1]]=true;
        for (j=1;j<=i;j=j+1) v[sp[j-1][2][1]^sp[i-j][1][1]]=true;
        sp[i][2][1]=get();
        //2 2
        reset();
        for (j=1;j<=i;j=j+1) v[sp[j-1][2][0]^sp[i-j][0][2]]=true;
        for (j=1;j<=i;j=j+1) v[sp[j-1][2][1]^sp[i-j][1][2]]=true;
        sp[i][2][2]=get();
    }
/*  for (j=0;j<3;j=j+1)
        for (k=0;k<3;k=k+1)
            printf("sp(2,%d,%d)=%d\n",j,k,sp[2][j][k]);*/
}
int n,r;
bool brd[MAX][4];
void init() {
    scanf("%d",&r);
    scanf("%d",&n);
    int i,x,y,j;
    for (i=1;i<=r;i=i+1) {
        brd[i][1]=true;
        brd[i][2]=true;
    }
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&x);
        scanf("%d",&y);
        brd[x][y]=false;
        for (j=-1;j<=1;j=j+1)
            brd[x+j][3-y]=false;
    }
    brd[r+1][1]=false;
    brd[r+1][2]=false;
    brd[0][1]=false;
    brd[0][2]=false;
    int f,l,sf,sl;
    fst.clear();
    for (i=1;i<=r+1;i=i+1) {
        if (brd[i][1]||brd[i][2]) {
            if (brd[i-1][1] || brd[i-1][2]) continue;
            f=i;
            if (brd[i][1] && brd[i][2]) sf=2;
            else if (brd[i][1]) sf=0;
            else sf=1;
        }   
        else {
            if (!brd[i-1][1] && !brd[i-1][2]) continue;
            else {
                l=i-1;
                if (brd[i-1][1] && brd[i-1][2]) sl=2;
                else if (brd[i-1][1]) sl=0;
                else sl=1;
                //printf("Push property %d %d %d %d\n",f,l,sf,sl);
                fst.push_back(state(l-f+1,sf,sl));
            }                       
        }
    }
    int rsp=0;
    for (i=0;i<fst.size();i=i+1)
        rsp=rsp^sp[fst[i].d][fst[i].f][fst[i].l];   
    //for (i=0;i<fst.size();i=i+1) printf("%d %d %d\n",fst[i].d,fst[i].f,fst[i].l);
    if (rsp==0) printf("LOSE");
    else printf("WIN"); 
}
int main(void) {
    sprague();
    init();
    return 0;
}