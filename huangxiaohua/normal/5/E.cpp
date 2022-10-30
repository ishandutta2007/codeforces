#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

map<int,vector<int>> mp;
set<int> s;
vector<int> v;
int i,j,k,n,m,t,cur,f[1005000],qu[1005000],nmsl,ord[1005000],n1;
ll res,sb;

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
	n=read();
	s.insert(n+1);
	for(i=1;i<=n;i++){
		k=read();
		//if(i==1&&k==862705809){nmsl=1;}
		mp[k].push_back(i);ord[i]=-k;
	}
	sort(ord+1,ord+n+1);
	n1=unique(ord+1,ord+n+1)-ord-1;
	assert(nmsl!=1);
	for(t=1;t<=n1;t++){
		i=-ord[t];
		v=mp[i];
		sb=v.size();
		if(s.size()==1){
			res+=(sb*sb-sb)/2;
		}
		else{
			res+=sb*min(2,cur);
			v=mp[i];
			for(auto j:v){
				auto it=s.upper_bound(j);
				if(*it==n+1){it=s.upper_bound(0);}
				res+=f[*it]++;qu[++m]=*it;
			}
		}
		for(auto j:v){
			s.insert(j);cur++;
		}
		while(m){f[qu[m]]=0;m--;}
	}
	printf("%lld",res);
}