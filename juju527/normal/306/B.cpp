#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5,maxm=2e5+5;
int l[maxn],id[maxn];
int mx[maxn];
int f[maxn];
bool vis[maxm];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int n,m;
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();b=read();
		if(l[a]<a+b-1)l[a]=a+b-1,id[a]=i;
	}
	for(int i=1;i<=n;i++)mx[i]=max(mx[i-1],l[i]);
	for(int i=1;i<=n;i++){
		int l=0,r=i,mid;
		while(l+1<r){
			mid=l+((r-l)>>1);
			if(mx[mid]>=i)r=mid;
			else l=mid;
		}
		f[i]=r-1;
//		cout<<f[i]<<" ";
	}//cout<<endl;
	int pos=n,sum=m;
	while(pos){
		if(!vis[id[f[pos]+1]]&&id[f[pos]+1])sum--;
		vis[id[f[pos]+1]]=1;
		pos=f[pos];
	}
	printf("%d\n",sum);
	for(int i=1;i<=m;i++)if(!vis[i])printf("%d ",i);
	return 0;
}