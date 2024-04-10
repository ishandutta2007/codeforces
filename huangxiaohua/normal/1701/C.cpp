#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500];
ll su;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(a,0,n*4+50);
		for(i=1;i<=m;i++){
			cin>>k;a[k]++;
		}
		su=0;
		int l=1,r=m,md=0,res=m;
		while(l<=r){
			md=(l+r)/2;
			su=0;
			for(i=1;i<=n;i++){
				if(md<=a[i])su+=md;
				else{
					su+=a[i]+(md-a[i])/2;
				}
			}
			if(su>=m){
				res=min(res,md);r=md-1;
			}
			else l=md+1;
		}
		cout<<res<<'\n';
	}
}