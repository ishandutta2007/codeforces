//Time Complexity : O(N)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
const int N=5e6;
int main(){
	char S[N+1]="";
	scanf("%s",S);
	int n=strlen(S);
	char S0[N*2+2]="##";
	for(int i=0;i<=n-1;++i){
		S0[i*2+2]=S[i];
		S0[i*2+3]='#';
	}
	int n0=n*2+2,MaxRight=1,Mid=0;
	vector<int>Radius(n0);
	for(int i=1;i<=n0-1;++i){
		Radius[i]=i<MaxRight?min(Radius[Mid*2-i],MaxRight-i):1;
		while(S0[i-Radius[i]]==S0[i+Radius[i]]){
			++Radius[i];
		}
		if(i+Radius[i]>MaxRight){
			MaxRight=i+Radius[i];
			Mid=i;
		}
	}
	vector<int>dp(n);
	dp[0]=1;
	for(int i=1;i<=n-1;++i){
		dp[i]=Radius[i+2]==i+2?dp[(i-1)/2]+1:0;
	}
	int Ans=0;
	for(int i=0;i<=n-1;++i){
		Ans=Ans+dp[i];
	}
	printf("%d\n",Ans);
	return 0;
}