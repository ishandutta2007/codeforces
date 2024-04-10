#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5;
int k[mn+10];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",k+i);
        k[i]+=i;
    }
    sort(k,k+n);
    for(i=0;i<n;i++)k[i]-=i;
    bool fail=0;
    for(i=0;i+1<n;i++)if(k[i+1]<k[i])fail=1;
    if(fail)printf(":(");
    else{
        for(i=0;i<n;i++)printf("%d ",k[i]);
    }
}