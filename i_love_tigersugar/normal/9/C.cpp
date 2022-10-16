#include<cstdio>
typedef long long ll;
struct num {
    int nd;
    int d[20];
    num(){
        nd=0;
    }
    num(ll x) {
        nd=0;
        while (x>0) {
            nd++;
            d[nd-1]=x%10;
            x=x/10;
        }
    }
};
int cnt;
int x[20];
ll n;
num tmp;
int nd;
void init(void) {
    scanf("%I64d",&n);
    tmp=num(n);
    nd=tmp.nd;
    cnt=0;
}
bool cmp(void) {
    int i;
    for (i=nd-1;i>=0;i=i-1) {
        if (x[i]>tmp.d[i]) return (false);
        if (x[i]<tmp.d[i]) return (true);
    }
    return (true);
}
void backtrack(int k) {
    int i;
    for (i=0;i<2;i=i+1) {
        x[k]=i;
        if (k==nd-1) cnt+=cmp();
        else backtrack(k+1);
    }
}
int main(void) {
    init();
    backtrack(0);
    printf("%d",cnt-1);
    return 0;
}