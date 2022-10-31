#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e6+7;
bool del[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		del[i] = 0;
	}
	string s;
	cin>>s;
	ll res = 0;
	for(int i = 1;i<=n;i+=1){
		for(int j = i;j<=n;j+=i){
			if (del[j]){
				continue;
			}
			if (s[j-1]=='0'){
				res += i;
				del[j] = 1;
			}
			else{
				break;
			}
		}
	}
	cout<<res<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}