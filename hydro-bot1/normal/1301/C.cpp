// Hydro submission #619f3870a76fd5537b89df2c@1637824624879
#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,m,l,c,T;
 ios::sync_with_stdio(0),cin.tie(0);
 for(cin>>T;T--;cout<<1ll*n*(n+1)/2-1ll*l*(l+1)/2*(m+1-c)-1ll*(l+1)*(l+2)/2*c<<'\n')cin>>n>>m,l=(n-m)/(m+1),c=n-m-l*(m+1);
}