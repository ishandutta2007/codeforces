#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll X,Y,sb;
__int128 x,y;

__int128 get1(__int128 x){
	__int128 l=1,r=1e9,md,res=0,k;
	while(l<=r){
		md=(l+r)/2;
		k=(md*md+md)/2;
		if(k<x){
			res=max(res,md);
			l=md+1;
		}
		else r=md-1;
	}
	return res+1;
}

__int128 get2(__int128 y,__int128 x){
	__int128 l=1,r=y,md,res=0,k;
	while(l<=r){
		md=(l+r)/2;
		k=(y+y-md+1)*md/2;
		if(k<x){
			res=max(res,md);
			l=md+1;
		}
		else r=md-1;
	}
	return res+1;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>X>>Y;
		x=X;y=Y;
		if((x*x)<=y){
			sb=x+x-1;
			cout<<sb<<'\n';
			continue;
		}
		if(((x*x+x)/2)>=y){
			sb=get1(y);
		}
		else{
			sb=x+get2(x-1,y-(x*x+x)/2);
		}
		cout<<sb<<'\n';
	}
}