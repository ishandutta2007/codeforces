#include<bits/stdc++.h>
#define MAX   5555
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
int n,a[MAX];
int f(int l,int r,int h) {
    if (l>r) return (0);
    if (l==r) return (a[l]>h);
    int id=l;
    FOR(i,l,r) if (a[i]<a[id]) id=i;
    return (min(r-l+1,a[id]-h+f(l,id-1,a[id])+f(id+1,r,a[id])));
}
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    printf("%d",f(1,n,0));
}
int main(void) {
    process();
    return 0;
}