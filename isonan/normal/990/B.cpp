#include <cstdio>
#include <iostream>
using namespace std;

long long n,K,a[200001],count[2000001];
int main(){
    cin>>n>>K;
    for(int i=1;i<=n;i++)scanf("%d",a+i),count[a[i]]++;
    for(int i=1;i<=2000000;i++)count[i]+=count[i-1];
    int tot=0;
    for(int i=1;i<=n;i++){
        if(count[a[i]+K]>count[a[i]])tot++;
    }
    cout<<n-tot;
}