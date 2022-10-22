#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;
const double eps = 1e-8;

int a[mn];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=INT_MAX;
	auto eval = [&](int l,int r){
		double diff = double(a[r]-a[l])/(r-l);
		int num=0;
		for(int i=0;i<n;i++){
			if(abs(a[i]-(a[l]+(i-l)*diff))>eps)num++;
		}
		return num;
	};
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)ans=min(ans,eval(i,j));
	if(n==1)ans=0;
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