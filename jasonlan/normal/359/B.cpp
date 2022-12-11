#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    n<<=1;
    cout<<k+1<<' ';
    for(int i=2;i<=k+1;++i)cout<<i-1<<' ';
    for(int i=k+2;i<=n;++i)cout<<i<<' ';
    return 0;
}