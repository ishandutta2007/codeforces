#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 4e5+10;
const ll mod = 998244353;

int a[mn],b[mn];

bool eval(int n, int k){
	int j=0;
	for(int i=0;i<n;i++){
		if(b[i]>=j&&a[i]>=k-1-j)j++;
	}
	return j>=k;
}

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	int l=0,r=n+1;
	while(l<r){
		int mid = l+(r-l)/2;
		if(eval(n,mid))l=mid+1;
		else r=mid;
	}
	printf("%d\n",l-1);
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