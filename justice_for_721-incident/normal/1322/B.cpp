#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[400001];
int b[400001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	ll ans=0;
	for(int i=1; i<=25 ;i++){
		for(int j=1; j<=n ;j++){
			b[j]=a[j]%(1<<i);
		}
		sort(b+1,b+n+1);
		int cur=0;
		for(int j=1; j<=n ;j++){
			int l=lower_bound(b+1,b+n+1,(1<<(i-1))-b[j])-b;
			l=max(l,j+1);
			int r=lower_bound(b+1,b+n+1,(1<<i)-b[j])-b;
			r=max(r,l);
			cur^=(r-l)%2;
		}
		for(int j=1; j<=n ;j++){
			int l=lower_bound(b+1,b+n+1,(1<<(i-1))+(1<<i)-b[j])-b;
			l=max(l,j+1);
			int r=n+1;
			r=max(r,l);
			cur^=(r-l)%2;
		}
		if(cur) ans|=(1<<(i-1));
	}
	cout << ans << endl;
}