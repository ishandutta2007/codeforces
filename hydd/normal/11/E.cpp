#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const double INF=1e18;
char t[1100000]; int n,tot;
string s; double dp[2100000][2];
bool check(string &s,double mid){
	int n=(int)s.length();
	dp[0][1]=0; dp[0][0]=-mid;
	for (int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][1]+(s[i-1]=='L')-mid;
		dp[i][1]=dp[i-1][0]+(s[i-1]=='R')-mid;
		dp[i][0]=max(dp[i][0],dp[i][1]-mid);
		dp[i][1]=max(dp[i][1],dp[i][0]-mid);
	}
	return (dp[n][1]>0);
}
double work(string s){
	double l=0,r=1,mid;
	for (int i=0;i<=40;i++){
		mid=(l+r)*.5;
		if (check(s,mid)) l=mid;
		else r=mid;
	}
	if (n&1) return max(1.*tot/n,r);
	else return r;
}
int main(){
	scanf("%s",t+1); n=strlen(t+1);
	s=t[1];
	for (int i=2;i<=n;i++){
		if (t[i]!='X'){
			if (t[i-1]==t[i]) s+='X';
			tot++;
		}
		s+=t[i];
	}
	if (s.front()==s.back()){
		if (s.front()=='L') printf("%.6lf\n",int(work(s+'X')*1e8)/1e6);
		else printf("%.6lf\n",int(work('X'+s)*1e8)/1e6);
	} else printf("%.6lf\n",int(work(s)*1e8)/1e6);
	return 0;
}