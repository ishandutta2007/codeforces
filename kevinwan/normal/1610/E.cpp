#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 2e5+10;

ll a[mn];
int uni[mn];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int ans=0;
	int tot=0;
	uni[n-1]=n-1;
	for(int i=n-2;i>=0;i--){
		uni[i]=i;
		if(a[i]==a[i+1])uni[i]=uni[i+1];
	}
	for(int i=0;i<n;i++){
		int num=uni[i]-i;
		i=uni[i];
		int cur=i;
		while(cur<n){
			++num;
			cur=lower_bound(a+cur+1,a+n,2*a[cur]-a[i])-a;
		}
		ans=max(ans,num);
	}
	cerr<<tot<<endl;
	printf("%d\n",n-ans);
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