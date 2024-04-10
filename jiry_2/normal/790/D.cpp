#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int f[310000][2],way[310000][2];
int x[310000][2],n,w[310000][2];
int ne[310000][3],ans;
map<long long,int>M;
void insert(int k1,int k2,int k3){
//	cout<<"insert "<<k1<<" "<<k2<<" "<<k3<<endl; 
	if (k1>n||k2>n) return; ans=max(ans,k3);
	if (k1>=k2){
		if (k3>f[k1][0]){
			f[k1][0]=k3; way[k1][0]=k2;
		} else if (k3==f[k1][0]) way[k1][0]=min(way[k1][0],k2);
	}
	if (k2>=k1){
		if (k3>f[k2][1]){
			f[k2][1]=k3; way[k2][1]=k1;
		} else if (k3==f[k2][1]) way[k2][1]=min(way[k2][1],k1);
	}
}
void update(int k1,int k2,int k3){
//	cout<<"update "<<k1<<" "<<k2<<" "<<k3<<endl;
	insert(k1+1,k2,k3);
	insert(k1,k2+1,k3);
	insert(ne[k1+1][0],k2,k3+1);
	insert(k1,ne[k2+1][1],k3+1);
	insert(ne[k1+1][0],ne[k2+1][1],k3+2);
}
int main(){
	memset(f,0x00,sizeof f);
	memset(way,0x3f,sizeof way);
	f[0][0]=f[0][1]=way[0][0]=way[0][1]=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i][0]);
	for (int i=1;i<=n;i++) scanf("%d",&x[i][1]);
	long long p=0; M[0]=n;
	for (int i=n;i;i--){
		p+=x[i][0]; if (M[p]==0) ne[i][0]=n+1; else ne[i][0]=M[p]; M[p]=i-1;
	}
	M.clear();
	p=0; M[0]=n;
	for (int i=n;i;i--){
		p+=x[i][1]; if (M[p]==0) ne[i][1]=n+1; else ne[i][1]=M[p]; M[p]=i-1;
	}
	M.clear();
	p=0; M[0]=n;
	for (int i=n;i;i--){
		p+=x[i][1]+x[i][0]; if (M[p]==0) ne[i][2]=n+1; else ne[i][2]=M[p]; M[p]=i-1;
	}
	ne[n+1][0]=ne[n+1][1]=ne[n+1][2]=n+1;
	int r=1e9;
	for (int i=n;i;i--){
		if (ne[i][0]<=r) r=ne[i][0]; ne[i][0]=r;
	}
	r=1e9;
	for (int i=n;i;i--){
		if (ne[i][1]<=r) r=ne[i][1]; ne[i][1]=r;
	}
//	for (int i=0;i<=n;i++) cout<<ne[i][0]<<" "; cout<<endl;
//	for (int i=0;i<=n;i++) cout<<ne[i][1]<<" "; cout<<endl;
//	for (int i=0;i<=n;i++) cout<<ne[i][2]<<" "; cout<<endl;
	ans=0;
	for (int i=1;i<=n;i++){
		update(i-1,way[i-1][0],f[i-1][0]);
		update(way[i-1][1],i-1,f[i-1][1]);
		int num=max(f[i-1][0],f[i-1][1]);
		insert(i,i,num);
		insert(ne[i][2],ne[i][2],num+1);
	}
	printf("%d\n",ans); return 0;
}