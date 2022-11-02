#include <stdio.h>
#include <iostream>
#include <iomanip>
#define MAXN 1050
#define MAXK 105

using namespace std;

int n,k;
double p1[MAXN];
double dp[MAXN][MAXN];

inline long long min(long long a,long long b) { return a<b?a:b; }

inline long long nStart1(long long x) {
	long long m=1,s=0;
	while(m<=x) {
		s+=min(m,x-m+1);
		if(m>x/10) break;
		m*=10;
	}
	return s;
}

inline double solve() {
	int i,j;
	double sol=0.0;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			dp[i][j]=0.0;
	dp[0][0]=1.0;
	for(i=0;i<n;i++) {
		for(j=0;j<=n;j++) {
			if(j<n) dp[i+1][j+1]+=dp[i][j]*p1[i];
			dp[i+1][j]+=dp[i][j]*(1.0-p1[i]);
		}
	}
	for(j=k;j<=n;j++)
		sol+=dp[n][j];
	return sol;
}

int main(void)
{
	int i,kp;
	long long lb,rb,l1,r1;
	while(cin>>n) {
		for(i=0;i<n;i++) {
			cin>>lb>>rb;
			l1=nStart1(lb-1);
			r1=nStart1(rb);
			p1[i]=(long double)(r1-l1)/(rb-lb+1);
		}
		cin>>kp;
		k=(n*kp+99)/100;
		cout<<setprecision(12)<<solve()<<endl;
	}
}