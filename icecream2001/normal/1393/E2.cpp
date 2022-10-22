#include <bits/stdc++.h>
using namespace std;
#define LL long long 
const LL INF=1e18;
//LL M=998244353;
int M=1000000007;

const int N=1e6+10;

LL qpow(LL x,LL y,LL P=M){
	x=x%P;
	LL re=1;
	while(y){
		if(y&1){
			re=re*x%P;
		}
		x=x*x%P;
		y>>=1;
	}
	return re;
}

void ADD(int &x,int y){
	x+=y;
	if(x>=M) x-=M;
}

int t;
int cur;
int m[2];
int dp[2][1000005];
int a[2][1000005];
char s[1000005];

#define cul cur^1

void sol_NN(){
	int flag=0;
	for(int i=1;i<=m[cul]&&i<=m[cur];++i){
		if(a[cul][i]>a[cur][i]){
			flag=-1;
			break;
		}
		if(a[cul][i]<a[cur][i]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		if(m[cul]<=m[cur]){
			flag=1;
		}
		else{
			flag=-1;
		}
	}
	if(flag==1){
		ADD(dp[cur][0],dp[cul][0]);
	}
	return;
}


int chk[1000005];
void sol_YN(){
	chk[m[cul]+1]=1;
	for(int i=m[cul];i>1;--i){
		if(m[cur]<i-1){
			chk[i]=-1;
		}
		else if(a[cul][i]<a[cur][i-1]){
			chk[i]=1;
		}
		else if(a[cul][i]>a[cur][i-1]){
			chk[i]=-1;
		}
		else {
			chk[i]=chk[i+1];
		}
	}
	for(int i=1;i<=m[cul];++i){
		if(chk[i+1]==1){
			ADD(dp[cur][0],dp[cul][i]);
		}
		if(i>m[cur]||a[cul][i]>a[cur][i]){
			break;
		}
		if(a[cul][i]<a[cur][i]){
			for(int j=i+1;j<=m[cul];++j){
				ADD(dp[cur][0],dp[cul][j]);
			}
			break;
		}
	}
	return;
}

void sol_NY(){
	if(m[cur]>m[cul]) chk[m[cur]+1]=1;
	else chk[m[cur]+1]=-1;
	for(int i=m[cur];i>1;--i){
		if(m[cul]<i-1){
			chk[i]=1;
		}
		else if(a[cul][i-1]<a[cur][i]){
			chk[i]=1;
		}
		else if(a[cul][i-1]>a[cur][i]){
			chk[i]=-1;
		}
		else {
			chk[i]=chk[i+1];
		}
	}
	for(int i=1;i<=m[cur];++i){
		if(chk[i+1]==1){
			ADD(dp[cur][i],dp[cul][0]);
		}
		if(i>m[cul]||a[cul][i]<a[cur][i]){
			for(int j=i+1;j<=m[cur];++j){
				ADD(dp[cur][j],dp[cul][0]);
			}
			break;
		}
		if(a[cul][i]>a[cur][i]){
			break;
		}
	}
	return;
}



void sol_YY0(){
	if(m[cur]+1>m[cul]) chk[m[cur]+1]=1;
	else chk[m[cur]+1]=-1;
	for(int i=m[cur];i>=1;--i){
		if(m[cul]<i){
			chk[i]=1;
		}
		else if(a[cul][i]<a[cur][i]){
			chk[i]=1;
		}
		else if(a[cul][i]>a[cur][i]){
			chk[i]=-1;
		}
		else {
			chk[i]=chk[i+1];
		}
	}
	for(int i=1;i<=min(m[cur],m[cul]);++i){
		if(chk[i+1]==1){
			ADD(dp[cur][i],dp[cul][i]);
		}
		if(a[cul][i]<a[cur][i]){
			for(int j=i+1;j<=min(m[cur],m[cul]);++j){
				ADD(dp[cur][j],dp[cul][j]);
			}
			break;
		}
		if(a[cul][i]>a[cur][i]){
			break;
		}
	}
	return;
}

int to[1000005];
int pr1[1000005],pr2[1000005];

void sol_YYL(){
	a[cur][m[cur]+1]=0;
	a[cul][m[cul]+1]=0;
	if(m[cur]+1>m[cul]) chk[m[cur]+1]=1;
	else chk[m[cur]+1]=-1;
	for(int i=m[cur];i>=1;--i){
		if(m[cul]<i){
			chk[i]=1;
		}
		else if(a[cul][i]<a[cur][i]){
			chk[i]=1;
		}
		else if(a[cul][i]>a[cur][i]){
			chk[i]=-1;
		}
		else {
			chk[i]=chk[i+1];
		}
	}
	
	
	to[m[cul]+1]=0;
	for(int i=m[cul];i>1;--i){
		if(m[cur]<i-1){
			to[i]=0;
		}
		else if(a[cul][i]==a[cur][i-1]){
			to[i]=to[i+1]+1;
		}
		else {
			to[i]=0;
		}
	}
	
	for(int i=0;i<=max(m[cur],m[cul])+1;++i){
		pr1[i]=pr2[i]=0;
	}
	
	for(int i=1;i<=m[cul];++i){
		{
//			cout<<i<<" "<<to[i+1]<<endl;
			int too=to[i+1];
			if(i+too+1<=m[cur]){
				if(i+too+1>m[cul]||a[cul][i+too+1]<a[cur][i+too]){
//					cout<<"ad "<<" "<<pr1[i+too+1]<<" "<<dp[cul][i]<<endl;
					ADD(pr1[i+too+1],dp[cul][i]);
				}
			}
			
			//i+1 i+too
			ADD(pr2[i+1],dp[cul][i]);
			ADD(pr2[i+1+too],M-dp[cul][i]);
		}
		if(i>m[cur]){
			break;
		}
		if(a[cul][i]<a[cur][i]){
			for(int j=i+1;j<=m[cul];++j){
				ADD(pr1[j+1],dp[cul][j]);
			}
			break;
		}
		if(a[cul][i]>a[cur][i]){
			break;
		}
	}
	
	for(int i=1;i<=m[cur];++i){
		ADD(pr1[i],pr1[i-1]);
		ADD(dp[cur][i],pr1[i]);
		ADD(pr2[i],pr2[i-1]);
//		cout<<"now "<<i<<" "<<chk[i+1]<<endl;
		if(chk[i+1]==1){
			ADD(dp[cur][i],pr2[i]);
		}
	}
//	for(int i=1;i<=m[cur];++i){
//		cout<<pr1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=m[cur];++i){
//		cout<<pr2[i]<<" ";
//	}
//	cout<<endl;
	return;
}


void sol_YYR(){
	a[cur][m[cur]+1]=0;
	a[cul][m[cul]+1]=0;
	chk[m[cul]+1]=1;
	for(int i=m[cul];i>=1;--i){
		if(m[cur]<i){
			chk[i]=-1;
		}
		else if(a[cul][i]<a[cur][i]){
			chk[i]=1;
		}
		else if(a[cul][i]>a[cur][i]){
			chk[i]=-1;
		}
		else {
			chk[i]=chk[i+1];
		}
	}
	
	
	to[m[cur]+1]=0;
	for(int i=m[cur];i>1;--i){
		if(m[cul]<i-1){
			to[i]=0;
		}
		else if(a[cul][i-1]==a[cur][i]){
//			cout<<"?"<<endl;
			to[i]=to[i+1]+1;
		}
		else {
			to[i]=0;
		}
	}
	
//	for(int i=2;i<=m[cur]+1;++i){
//		cout<<to[i]<<" ";
//	}
//	cout<<endl;
	
	for(int i=0;i<=max(m[cur],m[cul])+1;++i){
		pr1[i]=pr2[i]=0;
	}
	for(int i=m[cul];i>=1;--i){
		pr1[i]=dp[cul][i];
		ADD(pr1[i],pr1[i+1]);
		pr2[i]=0;
		if(chk[i+1]==1){
			pr2[i]=dp[cul][i];
		}
		ADD(pr2[i],pr2[i+1]);
	}
//	for(int i=1;i<=m[cul]+1;++i){
//		cout<<pr1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=m[cul]+1;++i){
//		cout<<chk[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=m[cul]+1;++i){
//		cout<<pr2[i]<<" ";
//	}
//	cout<<endl;
	
	
	for(int i=1;i<=m[cur];++i){
		{
//			cout<<i<<" "<<to[i+1]<<endl;
			int too=to[i+1];
			if(i+too+1<=m[cul]){
				if(i+too+1<=m[cur]&&a[cur][i+too+1]>a[cul][i+too]){
//					ADD(pr1[i+too+1],dp[cul][i]);
//cout<<pr1[i+too+1]<<endl;
					ADD(dp[cur][i],pr1[i+too+1]);
				}
			}
			
			//i+1 i+too
			ADD(dp[cur][i],pr2[i+1]);
			ADD(dp[cur][i],M-pr2[i+1+too]);
		}
		if(i>m[cul]){
			break;
		}
		if(a[cul][i]<a[cur][i]){
			for(int j=i+1;j<=m[cur];++j){
				ADD(dp[cur][j],pr1[j+1]);
//				ADD(pr1[j+1],dp[cul][j]);
			}
			break;
		}
		if(a[cul][i]>a[cur][i]){
			break;
		}
	}
//	for(int i=1;i<=m[cur];++i){
//		ADD(pr1[i],pr1[i-1]);
//		ADD(dp[cur][i],pr1[i]);
//		ADD(pr2[i],pr2[i-1]);
//		if(chk[i+1]){
//			ADD(dp[cur][i],pr2[i]);
//		}
//	}
	
	return;
}

void MAIN(){
	scanf("%d",&t);
//	cin>>t;
	cur=1;
	
//	cin>>s;
	scanf("%s",s);
	m[cur]=strlen(s);
	dp[cur][0]=1;
	for(int i=1;i<=m[cur];++i){
		a[cur][i]=s[i-1]-'a'+1;
		dp[cur][i]=1;
	}
	
	t--;
	while(t>0){
		t--;cur^=1;
		cin>>s;m[cur]=strlen(s);
		dp[cur][0]=0;
		for(int i=1;i<=m[cur];++i){
			a[cur][i]=s[i-1]-'a'+1;
			dp[cur][i]=0;
		}
		
		// NN
		sol_NN();
		
		sol_YN();
		
		sol_NY();
		
		sol_YY0();
		
		sol_YYL();
//		
		sol_YYR();
//		for(int i=0;i<=m[cur];++i){
//			cout<<dp[cur][i]<<" ";
//		}
//		cout<<endl;
	}
	int ans=0;
	for(int i=0;i<=m[cur];++i){
		ADD(ans,dp[cur][i]);
	}
//	cout<<qpow((LL)10,12,M)<<endl;
	cout<<ans<<endl;
	return;
}
int main(){
//	init();
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int ttt=1;//cin>>ttt;
	while(ttt--) MAIN();
	return 0;
}