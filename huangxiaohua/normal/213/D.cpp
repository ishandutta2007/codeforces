#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,it;
bool vis[666][666],mp[666][666];
const double pi=3.1415926535897932,deg=pi/180,len=5/sin(36*deg);
struct sb{
	double x,y;
}s[666];

void dfs(int x){
	int i;
	printf("%d ",x);
	for(i=x+1;i<=m;i++){
		if(mp[x][i]&&!vis[x][i]){
			vis[x][i]=vis[i][x]=1;
			dfs(i);
		}
	}
	for(i=x-1;i>=1;i--){
		if(mp[x][i]&&!vis[x][i]){
			vis[x][i]=vis[i][x]=1;
			dfs(i);
		}
	}
}

int main(){
	for(i=1;i<=5;i++){
		s[i].x=len*cos((306-72*i)*deg);
		s[i].y=len*sin((306-72*i)*deg);
	}
	it=4;
	for(j=1;it<=400;j++){
		if(j&1){
			s[it+4].y=s[it].y;
			s[it+4].x=s[it].x+10;it+=4;
		}
		else{
			s[it+2].y=s[it].y;
			s[it+2].x=s[it].x+s[4].x-s[2].x;it+=2;
		}
	}
	
	it=5;
	for(j=1;it<=400;j++){
		if(!(j&1)){
			s[it+4].y=s[it].y;
			s[it+4].x=s[it].x+10;it+=4;
		}
		else{
			s[it+2].y=s[it].y;
			s[it+2].x=s[it].x+s[4].x-s[2].x;it+=2;
		}
	}
	
	it=3;
	for(;it<=400;it+=6){
		s[it+6].y=s[it].y;
		s[it+6].x=s[it].x+10+2*s[4].x;
	}
	
	s[6].y=s[4].y-s[3].y+s[1].y;
	s[6].x=(s[4].x+s[8].x)/2;
	
	it=6;
	for(;it<=400;it+=6){
		s[it+6].y=s[it].y;
		s[it+6].x=s[it].x+10+2*s[4].x;
	}
	
	scanf("%d",&n);m=2+3*n;
	printf("%d\n",m);
	for(i=1;i<=m;i++){
		printf("%.20lf %.20lf\n",s[i].x,s[i].y);
	}
	for(i=0;i<n;i++){
		printf("%d %d %d %d %d\n",i*3+1,i*3+2,i*3+3,i*3+4,i*3+5);
	}
	for(i=1;i<=m;i++){
		if(i+2<=m){mp[i][i+2]=mp[i+2][i]=1;}
		if(i%3&&i+3<=m){mp[i][i+3]=mp[i+3][i]=1;}
	}
	for(i=2;i<m;i+=3){
		printf("%d ",i);
		vis[i][i+3]=vis[i+3][i]=1;
	}
	dfs(m);
}