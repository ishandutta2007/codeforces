#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[200500],p[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>a[i];
			p[i]=p[i-1];
			if(i>1&&a[i]*2>a[i-1]){
				p[i]++;
			}
		}
		int res=0;
		for(i=1+m;i<=n;i++){
			if(p[i]-p[i-m]==m)res++;
		}
		cout<<res<<'\n';
	}
}