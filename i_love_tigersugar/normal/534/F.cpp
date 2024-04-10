#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
vector<int> haveMask[11];
bool canVisit[21][15][11][11][11][11][11];
unsigned char trace[21][15][11][11][11][11][11];
int reqRow[22],reqCol[22],res[22];
int m,n;
int countSeg(int mask,int n) {
    int res=0;
    REP(i,n) if (BIT(mask,i) && (i==0 || !BIT(mask,i-1))) res++;
    return (res);
}
void init(void) {
    scanf("%d%d",&m,&n);
    REP(i,m) scanf("%d",&reqRow[i]);
    FOR(i,1,n) scanf("%d",&reqCol[i]);
    REP(i,MASK(m)) haveMask[countSeg(i,m)].push_back(i);
}
void optimize(void) {
    canVisit[0][0][0][0][0][0][0]=true;
    REP(col,n) REP(last,haveMask[reqCol[col]].size())
        REP(num0,reqRow[0]+1) REP(num1,reqRow[1]+1) REP(num2,reqRow[2]+1) REP(num3,reqRow[3]+1) REP(num4,reqRow[4]+1)
            if (canVisit[col][last][num0][num1][num2][num3][num4]) REP(next,haveMask[reqCol[col+1]].size()) {
                //print("From %d | %d | %d %d %d %d %d\n",col,haveMask[reqCol[col]])
                int tmp0=num0+(BIT(haveMask[reqCol[col+1]][next],0) && !BIT(haveMask[reqCol[col]][last],0));
                int tmp1=num1+(BIT(haveMask[reqCol[col+1]][next],1) && !BIT(haveMask[reqCol[col]][last],1));
                int tmp2=num2+(BIT(haveMask[reqCol[col+1]][next],2) && !BIT(haveMask[reqCol[col]][last],2));
                int tmp3=num3+(BIT(haveMask[reqCol[col+1]][next],3) && !BIT(haveMask[reqCol[col]][last],3));
                int tmp4=num4+(BIT(haveMask[reqCol[col+1]][next],4) && !BIT(haveMask[reqCol[col]][last],4));
                if (tmp0>reqRow[0]) continue;
                if (tmp1>reqRow[1]) continue;
                if (tmp2>reqRow[2]) continue;
                if (tmp3>reqRow[3]) continue;
                if (tmp4>reqRow[4]) continue;
                canVisit[col+1][next][tmp0][tmp1][tmp2][tmp3][tmp4]=true;
                trace[col+1][next][tmp0][tmp1][tmp2][tmp3][tmp4]=last;
            }
}
void findSolution(void) {
    int curCol=n;
    int curMask=-1;
    int tmp0=reqRow[0];
    int tmp1=reqRow[1];
    int tmp2=reqRow[2];
    int tmp3=reqRow[3];
    int tmp4=reqRow[4];
    REP(i,haveMask[reqCol[n]].size()) if (canVisit[n][i][tmp0][tmp1][tmp2][tmp3][tmp4]) curMask=i;
    assert(curMask>=0);
    while (curCol>0) {
        //printf("Col: %d | Mask: %d | %d %d %d %d %d\n",curCol,haveMask[reqCol[curCol]][curMask],tmp0,tmp1,tmp2,tmp3,tmp4);
        assert(canVisit[curCol][curMask][tmp0][tmp1][tmp2][tmp3][tmp4]);
        res[curCol]=haveMask[reqCol[curCol]][curMask];
        int prevMask=trace[curCol][curMask][tmp0][tmp1][tmp2][tmp3][tmp4];
        tmp0-=BIT(haveMask[reqCol[curCol]][curMask],0) && !BIT(haveMask[reqCol[curCol-1]][prevMask],0);
        tmp1-=BIT(haveMask[reqCol[curCol]][curMask],1) && !BIT(haveMask[reqCol[curCol-1]][prevMask],1);
        tmp2-=BIT(haveMask[reqCol[curCol]][curMask],2) && !BIT(haveMask[reqCol[curCol-1]][prevMask],2);
        tmp3-=BIT(haveMask[reqCol[curCol]][curMask],3) && !BIT(haveMask[reqCol[curCol-1]][prevMask],3);
        tmp4-=BIT(haveMask[reqCol[curCol]][curMask],4) && !BIT(haveMask[reqCol[curCol-1]][prevMask],4);
        curCol--;
        curMask=prevMask;
    }
    REP(i,m) {
        FOR(j,1,n) printf("%c",BIT(res[j],i)?'*':'.');
        printf("\n");
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    optimize();
    findSolution();
    return 0;
}