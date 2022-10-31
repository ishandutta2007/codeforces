#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
int s[N];
void solve(){
	int n,k;
	cin>>n>>k;
	if (k==1){
		int last;
		cin>>last;
		cout<<"YES\n";
		return;
	}
	for(int i = 1;i<=k;i+=1){
		cin>>s[i];
	}
	int frs = s[2]-s[1];
	for(int i = 2;i<k;i+=1){
		if (s[i]-s[i-1]>s[i+1]-s[i]){
			cout<<"NO\n";
			return;
		}
	}
	ll last = s[1]/(n-k+1);
	while (last*(n-k+1)<s[1]){
		last += 1;
	}
	while ((last-1)*(n-k+1)>=s[1]){
		last -= 1;
	}
	if (last<=frs){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}

}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	for(int tt = 1;tt<=t;tt+=1){
		solve();
	}
}