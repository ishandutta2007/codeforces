#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int b[410][410],n,m,dis[410][410],d[410],num[410],pd[410],bo[410][410],sign;
double A[410][410],w[410],f[410],an[410];
vector<int>x;
void update(int k1,int k2,double k3){
	if (bo[k1][k2]!=sign){
		bo[k1][k2]=sign; A[k1][k2]=0;
	}
	if (k3>A[k1][k2]){
		an[k1]+=k3-A[k1][k2]; A[k1][k2]=k3;
	}
}
double solve(int s){
	memset(num,0x00,sizeof num);
	memset(A,0x00,sizeof A);
	memset(w,0x00,sizeof w);
	for (int i=1;i<=n;i++) num[dis[s][i]]++;
	for (int i=0;i<=n;i++) if (num[i]) w[i]=1;
	double ans=0;
//	cout<<"solve "<<s<<endl;
	for (int i=0;i<=n;i++){
		if (num[i]==0) continue;
		x.clear();
		memset(f,0x00,sizeof f);
		memset(pd,0x00,sizeof pd);
		memset(an,0x00,sizeof an);
		sign++;
		for (int where=1;where<=n;where++)
			if (dis[s][where]==i){
				for (int j=1;j<=n;j++)
					if (b[where][j]){
						f[j]+=1.0/d[where];
						if (pd[j]==0){
							pd[j]=1; x.push_back(j);
						}
					}
			}
	//	cout<<"dis "<<i<<endl;
	//	for (int j=1;j<=n;j++) cout<<f[j]<<" "; cout<<endl;
	//	for (int j=0;j<x.size();j++) cout<<x[j]<<" "; cout<<endl;
		for (int j=0;j<x.size();j++){
			int k1=x[j];
			for (int k=1;k<=n;k++)
				update(k,dis[k1][k],f[k1]);
		}
	//	for (int j=1;j<=n;j++) cout<<an[j]<<" "; cout<<endl;
		for (int j=1;j<=n;j++) w[i]=max(w[i],an[j]);
	}
//	for (int i=0;i<=n;i++) cout<<w[i]<<" "; cout<<endl;
	for (int i=0;i<=n;i++)
		if (num[i]){
			ans+=w[i]/n;
		}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof dis);
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		b[k1][k2]=1; b[k2][k1]=1;
		dis[k1][k2]=1; dis[k2][k1]=1;
		d[k1]++; d[k2]++;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	double ans=0;
	for (int s=1;s<=n;s++) ans=max(ans,solve(s));
	printf("%.11lf\n",ans);
	return 0;
}