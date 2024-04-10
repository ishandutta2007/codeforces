#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
    ll a,b;
    cin>>a>>b;
    ll ans=min(a,b);
    ans=min(ans,(a+b)/4);
    cout<<ans<<endl;
}
	return 0;
}