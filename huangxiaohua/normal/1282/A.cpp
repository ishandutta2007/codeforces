#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a,b,c,r,res,x,y,xx,yy;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>r;
		if(a>b)swap(a,b);
		res=0;
		x=c-r;
		y=c+r;
		xx=max(a,x);
		yy=min(b,y);
		res=max(0ll,yy-xx);
		res=b-a-res;
		cout<<res<<'\n';
	}
}