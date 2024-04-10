#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,r,res,w;
map<int,int> mp;
set<int> s;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main(){
	ios::sync_with_stdio(0);
	n=read();t=read();
	s.insert(1);s.insert(n+1);
	mp[1]=1;res=n;
	while(t--){
		l=read();r=read();w=read();w--;
		auto it=s.upper_bound(l),it2=it;it--;
		s.insert(l);mp[l]=mp[*it];
		it=s.upper_bound(r+1);it--;
		s.insert(r+1);mp[r+1]=mp[*it];
		
		it=s.find(l);
		while((*it)<=r){
			k=mp[*it];it2=it;it++;
			res-=(*it-*it2)*k;s.erase(it2);
		}
		
		res+=(r-l+1)*w;
		s.insert(l);mp[l]=w;
		cout<<res<<'\n';
	}
}