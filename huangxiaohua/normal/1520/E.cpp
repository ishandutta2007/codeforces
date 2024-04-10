#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,k,t;
ll a[1005000],res,sum,sum2;
char s[1005000];

ll min(ll a,ll b){return a<b?a:b;}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s+1;
		m=sum=sum2=0;
		res=1e18;
		for(i=1;i<=n;i++){
			if(s[i]=='*'){
				a[++m]=i;a[m]-=m;sum+=a[m];
			}
		}
		if(!m){cout<<0<<endl;continue;}
		sort(a+1,a+m+1);
		for(i=1;i<=m;i++){
			sum2+=a[i];
			sum-=a[i];
			res=min(res,a[i]*i-sum2-(m-i)*a[i]+sum);
		}
		cout<<res<<endl;
	}
}