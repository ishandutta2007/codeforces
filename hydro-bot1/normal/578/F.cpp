// Hydro submission #624f15a3fcdfb741b9e5f4e6@1649350051533
#include<bits/stdc++.h>
using namespace std;
#define maxn 109 
#define maxk 509 
long long mod,mra[2][maxk][maxk];
int n,m,toa=0,tob=0,f[maxn*maxn],d[maxn*maxn],opt[maxn*maxn];
char mps[maxn][maxn];
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
int id(int x,int y){
	return (x-1)*(m+1)+y;
}
int lf(int x){return f[x]^x?f[x]=lf(f[x]):x;}
void meg(int x,int y){x=lf(x);y=lf(y);f[y]=x;return ;}
void put(){
//	puts("QWQ");
	for(int i=1;i<=toa;i++){
		for(int j=1;j<=toa;j++){
			mra[0][i][j]=(mra[0][i][j]+mod)%mod;
//			cout<<mra[0][i][j]<<" ";
		}
//		cout<<endl;
	}
//	puts("QWQ");
	for(int i=1;i<=tob;i++){
		for(int j=1;j<=tob;j++){
			mra[1][i][j]=(mra[1][i][j]+mod)%mod;
//			cout<<mra[1][i][j]<<" ";
		}
//		cout<<endl;
	}
//	puts("QWQ");
	return ;
}
int main(){
//    freopen("qwq.in","r",stdin);
//    freopen(".out","w",stdout);
	n=read(),m=read(),mod=read();
	for(int i=1;i<=id(n+1,m+1);i++)f[i]=i;
	for(int i=1;i<=n;i++){
		cin>>mps[i]+1;
		for(int j=1;j<=m;j++){
			if(mps[i][j]==47){// /
				meg(id(i+1,j),id(i,j+1));
			}
			if(mps[i][j]==92){// \/
				meg(id(i,j),id(i+1,j+1));
			}
		}
	} 
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			int k=id(i,j);
			if(lf(k)==k){
				if((i+j)%2)d[k]=++toa,opt[k]=0;
				else d[k]=++tob,opt[k]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mps[i][j]=='*'){
//				cout<<"QAQ "<<i<<" "<<j<<endl;
				int du,dv;
				du=lf(id(i,j));dv=lf(id(i+1,j+1));
				int u=d[du],v=d[dv]; 
//				cout<<u<<" "<<v<<endl;
				mra[opt[du]][u][v]--;mra[opt[du]][v][u]--;mra[opt[du]][u][u]++;mra[opt[du]][v][v]++;
				du=lf(id(i+1,j));dv=lf(id(i,j+1));
				u=d[du],v=d[dv];
//				cout<<u<<" "<<v<<endl;
				mra[opt[du]][u][v]--;mra[opt[du]][v][u]--;mra[opt[du]][u][u]++;mra[opt[du]][v][v]++;
			}
		}
	} 
	put();
	long long ans=1,sum=0;
	for(int i=1;i<toa;i++){
		for(int j=i+1;j<toa;j++){
			while(mra[0][j][i]){
				long long x=mra[0][i][i]/mra[0][j][i];x%=mod;
				for(int k=1;k<toa;k++){
					mra[0][i][k]-=x*mra[0][j][k]%mod;
					mra[0][i][k]%=mod;
					if(mra[0][i][k]<0)mra[0][i][k]+=mod;
				}
				for(int k=1;k<toa;k++)swap(mra[0][i][k],mra[0][j][k]);
				ans=-ans;
			}
		}
	}
	for(int i=1;i<toa;i++)ans=(ans*mra[0][i][i])%mod;if(mra[0][toa][toa]==0)ans=0;sum=(sum+ans)%mod;
//	cout<<sum<<endl;
	ans=1;
	for(int i=1;i<tob;i++){
		for(int j=i+1;j<tob;j++){
			while(mra[1][j][i]){
				long long x=mra[1][i][i]/mra[1][j][i];x%=mod;
				for(int k=1;k<tob;k++){
					mra[1][i][k]-=x*mra[1][j][k]%mod;
					mra[1][i][k]%=mod;
					if(mra[1][i][k]<0)mra[1][i][k]+=mod;
				}
				for(int k=1;k<tob;k++)swap(mra[1][i][k],mra[1][j][k]);
				ans=-ans;
			}
		}
	}
	for(int i=1;i<tob;i++)ans=(ans*mra[1][i][i])%mod;if(mra[1][tob][tob]==0)ans=0;sum=(sum+ans)%mod;
	if(toa==1||tob==1)sum=(sum+1)%mod;
	sum=(sum+mod)%mod;
	cout<<sum;
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}