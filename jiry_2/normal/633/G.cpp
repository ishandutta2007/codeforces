#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
bitset<1010>num[410000],q,ans;
struct bian{
	int next,point;
}b[210000];
int a[110000],p[110000],len,n,m,A[410000],pd[1100],dfs[110000],r[110000],sign,x[110000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs1(int k1,int k2){
	dfs[k1]=++sign;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2) dfs1(j,k1);
	}
	r[k1]=sign;
}
void change(int k1){
	num[k1]=num[k1*2]|num[k1*2+1];
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		num[k1][x[k2]]=1; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
void addin(int k1,int k2){
	A[k1]=(A[k1]+k2)%m;
	num[k1]=((num[k1]>>(m-k2))|(num[k1]<<k2));
}
void pushdown(int k1){
	if (A[k1]){
		addin(k1*2,A[k1]); addin(k1*2+1,A[k1]); A[k1]=0;
	}
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
	//	cout<<"addin "<<k1<<" "<<k2<<" "<<m<<endl;
	//	for (int i=0;i<m;i++) cout<<num[k1][i]<<" "; cout<<endl;
		addin(k1,k6);
//		for (int i=0;i<m;i++) cout<<num[k1][i]<<" "; cout<<endl; 
	return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6);
	add(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void get(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		ans|=num[k1]; return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	get(k1*2,k2,mid,k4,k5);
	get(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
	scanf("%d%d",&n,&m);
	memset(pd,0x00,sizeof pd);
	for (int i=2;i<m;i++){
		if (pd[i]==0){
			q[i]=1; //cout<<"fa "<<i<<endl;
		}
		for (int j=i;j<m;j+=i) pd[j]=1;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]); a[i]%=m;
	}
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	dfs1(1,0);
//	for (int i=1;i<=n;i++) cout<<"fa "<<dfs[i]<<" "<<r[i]<<endl;
	for (int i=1;i<=n;i++) x[dfs[i]]=a[i];
	buildtree(1,1,n);
	int t; scanf("%d",&t);
	for (;t;t--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		if (k1==2){
			ans=0; get(1,1,n,dfs[k2],r[k2]);
		//	for (int i=0;i<m;i++) cout<<ans[i]<<" "; cout<<endl;
			printf("%d\n",(ans&q).count());
		} else {
			int k3; scanf("%d",&k3); k3%=m;
			add(1,1,n,dfs[k2],r[k2],k3);
		}
	}
	return 0;
}