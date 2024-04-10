#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=1e9;
struct atom{
	int go[4][4];
	void print(){
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++) cout<<go[i][j]<<" "; cout<<endl;}
		cout<<endl; cout<<endl;
	}
}f[210000][18],B;
int two[210000],pre[210000],n,m,A[210000],x[210000];
char ch[210000];
atom merge(atom &k1,atom &k2){
	memset(B.go,0x3f,sizeof B.go);
	for (int i=0;i<4;i++)
		for (int j=i;j<4;j++)
			for (int k=j;k<4;k++) B.go[i][k]=min(B.go[i][k],k1.go[i][j]+k2.go[j][k]);
	return B;
}
int solve(int l,int r){
	if (l>=r) return inf;
	int num=r-l+1; int prel=l;
	atom ans; memset(ans.go,0x3f,sizeof ans.go);
	ans.go[0][0]=0;
	for (int i=17;i>=0;i--)
		if ((1<<i)&num){
			int ne=l+(1<<i);
			ans=merge(ans,f[ne-1][i]);
			l+=(1<<i);
		/*	cout<<"asd "<<prel<<" "<<l-1<<endl;
			for (int j=0;j<4;j++){
				for (int k=0;k<4;k++) cout<<ans.go[i][j]<<" "; cout<<endl;}*/
		}
	return ans.go[0][3];
}
int main(){
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for (int i=1;i<=n;i++) x[i]=ch[i]-'0';
	for (int i=1;i<=n;i++){
		if (ch[i]=='7') pre[i]=i; else pre[i]=pre[i-1];
		if (ch[i]=='6') A[i]=A[i-1]+1; else A[i]=A[i-1];
	}
	for (int i=1;i<=n;i++){
		f[i][0].go[0][0]=f[i][0].go[1][1]=f[i][0].go[2][2]=f[i][0].go[3][3]=0;
		if (x[i]==2) f[i][0].go[0][1]=0,f[i][0].go[0][0]=1;
		if (x[i]==0) f[i][0].go[1][2]=0,f[i][0].go[1][1]=1;
		if (x[i]==1) f[i][0].go[2][3]=0,f[i][0].go[2][2]=1;
		if (x[i]==6) f[i][0].go[3][3]=1;
	}
	for (int i=1;i<18;i++)
		for (int j=(1<<i);j<=n;j++)
			f[j][i]=merge(f[j-(1<<i-1)][i-1],f[j][i-1]);
//	for (int i=1;i<=n;i++) f[i][0].print();
	two[1]=0;
	for (int i=2;i<=n;i++) two[i]=two[i>>1]+1;
	for (;m;m--){
		int l,r; scanf("%d%d",&l,&r);
		int m=pre[r];
		int k1=solve(l,m-1); //cout<<k1<<" "<<A[r]<<" "<<A[m]<<endl;
		if (k1>=1e8) printf("-1\n"); else printf("%d\n",k1+A[r]-A[m]);
	}
	return 0;	
}