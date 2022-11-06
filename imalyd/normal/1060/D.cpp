//Problem D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100007;
int n,a[N],b[N];
ll s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)s+=max(a[i],b[i]);
    cout<<s+n;
    return 0;
}