#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e6+10;
int r,b,n,m;
map<int,int> cnt1,cnt2,id1,id2,lim[2];
int px[N],py[N],t,S,T,s0,t0;
int w[M],ne[M],la[M],len[M];
int d[M],vis[M],dep[M],ti,cur[M];
void alink(int x,int y,int z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
}
void blink(int x,int y,int z){
	if (z==0)return;
//	cout<<x<<' '<<y<<' '<<z<<endl;
	alink(x,y,z);
	alink(y,x,0);
}
int sum=0;
void link(int x,int y,int l,int r){
	blink(x,y,r-l);
	if (l<=0)return;
	sum+=l;
	blink(S,y,l);
	blink(x,T,l);
}
int bfs(){
	int l=0,r=1;
	d[1]=S;
	vis[S]=++ti;
	while (l<r){
		int x=d[++l];
		cur[x]=la[x];
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (vis[z]==ti||!len[y])continue;
			vis[z]=ti;
			dep[z]=dep[x]+1;
			d[++r]=z;
		}
	}
	return vis[T]==ti;
}
int flow(int x,int val){
	if (x==T)return val;
	int v1=val;
	for (int y=cur[x];y;cur[x]=y=ne[y]){
		int z=w[y];
		if (dep[z]!=dep[x]+1||!len[y])continue;
		int use=flow(z,min(val,len[y]));
		val-=use;
		len[y]-=use;
		len[y^1]+=use;
		if (!val)break;
	}return v1-val;
}
int ans[N];
long long Ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&px[i],&py[i]);
		cnt1[px[i]]++;
		cnt2[py[i]]++;
		lim[0][px[i]]=1;
		lim[1][py[i]]=1;
	}
	for (auto i:cnt1)id1[i.first]=++t;
	for (auto i:cnt2)id2[i.first]=++t;
	s0=++t,t0=++t,S=++t,T=++t;
	t=1;
	for (int i=1;i<=n;i++)
		blink(id1[px[i]],id2[py[i]],1);
	for (auto i:cnt1){
		int x=i.first,y=i.second;
		if (lim[0].count(x)){
			int d=lim[0][x];
			if (d==0&&(y&1)){
				cout<<-1<<endl;
				return 0;
			}
			link(s0,id1[x],(y-d+1)/2,(y+d)/2);
		}
		else link(s0,id1[x],0,y);
	}
	for (auto i:cnt2){
		int x=i.first,y=i.second;
		if (lim[1].count(x)){
			int d=lim[1][x];
			if (d==0&&(y&1)){
				cout<<-1<<endl;
				return 0;
			}
			link(id2[x],t0,(y-d+1)/2,(y+d)/2);
		}
		else link(id2[x],t0,0,y);
	}
	link(t0,s0,0,1<<30);
	while (bfs())sum-=flow(S,1<<30);
//	assert(sum>=0);
//	if (sum){
//		cout<<-1<<endl;
//		return 0;
//	}
//	S=s0,T=t0;
//	while (bfs())flow(S,1<<30);
//	for (int i=1;i<=n;i++){
//		ans[i]=len[2*i];
//		Ans+=ans[i]?max(r,b):min(r,b);
//	}
//	cout<<Ans<<endl;
	for (int i=1;i<=n;i++)
		putchar(len[2*i]==(r>=b)?'r':'b');
}