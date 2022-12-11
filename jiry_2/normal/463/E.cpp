#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian{
	int next,point;
}b[201000];
int n,q,prime[200010],len,pd[2000100],head[200010],w[2000000],d[200000],next[2000000],x[100100][10],a[100100],s[2010000],ans[101000],p[101000];
void make(){
	for (int i=2;i<=2000000;i++){
		if (pd[i]==0) {prime[++len]=i; s[i]=len;}
		for (int j=1;j<=len;j++){
			int now=prime[j]*i;
			if (now>2000000) break;
			pd[now]=1; if (i%prime[j]==0) break;
		}
	}
}
void get(int k){
	int k1=a[k]; x[k][0]=0;
	for (int i=1;prime[i]<=trunc(sqrt(k1));i++)
		if (k1%prime[i]==0){
			x[k][++x[k][0]]=i; while (k1%prime[i]==0) k1=k1/prime[i];
		}
	if (k1>1) x[k][++x[k][0]]=s[k1];
}
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void getans(int k1,int k2,int k3){
	d[k3]=k1;
	for (int i=1;i<=x[k1][0];i++){
	//	cout<<k1<<" "<<prime[x[k1][i]]<<endl;
		if (head[x[k1][i]]!=0) ans[k1]=max(ans[k1],w[head[x[k1][i]]]);
		len++; next[len]=head[x[k1][i]]; w[len]=k3; head[x[k1][i]]=len; 
	}
	if (ans[k1]!=-1) ans[k1]=d[ans[k1]];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point; if (j!=k2) getans(j,k1,k3+1);
	}
	for (int i=1;i<=x[k1][0];i++) head[x[k1][i]]=next[head[x[k1][i]]];
}
int main(){
	scanf("%d%d",&n,&q); make(); len=0; 
	for (int i=1;i<=n;i++){scanf("%d",&a[i]); get(i);} 
	for (int i=1;i<n;i++){int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);}
	len=0; memset(ans,0xff,sizeof ans); getans(1,0,1);  
	/*for (int i=1;i<=n;i++){
		for (int j=1;j<=x[i][0];j++) cout<<prime[x[i][j]]<<" "; cout<<endl;}
	for (int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl; */
	for (;q;q--){
		int k1,k2; scanf("%d",&k1);
		if (k1==1){
			scanf("%d",&k2); printf("%d\n",ans[k2]);
		} else {
			scanf("%d%d",&k1,&k2); memset(ans,0xff,sizeof ans); len=0; a[k1]=k2; get(k1);
			//for (int i=1;i<=x[k1][0];i++) cout<<prime[x[k1][i]]<<" "; cout<<endl;
			getans(1,0,0);
		}
	}
	return 0;
}