#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e6+9;
int n;
int a[M];
vector<int>g[M];
int s[M],top;
int mil[M],mir[M],mal[M],mar[M];
void work(){
	cin>>n;
	for(int i=1;i<M;++i)g[i].clear();
	for(int i=1;i<M;++i)g[i].eb(0);
	for(int i=1;i<=n;++i)cin>>a[i],g[a[i]].eb(i);
	for(int i=1;i<M;++i)g[i].eb(n+1);
	for(int i=1;i<=n;++i){
		while(top&&a[s[top]]>a[i]){
			mil[s[top]]=s[top-1]+1;
			mir[s[top]]=i-1;
			top--;
		}
		s[++top]=i;
	}
	while(top){
		mil[s[top]]=s[top-1]+1;
		mir[s[top]]=n;
		top--;
	}
	for(int i=1;i<=n;++i){
		while(top&&a[s[top]]<a[i]){
			mal[s[top]]=s[top-1]+1;
			mar[s[top]]=i-1;
			top--;
		}
		s[++top]=i;
	}
	while(top){
		mal[s[top]]=s[top-1]+1;
		mar[s[top]]=n;
		top--;
	}
	for(int i=1;i<=n;++i){
		if(a[mil[i]-1]==a[i])mil[i]=mil[mil[i]-1];
	}
	for(int i=n;i>=1;--i){
		if(a[mir[i]-1]==a[i])mir[i]=mir[mir[i]-1];
	}
	ll ans=0;
	mil[n+1]=mir[n+1]=mal[n+1]=mar[n+1]=n+1;
	for(int i=1;i<M;++i){
		if(g[i].size()==2)continue;
		for(int j=i;j<M;j+=i){
			for(auto o:g[j]){
				if(o<1||o>n)continue;
				int x=*prev(upper_bound(g[i].begin(),g[i].end(),o));
				int y=*lower_bound(g[i].begin(),g[i].end(),o);
				int l,r;
				l=x-max(mal[o],mil[x])+1;
				r=min(mar[o],mir[x])-o+1;
				if(l<0)l=0;
				if(r<0)r=0;
				ll d=0;
				d+=l*r;
				ans+=1ll*l*r;
				l=o-max(mal[o],mil[y])+1;
				r=min(mar[o],mir[y])-y+1;
				if(l<0)l=0;
				if(r<0)r=0;
				d+=l*r;
				ans+=1ll*l*r;
				l=x-max({mal[o],mil[x],mil[y]})+1;
				r=min({mar[o],mir[y],mir[x]})-y+1;
				if(l<0)l=0;
				if(r<0)r=0;
				d-=l*r;
				ans-=1ll*l*r;
				//cout<<i<<" "<<j<<" "<<o<<" "<<x<<" "<<y<<" "<<d<<endl;

				//cout<<i<<" "<<j<<" "<<o<<" "<<x<<" "<<y<<" "<<d<<endl;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
2
2 4
*/