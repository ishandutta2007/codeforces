//https://codeforces.com/contest/1276/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N=400005;
vector<int> f[633];
int a[N];
struct qwq{
	int x,y;
	inline qwq(){}
	inline qwq(int x,int y):x(x),y(y){}
	inline bool operator<(const qwq &a)const{
		return x>a.x;
	}
}p[N];
int main(){
	int n,k=0,i,j,t,jj,mm=0,x=1,y=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=j=1;i<=n;i=j){
		while(a[i]==a[j])++j;
		p[++k]=qwq(j-i,a[i]);
	}
	sort(p+1,p+k+1);
	for(j=1;j*j<=n;++j){
		t=0;
		for(i=1;i<=k;++i)t+=min(p[i].x,j);
		if(t<j*j)break;
		if((t=j*(t/j))>mm){mm=t;jj=j;}
	}
	j=jj;
	t=0;
	for(i=1;i<=k;++i)t+=min(p[i].x,j);
	t/=j;
	printf("%d\n%d %d\n",mm=t*j,j,t);
	for(i=1;i<=j;++i)f[i].resize(t+1);
	for(i=1;i<=k;++i)if(p[i].x>j)p[i].x=j;
	jj=i=1;
	while(mm--){
		f[x][y]=p[i].y;
		if(x==j){x=1;y=++jj;}
		else{
			x=(x==j)?1:x+1;
			y=(y==t)?1:y+1;
		}
		if(!(--p[i].x))++i;
	}
	for(x=1;x<=j;++x){
		for(y=1;y<=t;++y)printf("%d ",f[x][y]);
		printf("\n");
	}
	return 0;
}