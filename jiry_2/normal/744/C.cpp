#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1<<16][300];
int A[1<<16],B[1<<16];
struct atom{
	int x,y,pd;
}x[20];
int n;
char ch[20];
void update(int &k1,int k2){
	k1=min(k1,k2);
}
int main(){
	scanf("%d",&n);
	int ans=0,remx=0,remy=0;
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1); int k1,k2; scanf("%d%d",&k1,&k2);
		if (k1>n){
			remx+=k1-n; k1=n;
		}
		if (k2>n){
			remy+=k2-n; k2=n;
		}
		if (ch[1]=='R') x[i]=(atom){k1,k2,0}; else x[i]=(atom){k1,k2,1};
	}
	for (int i=1;i<(1<<n);i++)
		for (int j=1;j<=n;j++)
			if (i&(1<<j-1)){
				A[i]=A[i-(1<<j-1)];
				B[i]=B[i-(1<<j-1)];
				if (x[j].pd==0) A[i]++; else B[i]++;
				break;
			}
	memset(dp,0x3f,sizeof dp); dp[0][0]=0;
	const int lim=n*n;
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<=lim;j++)
			if (dp[i][j]<1e9){
			//	cout<<"ad "<<i<<" "<<j<<" "<<dp[i][j]<<" "<<A[i]<<" "<<B[i]<<endl;
				for (int k=1;k<=n;k++)
					if ((i&(1<<k-1))==0)
						update(dp[i+(1<<k-1)][j+max(0,x[k].x-A[i])],dp[i][j]+max(0,x[k].y-B[i]));
			}
	ans=1e9;
	for (int i=0;i<=lim;i++){
	//	cout<<"asd "<<i<<" "<<dp[(1<<n)-1][i]<<" "<<remx<<" "<<remy<<endl;
		ans=min(ans,max(i+remx,dp[(1<<n)-1][i]+remy));
	}
//	cout<<ans<<endl;
	cout<<ans+n<<endl;
	return 0;
}