#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian{
	int next,point,pd;
}b[110000];
long long num1,num2;
int p[500],n,m,v,a[500],bb[500],len,pd[500],d[500],ans[500100][3];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k){
	num1+=a[k]; num2+=bb[k]; pd[k]=1;
	for (int i=p[k];i!=-1;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0){
			dfs(j); d[j]++; d[k]++; b[i].pd=1; b[i^1].pd=1;
		}
	}
}
void down(int k1,int k2,int k3){
//	cout<<"down "<<k1<<" "<<k2<<" "<<k3<<endl;
	for (int i=p[k1];i!=-1;i=b[i].next){
		int j=b[i].point;
		if (j!=k3&&b[i].pd&&pd[j]==0){
			down(j,max(0,k2-(v-a[j])),k1); int num=min(k2,v-a[j]);
			len++; ans[len][0]=k1; ans[len][1]=j; ans[len][2]=num;
			a[j]+=num; a[k1]-=num; k2-=num;
		}
	}
}
void up(int k1,int k2,int k3){
//	cout<<"up "<<k1<<" "<<k2<<" "<<k3<<endl;
	for (int i=p[k1];i!=-1;i=b[i].next){
		int j=b[i].point;
		if (j!=k3&&b[i].pd&&pd[j]==0){
			up(j,min(v-a[j],max(0,k2-a[j])),k1); int num=min(k2,a[j]);
			len++; ans[len][0]=j; ans[len][1]=k1; ans[len][2]=num;
			a[j]-=num; a[k1]+=num; k2-=num;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&v,&m); memset(p,0xff,sizeof p); len=-1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&bb[i]);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	//cout<<1<<endl;
	for (int i=1;i<=n;i++)
		if (pd[i]==0){
			num1=0; num2=0; dfs(i); if (num1!=num2){cout<<"NO"<<endl; return 0;}
		}
	//cout<<2<<endl;
	len=0; memset(pd,0x00,sizeof pd);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (d[j]==1&&pd[j]==0){
				if (a[j]>bb[j]) down(j,a[j]-bb[j],0); else if (a[j]<bb[j]) up(j,bb[j]-a[j],0); pd[j]=1;
				for (int k1=p[j];k1!=-1;k1=b[k1].next) if (b[k1].pd&&pd[b[k1].point]==0) d[b[k1].point]--;
			}
	cout<<len<<endl;
	for (int i=1;i<=len;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]); return 0;
}