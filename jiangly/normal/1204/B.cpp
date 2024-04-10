#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l,r;
    cin>>n>>l>>r;
    int ans1=(1<<l)-1+(n-l);
    int ans2=(1<<r)-1+(1<<(r-1))*(n-r);
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}