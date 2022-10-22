#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
ll n,l,c[35];
int gerd(int x,int y){
	if(x%y==0)
		return x/y;
	return x/y+1;}
int main(){
	cin>>n>>l;
	f(i,0,n) {cin>>c[i];
		if(i!=0) c[i]=min(c[i],c[i-1]*2);}
	ll z=1,cost=0,ans=1e18;
	f(i,0,n-1) z*=2;
	f_(i,n-1,0){
		cost+=(l/z)* c[i];
		l%=z;
		ans=min(ans,cost+gerd(l,z)*c[i]);
		z/=2;
	}
	cout<<ans;
}