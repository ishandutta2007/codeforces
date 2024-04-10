#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c,p=0;int w;
	while(!isdigit(c=getchar()))if(c=='-')p=1;w=c^'0';
	while(isdigit(c=getchar()))w=w*10+(c^'0');return p?-w:w;
}
inline bool smin(int&x,const int&y){return x>y?x=y,1:0;}
inline bool smax(int&x,const int&y){return x<y?x=y,1:0;}
unordered_map<int,int>p;
const int n=read(),m=4000;
int x,y,np[m+2],pr[m+2];
int main(){
	REP(i,2,m)if(!np[i]){
		pr[++pr[0]]=i;
		for(int j=i*i;j<=m;j+=i)np[j]=1;
	}
	REP(i,1,n){
		x=read();y=sqrt(x);
		REP(j,1,pr[0]){
			if(pr[j]>x||pr[j]>y)break;
			if(x%pr[j]==0){
				int u=1;
				while(x%pr[j]==0)x/=pr[j],++p[u*=pr[j]];
			}
		}
		if(x>1)++p[x];
	}
	int ans=n;
	for(auto t:p)if(t.second<n)smin(ans,n-t.second);
	if(ans==n)puts("-1");else printf("%d\n",ans);
	return 0;
}