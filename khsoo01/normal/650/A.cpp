#include<cstdio>
#include<algorithm>
using namespace std;
long long n,cnt,ans;

struct man {
    long long x,y;
}a[200005];

bool comp1(man A,man B) {
    return A.x<B.x;
}

bool comp2(man A,man B) {
    if(A.y==B.y) return A.x<B.x;
    return A.y<B.y;
}

int main()
{
    long long i,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a,a+n,comp1);
    cnt = 1;
    for(i=1;i<n;i++) {
        if(a[i].x==a[i-1].x) {
            cnt++; continue;
        }
        if(cnt!=1) ans+=cnt*(cnt-1)/2;
        cnt = 1;
    }
    if(cnt!=1) ans+=cnt*(cnt-1)/2;
    cnt=1;
    sort(a,a+n,comp2);
    for(i=1;i<n;i++) {
        if(a[i].y==a[i-1].y) {
            cnt++; continue;
        }
        if(cnt!=1) ans+=cnt*(cnt-1)/2;
        cnt = 1;
    }
    if(cnt!=1) ans+=cnt*(cnt-1)/2;
    cnt=1;
    for(i=1;i<n;i++) {
        if(a[i].x==a[i-1].x && a[i].y==a[i-1].y) {
            cnt++; continue;
        }
        if(cnt!=1) ans-=cnt*(cnt-1)/2;
        cnt = 1;
    }
    if(cnt!=1) ans-=cnt*(cnt-1)/2;
    printf("%lld",ans);
}