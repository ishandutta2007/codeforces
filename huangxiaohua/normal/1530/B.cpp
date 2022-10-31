#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[35][35],f2[35][35],f3[35][35],sb1,sb2,sb3;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(f,0,sizeof(f));
		memset(f2,0,sizeof(f2));
		memset(f3,0,sizeof(f3));
		f[1][1]=1;
		f2[2][1]=1;
		f3[1][2]=1;
		sb1=sb2=sb3=0;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i!=1&&i!=n&&j!=1&&j!=m){continue;}
				if(f[i-1][j]||f[i][j-1]||f[i-1][j-1]||f[i][j+1]||f[i-1][j+1]){continue;}
				f[i][j]=1;sb1++;
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i!=1&&i!=n&&j!=1&&j!=m){continue;}
				if(f2[i-1][j]||f2[i][j-1]||f2[i-1][j-1]||f2[i][j+1]||f2[i-1][j+1]){continue;}
				f2[i][j]=1;sb2++;
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i!=1&&i!=n&&j!=1&&j!=m){continue;}
				if(f3[i-1][j]||f3[i][j-1]||f3[i-1][j-1]||f3[i][j+1]||f3[i-1][j+1]){continue;}
				f3[i][j]=1;sb3++;
			}
		}
		
		if(sb1>=sb2&&sb1>=sb3){
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(i!=1&&i!=n&&j!=1&&j!=m){printf("0");continue;}
					printf("%d",f[i][j]);
				}
				puts("");
			}
			continue;
		}
		
		if(sb2>=sb3){
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(i!=1&&i!=n&&j!=1&&j!=m){printf("0");continue;}
					printf("%d",f2[i][j]);
				}
				puts("");
			}
			continue;
		}
		
		for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(i!=1&&i!=n&&j!=1&&j!=m){printf("0");continue;}
					printf("%d",f3[i][j]);
				}
				puts("");
			}
			continue;
	}
}