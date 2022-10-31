#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],res,t1,t2,t3,n1,n2;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,n*4+50);
		for(i=1;i<=n;i++){
			cin>>k;a[k]++;
		}
		for(i=1;i<=n;i++){
			a[i]+=a[i-1];
		}
		res=2e9;
		for(t1=1;t1<=n+n;t1<<=1){
			for(t2=1;t2<=n+n;t2<<=1){
				n1=0;n2=n+1;
				for(i=1;i<=n;i++){
					if(a[i]<=t1)n1=i;
				}
				for(i=n;i>=1;i--){
					if(a[n]-a[i-1]<=t2)n2=i;
				}
				k=a[n2-1]-a[n1];
				for(i=1;;i<<=1){
					if(i>=k)break;
				}
				res=min(res,t1+t2+i-n);
			}
		}
		cout<<res<<'\n';
	}
}