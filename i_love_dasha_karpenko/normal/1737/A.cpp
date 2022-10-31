#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int AL = 26;
int cnt[AL];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i+=1){
		char ch;
		cin>>ch;
		cnt[ch-'a']+=1;
	}
	for(int i = 1;i<=k;i+=1){
		int ans = 0;
		for(int j = 0;j<min(n/k,AL);j+=1){
			if (cnt[j]==0){
				break;
			}
			ans += 1;
			cnt[j] -= 1;
		}
		cout<<char('a'+ans);
	}
	cout<<endl;
	memset(cnt,0,sizeof(cnt));
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}