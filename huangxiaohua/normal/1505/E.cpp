#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,x,y,t,res,l;
char mp[66][66];

struct sb{
	int x,y,dx,dis;
	bool operator<(const sb a)const{
		if(dis==a.dis){return dx<a.dx;}
		return dis<a.dis;
	}
}s[666];

void chk(int x,int y){
	//printf("%d %d\n",x,y);
	int i,j;
	l=0;
	for(i=x;i<=n;i++){
		for(j=y;j<=m;j++){
			if(i==x&&j==y){continue;}
			if(mp[i][j]=='*'){
				s[++l].x=i;
				s[l].y=j;
				s[l].dis=i+j-x-y;
				s[l].dx=i-x;
			}
		}
	}
	if(!l){return;}
	res++;
	sort(s+1,s+l+1);
	chk(s[1].x,s[1].y);
}

int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>mp[i]+1;
	}
	if(mp[1][1]=='*'){res++;}
	chk(1,1);
	cout<<res;
}