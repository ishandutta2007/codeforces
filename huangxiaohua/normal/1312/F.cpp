#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,x,y,z,f[2005][5],f2[2005],nxt[2005],t,res,ans,m,tmp;
ll sb[300500];
int mex(int a,int b,int c){
	for(int i=0;;i++){if(i!=a&&i!=b&&i!=c){return i;}}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&x,&y,&z);
		memset(f,0,sizeof(f));
		for(i=1;i<=2000;i++){
			f[i][0]=mex(f[max(0,i-x)][0],f[max(0,i-y)][1],f[max(0,i-z)][2]);
			f[i][1]=mex(f[max(0,i-x)][0],99,f[max(0,i-z)][2]);
			f[i][2]=mex(f[max(0,i-x)][0],f[max(0,i-y)][1],99);
			f2[i]=f[i][0]+f[i][1]*10+f[i][2]*100;
		}
		j=m=res=ans=0;
		for(i=1002;i<=2000;i++){
			while(j&&f2[j+1001]!=f2[i]){j=nxt[j];}
			if(f2[j+1001]==f2[i]){j++;}
			nxt[i-1000]=j;
		}
		for(i=1;i<=1000;i++){
			if(nxt[i]*2==i){m=max(m,i/2);}
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&sb[i]);
			if(sb[i]>=100){
				sb[i]%=m;sb[i]+=((100-sb[i])/m)*m;
				res^=f[sb[i]][0];
			}
			else{
				res^=f[sb[i]][0];
			}
		}
		for(i=1;i<=n;i++){
			res^=f[sb[i]][0];
			if(!(res^f[max(0ll,sb[i]-x)][0])){ans++;}
			if(!(res^f[max(0ll,sb[i]-y)][1])){ans++;}
			if(!(res^f[max(0ll,sb[i]-z)][2])){ans++;}
			res^=f[sb[i]][0];
		}
		printf("%d\n",ans);
	}
}