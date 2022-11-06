#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>arr(300005);
int n,q,mod;
int cnt = 0;
void update(int i, int val){
	if(i>n)return;
	if(arr[i]==0)cnt--;
	arr[i]+=val;
	arr[i]%=mod;
	arr[i]+=mod;
	arr[i]%=mod;
	if(arr[i]==0)cnt++;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q >> mod;
	vector<int>fib(n+1);
	fib[2] = fib[1] = 1;
	for(int i = 3; i<=n; i++){
		fib[i] = fib[i-2]+fib[i-1];
		fib[i]%=mod;
	}
	
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		arr[i]-=x;
		arr[i]%=mod; arr[i]+=mod; arr[i]%=mod;
	}
	for(int i = n; i>=2; i--){
		arr[i]-=arr[i-1];
		arr[i]-=arr[i-2];
		arr[i]%=mod; arr[i]+=mod; arr[i]%=mod;
	}

	for(int i = 1; i<=n; i++){
		if(arr[i]==0)cnt++;
	}
	while(q--){
		char ch;
		cin >> ch;
		int l,r;
		cin >> l >> r;
		if(ch=='A'){
			update(l,1);
			update(r+1,-1*fib[r-l+2]);
			update(r+2,-1*fib[r-l+1]);
		}
		else{
			update(l,-1);
			update(r+1,fib[r-l+2]);
			update(r+2,fib[r-l+1]);
		}
		if(cnt==n)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}