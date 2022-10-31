#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,f[1050][1050],res;

struct sb{
	int x,y;
	bool operator<(const sb a)const{return x<a.x;}
}s[6];

int main(){
	for(i=1;i<=3;i++){
		scanf("%d%d",&s[i].x,&s[i].y);
	}
	sort(s+1,s+4);
	for(i=min({s[1].y,s[2].y,s[3].y});i<=max({s[1].y,s[2].y,s[3].y});i++){
		f[s[2].x][i]=1;
	}
	for(i=s[1].x;i<=s[2].x;i++){
		f[i][s[1].y]=1;
	}
	for(i=s[2].x;i<=s[3].x;i++){
		f[i][s[3].y]=1;
	}
	for(i=0;i<=1005;i++){
		for(j=0;j<=1005;j++){
			res+=f[i][j];
		}
	}
	printf("%d\n",res);
	for(i=0;i<=1005;i++){
		for(j=0;j<=1005;j++){
			if(f[i][j]){
				printf("%d %d\n",i,j);
			}
		}
	}
}