#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	printf("%d\n",int(n>1)+int(m>1));
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}