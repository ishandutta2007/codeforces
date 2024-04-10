#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<min(n-1,abs(a-b)+m)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}