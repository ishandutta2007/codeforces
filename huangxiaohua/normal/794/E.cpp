#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300050],res[300500],sb,l,r,mx;

int chk1(vector<int> v){
	int ans=-1;
	ans=max(ans,min(v[0],v[1]));
	ans=max(ans,min(v[2],v[1]));
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	a[0]=a[n+1]=1e9;
	if(n&1){
		l=r=(n+1)/2;
		sb=0;
		for(i=n;i>=1;i-=2){
			sb=max(sb,chk1({a[l-1],a[l],a[l+1]}));
			sb=max(sb,chk1({a[r-1],a[r],a[r+1]}));
			l--;r++;
			res[i]=sb;
		}
		
		l=n/2;r=(n+1)/2;
		sb=0;
		for(i=n-1;i>=1;i-=2){
			sb=max(sb,max(a[l],a[l+1]) );
			sb=max(sb,max(a[r],a[r+1]) );
			l--;r++;
			res[i]=sb;
		}
	}
	else{
		l=r=n/2;
		sb=0;
		for(i=n;i>=1;i-=2){
			sb=max(sb,max(a[l],a[l+1]) );
			sb=max(sb,max(a[r],a[r+1]) );
			l--;r++;
			res[i]=sb;
		}
		
		l=n/2;r=l+1;
		sb=0;
		for(i=n-1;i>=1;i-=2){
			sb=max(sb,chk1({a[l-1],a[l],a[l+1]}));
			sb=max(sb,chk1({a[r-1],a[r],a[r+1]}));
			l--;r++;
			res[i]=sb;
		}
	}
	res[1]=mx;
	for(i=n;i>=1;i--){
		cout<<res[i]<<' ';
	}
}