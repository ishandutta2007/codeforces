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

const int N=3e5+9;
ll n,t,ans,p1,p2,e=1e6,x,y;
string s;
map<ll,ll> mark;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>s;
		s=' '+s;
		p1=-1,p2=1e9;
		x=y=0;
		f(i,1,n+1){
			if(s[i]=='R')
				x++;
			if(s[i]=='L')
				x--;
			if(s[i]=='U')
				y++;
			if(s[i]=='D')
				y--;
			if((mark[x*e+y]!=0 || (x==0 && y==0)) && i-mark[x*e+y]<p2-p1)
				p2=i,p1=mark[x*e+y];
			mark[x*e+y]=i;
		}
		if(p1==-1)
			cout<<-1<<endl;
		else
			cout<<p1+1<<" "<<p2<<endl;
		x=y=0;
		f(i,1,n+1){
			if(s[i]=='R')
				x++;
			if(s[i]=='L')
				x--;
			if(s[i]=='U')
				y++;
			if(s[i]=='D')
				y--;
			mark[x*e+y]=0;
		}
	}
}