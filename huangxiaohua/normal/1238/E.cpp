#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
#define b(x) (1<<((x)-1))
int i,j,k,n,m,x,y,f[25][25],dp[1100000],s1[20],s2[20];
char sb[100500];

void get(int x){
	int res=1e9,res2=0;
	int i,j,k,m1=0,m2=0;
	for(i=1;i<=m;i++){
		if(x&b(i)){
			s1[++m1]=i;
			if(dp[x^b(i)]<res){res=dp[x^b(i)];}
		}
		else{s2[++m2]=i;}
	}
	for(i=1;i<=m1;i++){
		for(j=1;j<=m2;j++){
			res2+=f[s1[i]][s2[j]];
			res2+=f[s2[j]][s1[i]];
		}
	}
	dp[x]=res+res2;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>sb+1;
	for(i=2;i<=n;i++){
		j=sb[i-1]-'a'+1;k=sb[i]-'a'+1;
		f[j][k]++;
	}
	for(i=1;i<b(m+1);i++){
		get(i);
	}
	cout<<dp[b(m+1)-1];
}