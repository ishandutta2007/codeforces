#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n,m;
ll a[N],q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
    while(m--){
        cin>>q;
        int id=lower_bound(a+1,a+n+1,q)-a;
        cout<<id<<' '<<q-a[id-1]<<endl;
    }
    return 0;
}