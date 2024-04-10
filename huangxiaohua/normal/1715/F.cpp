#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
double len[666],sb,w1,w2,w3,w4,x,y;

void ask(double x,double y){
	printf("%.15lf %.15lf\n",x,y);
	fflush(stdout);
}

int main(){
	cin>>n>>m;
	
	printf("? %d\n",n*2+2);
	ask(0,m+1);
	ask(0,0);
	for(i=1;i<=n;i++){
		ask(i,m);
		if(i!=n)ask(i,0);
		else ask(i,m+1);
	}
	scanf("%lf",&y);
	y=y*m-0.5;
	
	printf("? %d\n",m*2+2);
	ask(n+1,0);
	ask(0,0);
	for(i=1;i<=m;i++){
		ask(n,i);
		if(i!=m)ask(0,i);
		else ask(n+1,i);
	}
	scanf("%lf",&x);
	x=x*n-0.5;
	
	printf("! %.15lf %.15lf",x,y);
	fflush(stdout);
}