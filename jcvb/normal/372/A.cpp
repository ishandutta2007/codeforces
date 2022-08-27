#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[500005];
int off[500005],lef;
int main(){
    scanf("%d",&n);lef=n;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int cur=n/2;
    for (int i=n;i>=1;i--){
        if(off[i])continue;
        while(cur && (off[cur]||a[cur]*2>a[i]))cur--;
        if(cur){lef--;off[cur]=1;}
    }
    printf("%d\n",lef);
    return 0;
}