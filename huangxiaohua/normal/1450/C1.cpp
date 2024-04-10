#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,res,sum,tmp,sum1,sum2,sum3;
char sb[305][305];

int chkx(int a,int b,int c,int d){
	if(d<1||b<1||c<1||d>n||b>n||c>n){return 0;}
	if(sb[a][b]=='X'&&sb[a][c]=='X'&&sb[a][d]=='X'){return 1;}
	return 0;
}

int chky(int a,int b,int c,int d){
	if(d<1||b<1||c<1||d>n||b>n||c>n){return 0;}
	if(sb[b][a]=='X'&&sb[c][a]=='X'&&sb[d][a]=='X'){return 1;}
	return 0;
}

void print(){
	int i;
	for(i=1;i<=n;i++){cout<<sb[i]+1<<endl;}
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;

		for(i=1;i<=n;i++){
			cin>>sb[i]+1;
		}
		k=0;sum1=sum2=sum3=0;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tmp=0;
				if(((i%3)+(j%3))%3!=0){continue;}
				tmp+=chkx(i,j-2,j-1,j);
				tmp+=chkx(i,j-1,j,j+1);
				tmp+=chkx(i,j,j+1,j+2);
				tmp+=chky(j,i-2,i-1,i);
				tmp+=chky(j,i-1,i,i+1);
				tmp+=chky(j,i,i+1,i+2);
				if(tmp){sum1++;sb[i][j]='O';}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(sb[i][j]=='O'){sb[i][j]='X';}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tmp=0;
				if(((i%3)+(j%3))%3!=1){continue;}
				tmp+=chkx(i,j-2,j-1,j);
				tmp+=chkx(i,j-1,j,j+1);
				tmp+=chkx(i,j,j+1,j+2);
				tmp+=chky(j,i-2,i-1,i);
				tmp+=chky(j,i-1,i,i+1);
				tmp+=chky(j,i,i+1,i+2);
				if(tmp){sum2++;sb[i][j]='O';}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(sb[i][j]=='O'){sb[i][j]='X';}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tmp=0;
				if(((i%3)+(j%3))%3!=2){continue;}
				tmp+=chkx(i,j-2,j-1,j);
				tmp+=chkx(i,j-1,j,j+1);
				tmp+=chkx(i,j,j+1,j+2);
				tmp+=chky(j,i-2,i-1,i);
				tmp+=chky(j,i-1,i,i+1);
				tmp+=chky(j,i,i+1,i+2);
				if(tmp){sum3++;sb[i][j]='O';}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(sb[i][j]=='O'){sb[i][j]='X';}
			}
		}
		
		if(sum1<=sum2&&sum1<=sum3){
			for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tmp=0;
				if(((i%3)+(j%3))%3!=0){continue;}
				tmp+=chkx(i,j-2,j-1,j);
				tmp+=chkx(i,j-1,j,j+1);
				tmp+=chkx(i,j,j+1,j+2);
				tmp+=chky(j,i-2,i-1,i);
				tmp+=chky(j,i-1,i,i+1);
				tmp+=chky(j,i,i+1,i+2);
				if(tmp){sb[i][j]='O';}
			}
			}
			goto aaa;
		}
		
		if(sum2<=sum1&&sum2<=sum3){
			for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tmp=0;
				if(((i%3)+(j%3))%3!=1){continue;}
				tmp+=chkx(i,j-2,j-1,j);
				tmp+=chkx(i,j-1,j,j+1);
				tmp+=chkx(i,j,j+1,j+2);
				tmp+=chky(j,i-2,i-1,i);
				tmp+=chky(j,i-1,i,i+1);
				tmp+=chky(j,i,i+1,i+2);
				if(tmp){sb[i][j]='O';}
			}
			}
			goto aaa;
		}
		
		if(sum3<=sum2&&sum3<=sum1){
			for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tmp=0;
				if(((i%3)+(j%3))%3!=2){continue;}
				tmp+=chkx(i,j-2,j-1,j);
				tmp+=chkx(i,j-1,j,j+1);
				tmp+=chkx(i,j,j+1,j+2);
				tmp+=chky(j,i-2,i-1,i);
				tmp+=chky(j,i-1,i,i+1);
				tmp+=chky(j,i,i+1,i+2);
				if(tmp){sb[i][j]='O';}
			}
			}
			goto aaa;
		}
		
		aaa:
		for(i=1;i<=n;i++){
			cout<<sb[i]+1<<endl;
		}
	}
}