#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,y;
ll a[200500],b[200500],k=1e18,sb,tot;
string s,res;

void del(){for(int i=n;i>1;i--)b[i]-=b[i-1];}
void add(){for(int i=2;i<=n;i++)b[i]+=b[i-1];}

void dfs(){
	tot++;
	if(sb>=k)return;
	bool NMSL=1;
	for(i=1;i<=n;i++){
		if(b[i]<=0)return;
		if(b[i]!=a[i])NMSL=0;
	}
	if(!NMSL)goto aaa;
	if(!y){res=s;k=sb;y=1;}
	else if(sb<k){
		k=sb;res=s;
	}
	return;
	aaa:;
	for(i=1;i<=n;i++){
		if(a[i]!=b[n+1-i])goto bbb;
	}
	if(!y){res=s;res+="R";k=sb;y=1;}
	else if(sb<k){
		k=sb;res=s;res+="R";
	}
	bbb:;
	s+="P";sb++;del();
	dfs();
	sb--;s.pop_back();add();
	s+="RP";sb++;reverse(b+1,b+n+1);del();
	dfs();
	sb--;s.pop_back();s.pop_back();add();reverse(b+1,b+n+1);
}

void show(){
	reverse(res.begin(),res.end());
	if(k>200000)cout<<"BIG\n"<<k;
	else cout<<"SMALL\n"<<res.size()<<'\n'<<res;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=n;i++)if(a[i]!=b[i])goto aaa;
	cout<<"SMALL\n0";return 0;
	aaa:;
	for(i=1;i<=n;i++)if(a[i]!=b[n+1-i])goto bbb;
	cout<<"SMALL\n1\nR";return 0;
	bbb:;
	if(n==1){cout<<"IMPOSSIBLE";return 0;}
	if(n>=3){
		s+="P";sb++;del();
		dfs();
		s.pop_back();sb--;add();
		
		s+="RP";sb++;
		reverse(b+1,b+n+1);del();
		dfs();
		s.pop_back();s.pop_back();sb--;add();reverse(b+1,b+n+1);
		
		if(y)show();
		else cout<<"IMPOSSIBLE";
		return 0;
	}
	k=0;
	while(1){
		if(a[1]==b[1]&&a[2]==b[2]){
			show();return 0;
		}
		if(a[1]==b[2]&&a[2]==b[1]){
			res+="R";show();return 0;
		}
		if(b[1]>b[2]){
			res+="R";swap(b[1],b[2]);
		}
		ll l=1,r=(b[2]-1)/b[1],ans=0,md;
		while(l<=r){
			md=(l+r)/2;
			if( (b[2]-md*b[1])>=a[1] && b[1]>=a[2] ){
				ans=max(ans,md);l=md+1;continue;
			}
			if( (b[2]-md*b[1])>=a[2] && b[1]>=a[1] ){
				ans=max(ans,md);l=md+1;continue;
			}
			r=md-1;
		}
		if(!ans){
			cout<<"IMPOSSIBLE";return 0;
		}
		k+=ans;
		if(k<=200000){
			for(i=1;i<=ans;i++)res+="P";
		}
		b[2]-=ans*b[1];
	}
}