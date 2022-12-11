#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct bian{
	int next,point,w;
}b[210000];
int n,m,p[110000],len,pd[110000],size[110000],mo;
int A[110000],inv[110000];
long long ans;
void ade(int k1,int k2,int k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,int k3){
	ade(k1,k2,k3); ade(k2,k1,k3);
}
int getphi(int k){
	int phi=1;
	for (int i=2;1ll*i*i<=k;i++)
		if (k%i==0){
			phi*=(i-1); k/=i;
			while (k%i==0){
				phi*=i; k/=i;
			}
		}
	if (k>1) phi*=(k-1);
	return phi;
}
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int num,where;
int dfs1(int k1,int k2){
	size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) size[k1]+=dfs1(j,k1);
	}
	return size[k1];
}
void dfs2(int k1,int k2){
	int ma=n-size[k1];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0){
			ma=max(ma,size[j]);
			dfs2(j,k1);
		}
	}
	if (ma<num){
		num=ma; where=k1;
	}
}
map<int,int>M1,M2;
void dfs3(int k1,int k2,int k3,int k4,int k5){
	ans+=M1[(mo-k4)%mo]; ans+=M2[(mo-1ll*k5*inv[k3]%mo)%mo];
//	cout<<"add "<<k1<<" "<<(mo-k4)%mo<<" "<<(mo-1ll*k5*inv[k3]%mo)%mo<<endl;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) dfs3(j,k1,k3+1,(k4+1ll*A[k3]*b[i].w)%mo,(10ll*k5+b[i].w)%mo);
	}
}
void dfs4(int k1,int k2,int k3,int k4,int k5){
	M1[1ll*k5*inv[k3]%mo]++; M2[k4]++;
//cout<<"ins "<<1ll*k5*inv[k3]%mo<<" "<<k4<<endl;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) dfs4(j,k1,k3+1,(k4+1ll*A[k3]*b[i].w)%mo,(10ll*k5+b[i].w)%mo);
	}
}
vector<int>x;
void solve(int k1){
	n=dfs1(k1,0); num=n; dfs2(k1,0); int k=where;
	M1.clear(); M2.clear(); M1[0]=1; M2[0]=1; pd[k]=1; //cout<<"solve "<<k<<endl;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0){
			dfs3(j,k,1,b[i].w%mo,b[i].w%mo); dfs4(j,k,1,b[i].w%mo,b[i].w%mo); //cout<<"insert "<<j<<" "<<ans<<endl;
		}
	}
//	cout<<"fin "<<ans<<endl;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) solve(j);
	}
}
int main(){
	scanf("%d%d",&n,&mo);
	if (mo==1){
		printf("%I64d\n",1ll*n*(n-1)); return 0;
	}
	for (int i=1;i<n;i++){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); k1++; k2++; add(k1,k2,k3);
	}
	A[0]=1; inv[0]=1; A[1]=10; inv[1]=quick(10,getphi(mo)-1); 
	for (int i=2;i<=n;i++){
		A[i]=1ll*A[i-1]*A[1]%mo;
		inv[i]=1ll*inv[i-1]*inv[1]%mo;
	}
	solve(1);
	printf("%I64d\n",ans);
	return 0;
}