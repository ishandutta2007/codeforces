#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=105;
int a[maxn];
int main(){
    int i,j,n;
    int t,cnt;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&t); a[t]=1;
    }
    cnt=0;
    for (i=0;i<maxn;i++) if (a[i]){
        cnt++;
        for (j=i;j<maxn;j+=i) a[j]=0;
    }
    printf("%d\n",cnt);
    return 0;
}