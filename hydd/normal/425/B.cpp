#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,c[110],pc[2100],u[110][110],v[110][110];
bitset<110> a[110],b[110];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
int main(){
//	freopen("table.in","r",stdin);
//	freopen("table.out","w",stdout);
	pc[0]=0; for (int s=1;s<2048;s++) pc[s]=pc[s>>1]+(s&1);
	T=1;
	while (T--){
		n=read(); m=read(); k=read();//Tnmk
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				v[i][j]=read();
		if (n<m){
			swap(n,m);
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					u[i][j]=v[j][i];
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					v[i][j]=u[i][j];
		}
		int x;
		for (int i=0;i<n;i++){
			a[i]=0; b[i]=0; c[i]=0;
			for (int j=0;j<m;j++){
				x=v[i][j];
				a[i][j]=x; b[i][j]=x^1; c[i]=(c[i]<<1)|x;
			}
		}
		int ans=k+1;
		if (n>k){
			for (int i=0;i<n;i++){
				int res=0;
				for (int j=0;j<n&&res<=k;j++)
					res+=min((a[i]^a[j]).count(),(a[i]^b[j]).count());
				ans=min(ans,res);
			}
			if (ans==k+1) puts("-1");
			else printf("%d\n",ans);
		} else{
			int upperlim=(1<<m)-1;
			for (int s=0;s<=upperlim;s++){
				int t=s^upperlim,res=0;
				for (int i=0;i<n&&res<=k;i++)
					res+=min(pc[s^c[i]],pc[t^c[i]]);
				ans=min(ans,res);
			}
			if (ans==k+1) puts("-1");
			else printf("%d\n",ans);
		}
	}
	return 0;
}