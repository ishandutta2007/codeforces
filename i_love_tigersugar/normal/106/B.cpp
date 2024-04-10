#include<bits/stdc++.h>
#define MAX   111
using namespace std;
int n;
struct comp {
    int sp,ram,hdd,cost;
};
comp a[MAX];
bool od[MAX];
void init(void) {
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&a[i].sp);
        scanf("%d",&a[i].ram);
        scanf("%d",&a[i].hdd);
        scanf("%d",&a[i].cost);
    }
    for (i=1;i<=n;i=i+1) od[i]=false;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=n;j=j+1)
            if (a[i].sp<a[j].sp && a[i].ram<a[j].ram && a[i].hdd<a[j].hdd) od[i]=true;    
    int res=(int)1e9;
    int ir;
    for (i=1;i<=n;i=i+1)
        if (!od[i]) {
            if (res>a[i].cost) {
                res=a[i].cost;
                ir=i;
            }
        }
    printf("%d",ir);
}
int main(void) {
    init();
    return 0;
}