#include<bits/stdc++.h>
using namespace std;
int h,m,x,y;
char c[10];
bool vis[10];
void work(){
	scanf("%d%d%s",&h,&m,c);
	x=(c[0]-'0')*10+c[1]-'0';
	y=(c[3]-'0')*10+c[4]-'0';
	while(1){
		if(vis[y%10]&&vis[y/10]&&vis[x%10]&&vis[x/10]){
			int l,r;
			if(y%10==2)l=50;
			else if(y%10==5)l=20;
			else l=y%10*10;
			if(y/10==2)l+=5;
			else if(y/10==5)l+=2;
			else l+=y/10;
			if(x%10==2)r=50;
			else if(x%10==5)r=20;
			else r=x%10*10;
			if(x/10==2)r+=5;
			else if(x/10==5)r+=2;
			else r+=x/10;
			
			if(l<h&&r<m){
				printf("%02d:%02d\n",x,y);
				break;
			}
		}
		y++;	
		if(y==m)y=0,x++;
		if(x==h)x=0;
	}
}
int main(){
	int T;
	vis[0]=vis[1]=vis[2]=vis[5]=vis[8]=1;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}