#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,s[100005],c[100005],t[100005][2];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		for(int i=1;i<=100000;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[s[i]]++;
		for(int i=1;i<=100000;i++)c[i]+=c[i-1];
		for(int i=1;i<=100000;i++){
			t[i][0]=t[i][1]=0;
			for(int j=c[i-1]+1;j<=c[i];j++)t[i][j&1]++;
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			int x=s[i];
			if(!t[x][i&1])flag=0;
			else t[x][i&1]--;
		}
		puts(flag?"YES":"NO");
	}
}