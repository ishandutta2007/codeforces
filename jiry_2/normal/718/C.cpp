#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct atom{
	int x[2][2];
}A,B;
const int mo=1e9+7;
atom operator * (atom k1,atom k2){
	memset(B.x,0x00,sizeof B.x);
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				B.x[i][j]=(B.x[i][j]+1ll*k1.x[i][k]*k2.x[k][j])%mo;
	return B;
}
atom operator + (atom k1,atom k2){
	memset(B.x,0x00,sizeof B.x);
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			B.x[i][j]=(k1.x[i][j]+k2.x[i][j])%mo;
	return B;
}
atom get(int k){
	A.x[0][0]=0; A.x[0][1]=A.x[1][0]=A.x[1][1]=1;
	atom ans=A; k--;
	while (k){
		if (k&1) ans=ans*A; k>>=1; A=A*A;
	}
	return ans;
}
const int N=110000;
atom C[N<<2],sum[N<<2];
void change(int k1){
	sum[k1]=sum[k1*2]+sum[k1*2+1];
}
void buildtree(int k1,int k2,int k3){
	C[k1].x[0][0]=C[k1].x[1][1]=1;
	C[k1].x[1][0]=C[k1].x[0][1]=0;
	if (k2==k3){
		int k; scanf("%d",&k);
		sum[k1]=get(k); return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
//	cout<<"fa "<<k1<<" "<<k2<<" "<<k3<<endl;
//	cout<<sum[k1].x[0][0]<<" "<<sum[k1].x[0][1]<<endl;
//	cout<<sum[k1].x[1][0]<<" "<<sum[k1].x[1][1]<<endl;
}
atom p;
void add(int k1,atom k2){
	C[k1]=C[k1]*k2; sum[k1]=sum[k1]*k2;
}
void pushdown(int k1){
	add(k1*2,C[k1]); add(k1*2+1,C[k1]);
	C[k1].x[0][0]=C[k1].x[1][1]=1;
	C[k1].x[1][0]=C[k1].x[0][1]=0;
}
void add(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k1,p);  return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5);
	add(k1*2+1,mid+1,k3,k4,k5);
	change(k1);
}
atom find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4){
		atom A; memset(A.x,0x00,sizeof A.x); return A;
	}
	if (k2>=k4&&k3<=k5){
	//	cout<<"asd "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<sum[k1].x[1][0]<<endl; 
	return sum[k1];
	}
	int mid=k2+k3>>1; pushdown(k1);
	return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	buildtree(1,1,n);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		if (k1==2){
			atom ans=find(1,1,n,k2,k3);
			printf("%d\n",ans.x[1][0]);
		} else {
			int k4; scanf("%d",&k4); p=get(k4);
			add(1,1,n,k2,k3);
		}
	}
	return 0;
}