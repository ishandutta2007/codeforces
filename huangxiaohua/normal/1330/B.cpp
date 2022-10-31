#include <bits/stdc++.h>
using namespace std;

int read(){
	char c=getchar();int ans=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return ans;
}

int n,t,i,a[200500],mexa[200500],mexb[200500],b[200500],sb[200500],res[200500][2],rn;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		mexa[0]=mexb[n+1]=1;
		memset(a,0,(n+10)*4);rn=0;
		memset(b,0,(n+10)*4);
		memset(sb,0,(n+10)*4);
		for(i=1;i<=n;i++){
			sb[i]=read();
			mexa[i]=mexa[i-1];
			a[sb[i]]=1;
			while(a[mexa[i]]){mexa[i]++;}
		}
		for(i=n;i>=1;i--){
			mexb[i]=mexb[i+1];
			b[sb[i]]=1;
			while(b[mexb[i]]){mexb[i]++;}
		}
		for(i=1;i<=n;i++){
			//printf("%d %d\n",mexa[i],mexb[i]);
			if(mexa[i]==i+1&&mexb[i+1]==n-i+1){
				rn++;res[rn][0]=i;res[rn][1]=n-i;
			}
		}
		printf("%d\n",rn);
		for(i=1;i<=rn;i++){
			printf("%d %d\n",res[i][0],res[i][1]);
		}
	}
}