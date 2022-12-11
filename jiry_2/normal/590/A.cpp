#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[510000],n,ans[510000];
int main(){
    scanf("%d",&n); int pre=1;
    for (int i=1;i<=n;i++) scanf("%d",&A[i]);
    memcpy(ans,A,sizeof A); int num=0;
    for (int i=2;i<=n;i++){
        if (A[i]==A[i-1]) {pre=i; continue;}
        if (i==n||A[i]==A[i+1]){
            int l=pre+1,r=i-1; int k1=0;
            while (l<=r){
                k1++; ans[l]=A[pre]; ans[r]=A[i];
                l++; r--;
            }
            num=max(num,k1);
            pre=i+1;
        }
    }
    printf("%d\n",num);
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}