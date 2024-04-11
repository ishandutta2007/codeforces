#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll n,m,w,a[100099],s[100099],b[100099];
bool check(ll x){
	f(i,0,n) s[i]=0,b[i]=0;
	f(i,0,n){b[i]=max(x-a[i],(ll)0);}
	ll gh=0,j=0;
	f(i,0,n){
		if(i-w>=0){
			gh-=s[i-w];
		}
		s[i]=max(x-(a[i]+gh),(ll)0);
		j+=s[i];
		gh+=s[i];
		if(j>m) return false;
	}
	return true;
}
int main(){
	cin>>n>>m>>w;
	f(i,0,n) cin>>a[i];
	ll l=1,r=1e10;
	//cout<<check(4294967305)<<endl;
	while(l+1<r){
		ll mid=(l+r)/2;
		//cout << ' ' << l << ' ' << mid << ' ' << r << ' ' << ' ' << check(mid) << endl;
		if(check(mid)){
			l=mid;
		}
		else r=mid;
	}
	cout<<l;
}