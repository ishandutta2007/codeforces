#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll n,a,lust,w,l,r;
int main(){
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>a;
        a+=lust;
        l=min(l,a);
        r=max(r,a);
        lust=a;
    }
    cout<<max(min(l,r)+w-max(l,r)+1,0ll);
    return 0;
}