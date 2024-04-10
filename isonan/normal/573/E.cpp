#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define int long long

int n,ch[100001][2],pri[100001],size[100001],root;
long long val[100001],add[100001];
inline void pushdown(int x,int y){x?val[x]+=y,add[x]+=y:0;}
inline void spread(int x){pushdown(ch[x][0],add[x]),pushdown(ch[x][1],add[x]),add[x]=0;}
inline void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
inline bool check(int x,int s,int v){return val[x]>=1ll*s*v;}
void split(int now,int &x,int &y,int s,int v){
	if(!now)x=y=0;
	else{
		spread(now);
		if(check(now,s+size[ch[now][0]]+1,v))x=now,split(ch[now][1],ch[now][1],y,s+size[ch[now][0]]+1,v);
		else y=now,split(ch[now][0],x,ch[now][0],s,v);
		pushup(now);
	}
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	spread(x),spread(y);
	if(pri[x]<pri[y]){
		ch[x][1]=merge(ch[x][1],y);
		pushup(x);
		return x;
	}
	else{
		ch[y][0]=merge(x,ch[y][0]);
		pushup(y);
		return y;
	}
}
long long ans,now;
void getans(int x){
	if(!x)return;
	spread(x);
	getans(ch[x][0]);
	now+=val[x];
	ans=std::max(ans,now);
	getans(ch[x][1]);
}
signed main(){
	srand(19260817);
	scanf("%I64d",&n);
	for(int i=1,tem;i<=n;i++){
		scanf("%I64d",&tem);
		int t1=0,t2=0;
		split(root,t1,t2,0,tem);
		pri[i]=rand();
		val[i]=1ll*tem*(size[t1]+1);
		size[i]=1;
		pushdown(t2,tem);
		root=merge(t1,merge(i,t2));
	}
	getans(root);
	printf("%I64d",ans);
}