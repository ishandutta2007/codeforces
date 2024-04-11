#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=102;

ll n,m,t;
string s[N];

string bnr(ll x){
	string res="";
	f(i,0,m){
		if(x%2) res+='1';
		else res+='0';
		x/=2;
	}
	reverse(res.begin(),res.end());
	return res;
}
ll Get_an(ll x){
	string a=bnr(x);
	f(i,0,n)
		if(s[i]<a)
			x--;
	return x;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		f(i,0,n)
			cin>>s[i];
		ll l=0,r=(1ll<<1ll*61),mid,an;
		an=((1ll<<m)-n-1ll)/2ll;
		while(l+1<r){
			mid=(l+r)/2ll;
			if(Get_an(mid)<=an) l=mid;
			else r=mid;
		}
		cout<<bnr(l)<<endl;
	}
}