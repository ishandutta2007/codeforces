#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
int n,m,T,i,j,k,x,y,a[N],b[N],c[N];
char ch;
string s;
ll l,r;
ll f(ll x){
	if(x==0)return 0;
	ll l=(ll)(sqrt(x));
	if(l*l>x)--l;
	return (l*3-2)+(x-l*l)/l;
}
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>l>>r;
		cout<<f(r)-f(l-1)<<"\n"; 
	}
}