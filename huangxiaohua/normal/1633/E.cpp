#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,m,t,n,fa[66],cur,tt,q[10005000],t1,t2,t3,id[10005000],e[100500],it,it2;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
ll res,ans,tmp;
struct bian{
	int x,y,w;
	bool operator<(const bian a)const{return abs(cur-w)<abs(cur-a.w);}
}s[305];
bool cmp(int a,int b){return q[a]<q[b];}
void work(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(s+1,s+m+1);
	int x,y,w;
	ans=0;tmp=0;
	for(int i=1;i<=m;i++){
		x=find(s[i].x);y=find(s[i].y);w=s[i].w;
		if(x==y)continue;
		if(w<=cur)ans-=w,tmp++;
		else ans+=w,tmp--;
		fa[x]=y;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>s[i].x>>s[i].y>>s[i].w;
	cin>>tt>>t>>t1>>t2>>t3;
	for(i=1;i<=t;i++){
		id[i]=i;
		if(i<=tt)cin>>q[i];
		else q[i]=(1ll*q[i-1]*t1+t2)%t3;
	}
	sort(id+1,id+t+1,cmp);
	for(i=1;i<=m;i++){
		e[++it]=s[i].w;
		for(j=1;j<=m;j++)if(s[i].w<s[j].w){
			e[++it]=(s[i].w+s[j].w)/2+1;
		}
	}
	sort(e+1,e+it+1);
	it2=1;
	work();
	for(i=1;i<=t;i++){
		cur=q[id[i]];
		while(it2<=it){
			if(e[it2]<=cur){it2++;work();}
			else break;
		}
		res^=(ans+cur*tmp);
	}
	cout<<res;
}