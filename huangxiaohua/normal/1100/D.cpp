#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[1050][1050],x,y,sb[1050][2],s1,s2,s3,s4;

void get(){
	int i,j,k;
	scanf("%d%d%d",&i,&j,&k);
	if(i==-1){exit(0);}
	f[sb[i][0]][sb[i][1]]=0;
	f[j][k]=1;
	sb[i][0]=j;sb[i][1]=k;
}

void ask(int dx,int dy){
	while(1){
		j=x+dx;k=y+dy;
		if(f[j][k]){printf("%d %d\n",j,y);}
		else{printf("%d %d\n",j,k);}
		x=j;y=k;
		fflush(stdout);
		get();
	}
}

int main() {
	scanf("%d%d",&x,&y);
	for(i=1;i<=666;i++){
		scanf("%d%d",&j,&k);
		sb[i][0]=j;sb[i][1]=k;
		f[j][k]=1;
	}
	while(x!=500||y!=500){
		j=500;
		if(x>500){j=x-1;}
		if(x<500){j=x+1;}
		k=500;
		if(y>500){k=y-1;}
		if(y<500){k=y+1;}
		if(f[j][k]){printf("%d %d\n",j,y);}
		else{printf("%d %d\n",j,k);}
		x=j;y=k;
		fflush(stdout);
		get();
	}
	for(i=1;i<=500;i++){
		for(j=1;j<=500;j++){
			s1+=f[i][j];
		}
	}
	for(i=500;i<=999;i++){
		for(j=1;j<=500;j++){
			s2+=f[i][j];
		}
	}
	for(i=1;i<=500;i++){
		for(j=500;j<=999;j++){
			s3+=f[i][j];
		}
	}
	for(i=500;i<=999;i++){
		for(j=500;j<=999;j++){
			s4+=f[i][j];
		}
	}
	if(s4<=166){ask(-1,-1);}
	if(s3<=166){ask(1,-1);}
	if(s2<=166){ask(-1,1);}
	if(s1<=166){ask(1,1);}
}