#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 312345
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long


vector<int> v;
//interval and bit
int ans(int l,int r,int bit){
	if(bit<0)return 0;
	//primeiro q n eh 0
	int mid=l;
	while(mid<=r && (v[mid]>>bit)%2==0)mid++;
	if(mid==l || mid==r+1)return ans(l,r,bit-1);
	return (1ll<<bit)+min(ans(l,mid-1,bit-1),ans(mid,r,bit-1));
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.pb(x);
	}	
	sort(v.begin(),v.end());
	cout<<ans(0,n-1,30)<<endl;

	
	return 0;
}