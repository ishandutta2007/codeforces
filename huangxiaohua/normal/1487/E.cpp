#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
struct sb{
	int id,num;
	bool operator<(const sb x)const{return num<x.num;}
}s[5][150500];
unordered_map<int,unordered_map<int,int> > mp[5];

int i,j,k,n,m[5],sb,x,y,res=1145141919,dp[5][150500];

int main(){
	for(i=1;i<=4;i++){
		scanf("%d",&m[i]);
	}
	for(i=1;i<=4;i++){
		for(j=1;j<=m[i];j++){
			s[i][j].id=j;
			scanf("%d",&s[i][j].num);
			dp[i][j]=s[i][j].num;
		}
	}
	for(i=2;i<=4;i++){
		scanf("%d",&sb);
		for(j=1;j<=sb;j++){
			scanf("%d%d",&x,&y);
			mp[i][y][x]=1;
		}
	}
	for(i=2;i<=4;i++){
		sort(s[i-1]+1,s[i-1]+1+m[i-1]);
		for(j=1;j<=m[i];j++){
			s[i][j].num=1145141919;
			for(k=1;k<=m[i-1];k++){
				if(mp[i][s[i][j].id][s[i-1][k].id]){continue;}
				s[i][j].num=dp[i][j]+s[i-1][k].num;break;
			}
		}
	}
	for(i=1;i<=m[4];i++){
		res=min(res,s[4][i].num);
	}
	printf("%d",(res==1145141919)?-1:res);
}