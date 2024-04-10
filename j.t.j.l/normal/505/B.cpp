#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,m,i,j,p,q,x,y,z,t,tot;
int father[111][111];

int getfather(int op,int w){
	if (father[op][w]==w)
		return w;
	else{
		father[op][w]=getfather(op,father[op][w]);
		return father[op][w];
	}
}

int main(){
	cin>>n>>m;
	rep(i,1,m)
		rep(j,1,n)
			father[i][j]=j;
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		p=getfather(z,x);
		q=getfather(z,y);
		if (p!=q)
			father[z][p]=q;
	}
	cin>>t;
	rep(i,1,t){
		scanf("%d%d",&x,&y);
		tot=0;
		rep(j,1,m){
			p=getfather(j,x);
			q=getfather(j,y);
			if (p==q)
				tot++;
		}
		printf("%d\n",tot);
	}
	return 0;
}