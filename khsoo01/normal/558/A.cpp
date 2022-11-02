#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,tmp[2],sum;
struct apple{
    int idx,val;
}appl[105],appr[105];
int lcnt,rcnt;
bool comp(apple A,apple B){return abs(A.idx)<abs(B.idx);}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d%d",&tmp[0],&tmp[1]);
        if(tmp[0]<0) {
            appl[lcnt].idx=tmp[0];
            appl[lcnt].val=tmp[1];
            lcnt++;
        }
        else {
            appr[rcnt].idx=tmp[0];
            appr[rcnt].val=tmp[1];
            rcnt++;
        }
        sum+=tmp[1];
    }
    sort(appl,appl+lcnt,comp);
    sort(appr,appr+rcnt,comp);
    if(lcnt>rcnt) {
        sum=0;
        for(i=0;i<rcnt;i++) {
            sum+=appl[i].val;
            sum+=appr[i].val;
        }
        sum+=appl[rcnt].val;
    }
    if(lcnt<rcnt) {
        sum=0;
        for(i=0;i<lcnt;i++){
            sum+=appl[i].val;
            sum+=appr[i].val;
        }
        sum+=appr[lcnt].val;
    }
    printf("%d",sum);
}