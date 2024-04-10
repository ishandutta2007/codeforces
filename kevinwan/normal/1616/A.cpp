#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 200+10;

int av[mn];
void solve(){
	int n;
	cin>>n;
	memset(av,0,sizeof(av));
	int x;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>x;
		x=abs(x);
		if(av[x]<2&&x!=0)ans++;
		else if(av[x]<1)ans++;
		av[x]++;
	}
	printf("%d\n",ans);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}