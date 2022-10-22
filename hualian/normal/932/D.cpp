#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+9;
const int MAX=1e15+1;
int last_ans,cnt,idx;
struct edge{
	int pre,to;
}e[2*N];
int last[N];
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N];
int ans[N];
int val[N][32],Fa[N][32];// 
int mx[N][32],fa[N][32];// 
void push_up(int x){
	int now=x;
	for(int i=1;i<=31;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
	}
	for(int i=31;i>=0;i--)
		if(mx[x][i]<a[now])x=fa[x][i];
	int pre=fa[x][0];
	ans[now]=ans[pre]+1;
	
	x=now; 
	Fa[x][0]=pre;
	val[x][0]=a[pre];
	if(val[x][0]>=MAX)val[x][0]=-1;
	for(int i=1;i<=31;i++){
		Fa[x][i]=Fa[Fa[x][i-1]][i-1];
		val[x][i]=val[x][i-1]+val[Fa[x][i-1]][i-1];
		if(val[x][i]>=MAX)val[x][i]=-1;
		if((val[x][i-1]==-1)||(val[Fa[x][i-1]][i-1]==-1))val[x][i]=-1;
	}
	return;
}
inline int get(int x,int mx){
	int sum=a[x],now=x;
	if(sum>mx)return 0;
	for(int i=31;i>=0;i--){
		if(val[x][i]==-1)continue;
		if(val[x][i]+sum>mx)continue;
		sum+=val[x][i],x=Fa[x][i];
	}
	if(x==0)return ans[now];
	return ans[now]-ans[x]+1;
	
}
signed main(){
	int q=read();
	push_up(++idx);
	while(q--){
		int op=read(),R=read(),x=read();
		R^=last_ans,x^=last_ans;
		switch(op){
			case 1:{
				a[++idx]=x;
				fa[idx][0]=R,mx[idx][0]=a[R];
				push_up(idx);
				break;
			}
			case 2:{
				last_ans=get(R,x);
				printf("%lld\n",last_ans);
				break;
			}
		}
	}
	return 0;
}