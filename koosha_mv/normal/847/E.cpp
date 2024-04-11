#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,l,r=1e6+9,mid,t,gh,k,a;
string s;
bool check(ll x){
	a=0;
	f(i,1,n+1){
		if(s[i]=='.' && a==i-1 && a<i) a++;
		if(s[i]=='P'){
			if(a>=i)
				a=i+x;
			else{
				if(i-a-1>x) return 0;
				if(a>=i)
					a=i+x;
				else
					a=max(max(i+x-((i-a-1)*2),i+((x-(i-a-1))/2)),i);
			}
		}
	}
	if(a>=n) return 1;
	return 0;
}
int main(){
	cin>>n>>s;
	s=' '+s;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r;
}