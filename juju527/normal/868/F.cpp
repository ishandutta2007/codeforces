#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int n,k;
int a[maxn];
ll f[maxn][25];
int p[maxn][25];
int t[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int lt,rt;
ll ans=0;
void ins(int x){
	ans+=t[a[x]];
	t[a[x]]++;
	return ;
}
void del(int x){
	t[a[x]]--;
	ans-=t[a[x]];
	return ;
}
void solve(int j,int l,int r,int x,int y){
	if(l>r)return ;
	int mid=l+((r-l)>>1);
	while(rt>mid)del(rt--);
	while(rt<mid)ins(++rt);
	while(lt<x)del(lt++);
	while(lt>x)ins(--lt);
	for(int i=x;i<=min(mid,y);i++){
		if(f[i-1][j-1]+ans<f[mid][j]){
			f[mid][j]=f[i-1][j-1]+ans;
			p[mid][j]=i;
		}
		del(lt++);
	}
//	cout<<mid<<" "<<j<<" "<<p[mid][j]<<endl;
	solve(j,l,mid-1,x,p[mid][j]);
	solve(j,mid+1,r,p[mid][j],y);
	return ;
}
int main(){	
	n=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=k;i++){
		lt=1;rt=0;
		for(int j=1;j<=n;j++)t[j]=0;
		solve(i,1,n,1,n);
	}
	printf("%lld\n",f[n][k]);
	return 0;
}