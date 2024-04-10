#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bit[1000001];
set<int> nums;
map<int,int> comp;
int a[1000000];
ll t[1000000];
void u(int a,ll b){for(;a<=1000000;a+=a&-a)bit[a]+=b;}
ll q(int a){ll b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int main(){
    int n,i;
    ll ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i),nums.insert(a[i]);
    i=1;
    for(int it:nums){
        comp[it]=i++;
    }
    for(i=0;i<n;i++)a[i]=comp[a[i]];
    for(i=n-1;i>=0;i--){
        t[i]=q(a[i]-1);
        u(a[i],1);
    }
    memset(bit,0,sizeof(bit));
    for(i=n-1;i>=0;i--){
        ans+=q(a[i]-1);
        u(a[i],t[i]);
    }
    cout<<ans;
}