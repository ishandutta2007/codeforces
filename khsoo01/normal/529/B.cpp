#include<cstdio>
#include<algorithm>
using namespace std;
long long i,j,n,a[1005][2],l,c,cc,flag,m=0x7fffffffffffffff,arr[1005][2][1005],cnt[1005][2];

int main()
{
    scanf("%I64d",&n);
    for(i=0;i<n;i++) {
        scanf("%I64d%I64d",&a[i][0],&a[i][1]);
    }
    for(i=0;i<n;i++) {
        l=a[i][0];
        for(j=0;j<n;j++) {
            if(i==j)continue;
            if(a[i][1]<a[j][1]) {
                c++;
                if(a[i][1]<a[j][0]) {flag=1;break;}
                l+=a[j][1];
            }
            else {
                if(a[j][1]<a[j][0] && a[j][0]<=a[i][1]) {
                    c++;
                    cc++;
                    arr[i][0][cnt[i][0]++]=a[j][0]-a[j][1];
                    l+=a[j][1];
                }
                else l+=a[j][0];
            }
        }
        if(!flag){
            if(c>n/2 && c-cc<=n/2){
                sort(arr[i][0],arr[i][0]+cnt[i][0]);
                for(j=0;j<c-n/2;j++) {
                    l+=arr[i][0][j];
                }
                if(m>l*a[i][1]) {m=l*a[i][1];}
            }
            if(m>l*a[i][1] && c<=n/2) {m=l*a[i][1];}
        }
        c=1;
        cc=0;
        flag=0;
        l=a[i][1];
        for(j=0;j<n;j++) {
            if(i==j)continue;
            if(a[i][0]<a[j][1]) {
                c++;
                if(a[i][0]<a[j][0]) {flag=1;break;}
                l+=a[j][1];
            }
            else {
                if(a[j][1]<a[j][0] && a[j][0]<=a[i][0]) {
                    c++;
                    cc++;
                    arr[i][1][cnt[i][1]++]=a[j][0]-a[j][1];
                    l+=a[j][1];
                }
                else l+=a[j][0];
            }
        }
        if(!flag){
            if(c>n/2 && c-cc<=n/2){
                sort(arr[i][1],arr[i][1]+cnt[i][1]);
                for(j=0;j<c-n/2;j++) {
                    l+=arr[i][1][j];
                }
                if(m>l*a[i][0]) {m=l*a[i][0];}
            }
            if(m>l*a[i][0] && c<=n/2) {m=l*a[i][0];}
        }
        c=0;
        cc=0;
        flag=0;
    }
    printf("%I64d",m);
}