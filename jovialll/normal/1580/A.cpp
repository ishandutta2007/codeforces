#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 405
#define pb push_back
#define pn cout<<"No\n";
#define py cout<<"Yes\n";
int T,n,f[N],m,MN,ans,c[N],a[N],i,j,x,y,F[N],S[N];
char s[N][N];
void calc(int x,int y){
	int i;
	for(i=1;i<=m;++i){
		F[i]=y-x-1-(c[i]-s[x][i]+'0'-s[y][i]+'0');
	}
	for(i=1;i<=m;++i){
		S[i]=c[i]+S[i-1];
		if(s[x][i]=='1')S[i]-=1;
		else S[i]+=1;
		if(s[y][i]=='1')S[i]-=1;
		else S[i]+=1;
	}
	MN=-1e9;
	for(i=1;i<=m;++i){
		if(i>=4){
			MN=max(MN,S[i-3]-F[i-3]);
			ans=min(ans,F[i]+S[i-1]-MN);
		}
	}
}
int k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)scanf("%s",s[i]+1);
		ans=123456;
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j)c[j]=0; 
			for(j=i;j<=n;++j){
				for(k=1;k<=m;++k)c[k]+=s[j][k]=='1';
				if(j-i>=4)calc(i,j);
			}
		}
		cout<<ans<<"\n";
	}
}