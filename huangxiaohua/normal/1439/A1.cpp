#include<bits/stdc++.h>
using namespace std;
#define N 55
#define M 1000000007
#define ans(x,b,c,d,e,f) \
		rn++;\
		res[rn][1]=x;\
		res[rn][2]=b;\
		\
		res[rn][3]=c;\
		res[rn][4]=d;\
		\
		res[rn][5]=e;\
		res[rn][6]=f;\
		a[x][b]^=1; a[c][d]^=1; a[e][f]^=1;
		
#define del1() ans(a1,b1,a2,b2,a4,b4);ans(a1,b1,a3,b3,a4,b4);ans(a1,b1,a2,b2,a3,b3);return;
#define del2() ans(a1,b1,a2,b2,a3,b3);ans(a2,b2,a3,b3,a4,b4);ans(a1,b1,a2,b2,a4,b4);return;
#define del3() ans(a1,b1,a2,b2,a3,b3);ans(a2,b2,a3,b3,a4,b4);ans(a3,b3,a1,b1,a4,b4);return;
#define del4() ans(a4,b4,a2,b2,a3,b3);ans(a2,b2,a4,b4,a1,b1);ans(a3,b3,a1,b1,a4,b4);return;

typedef long long ll;

int i,j,n,m,a[105][105],rn,res[10500][7],t;

void chk1(int x,int y){
	if(!a[x][y]){return;}
	if(y!=m){
		rn++;
		res[rn][1]=x;
		res[rn][2]=y;
		
		res[rn][3]=x+1;
		res[rn][4]=y;
		
		res[rn][5]=x+1;
		res[rn][6]=y+1;
		a[x][y]^=1; a[x+1][y]^=1; a[x+1][y+1]^=1;
	}
	else{
		rn++;
		res[rn][1]=x;
		res[rn][2]=y;
		
		res[rn][3]=x+1;
		res[rn][4]=y;
		
		res[rn][5]=x+1;
		res[rn][6]=y-1;
		a[x][y]^=1; a[x+1][y]^=1; a[x+1][y-1]^=1;
	}
}

void chk2(int x,int y){
	if(!a[x][y]){return;}
	if(x!=n){
		rn++;
		res[rn][1]=x;
		res[rn][2]=y;
		
		res[rn][3]=x;
		res[rn][4]=y+1;
		
		res[rn][5]=x+1;
		res[rn][6]=y+1;
		a[x][y]^=1; a[x][y+1]^=1; a[x+1][y+1]^=1;
	}
	else{
		rn++;
		res[rn][1]=x;
		res[rn][2]=y;
		
		res[rn][3]=x-1;
		res[rn][4]=y+1;
		
		res[rn][5]=x;
		res[rn][6]=y+1;
		a[x][y]^=1; a[x-1][y+1]^=1; a[x][y+1]^=1;
	}
}

void chk3(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4){
	int sb1=a[a1][b1],sb2=a[a2][b2],sb3=a[a3][b3],sb4=a[a4][b4];
	if(!sb1&&!sb2&&!sb3&&!sb4){
		return;
	}
	if( sb1&&!sb2&&!sb3&&!sb4){
		del1();
	}
	if(!sb1&& sb2&&!sb3&&!sb4){
		del2();
	}
	if(!sb1&&!sb2&& sb3&&!sb4){
		del3();
	}
	if(!sb1&&!sb2&&!sb3&& sb4){
		del4();
	}
	
	if( sb1&& sb2&&!sb3&&!sb4){
		ans(a1,b1,a2,b2,a3,b3);
		del3();
	}
	
	if( sb1&&!sb2&& sb3&&!sb4){
		ans(a1,b1,a2,b2,a3,b3);
		del2();
	}
	
	if( sb1&&!sb2&&!sb3&& sb4){
		ans(a1,b1,a2,b2,a4,b4);
		del2();
	}
	
	if(!sb1&& sb2&& sb3&&!sb4){
		ans(a3,b3,a2,b2,a4,b4);
		del4();
	}
	
	if(!sb1&& sb2&&!sb3&& sb4){
		ans(a3,b3,a2,b2,a4,b4);
		del3();
	}
	
	if(!sb1&&!sb2&& sb3&& sb4){
		ans(a3,b3,a2,b2,a4,b4);
		del2();
	}
	
	if( sb1&& sb2&& sb3&&!sb4){
		ans(a1,b1,a2,b2,a3,b3);return;
	}
	
	if( sb1&& sb2&&!sb3&& sb4){
		ans(a1,b1,a2,b2,a4,b4);return;
	}
	
	if( sb1&&!sb2&& sb3&& sb4){
		ans(a1,b1,a4,b4,a3,b3);return;
	}
	
	if(!sb1&& sb2&& sb3&& sb4){
		ans(a4,b4,a2,b2,a3,b3);return;
	}
	
	ans(a1,b1,a2,b2,a3,b3); del4();
}


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);rn=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%1d",&a[i][j]);
			}
		}
		for(i=1;i<=n-2;i++){
			for(j=1;j<=m;j++){
				chk1(i,j);
			}
		}
		for(i=1;i<=m-2;i++){
			chk2(n-1,i);
			chk2(n,i);
		}
		chk3(n-1,m-1,n-1,m,n,m-1,n,m);
		//for(i=1;i<=n;i++){for(j=1;j<=m;j++){printf("%d ",a[i][j]);}puts("");}puts("");
		printf("%d\n",rn);
		for(i=1;i<=rn;i++){
			printf("%d %d %d %d %d %d\n",res[i][1],res[i][2],res[i][3],res[i][4],res[i][5],res[i][6]);
		}
	}
}