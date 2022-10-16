#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a<b;}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    int brk[n+5];
    int ans=n;
    for(int i=0;i<n-1;i++){brk[i]=arr[i+1]-arr[i]-1;}
    sort(brk,brk+n-1,cmp);
    for(int i=0;i<n-k;i++)ans+=brk[i];
    cout<<ans<<endl;
    return 0;
}