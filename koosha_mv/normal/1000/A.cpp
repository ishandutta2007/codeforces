#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+99;
ll n,a[N],b[N],t1m,tx[4],tl[4],p1m,px[4],pl[4],ans;
string s;
int main(){
	get(n);
	f(i,0,n){
		cin>>s;
		if(s[s.size()-1]=='S')
			tx[s.size()-1]++;
		if(s[s.size()-1]=='L')
			tl[s.size()-1]++;
		if(s[s.size()-1]=='M')
			t1m++;
	}
	f(i,0,n){
		cin>>s;
		if(s[s.size()-1]=='S')
			px[s.size()-1]++;
		if(s[s.size()-1]=='L')
			pl[s.size()-1]++;
		if(s[s.size()-1]=='M')
			p1m++;
	}
	ans+=min(t1m,p1m);
	f(i,0,4){
		ans+=min(tx[i],px[i]);
		ans+=min(tl[i],pl[i]);
	}
	cout<<n-ans;
}