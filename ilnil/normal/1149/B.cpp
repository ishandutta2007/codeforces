#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db long double
#define put putchar
using namespace std;
const int N=2e5+5,mo=1e9+7;
int n,q,ne[N][27],w;
int f[255][255][255],wz[4];
char c[4][255],s[N],g;
int main(){
	scanf("%d%d\n",&n,&q);
	scanf("%s",s+1);
	fo(j,0,25)ne[n][j]=ne[n+1][j]=n+1;
	fd(i,0,n-1){
		fo(j,0,25)ne[i][j]=ne[i+1][j];
		ne[i][s[i+1]-'a']=i+1;
	}
	fo(i,0,250)fo(j,0,250)fo(k,0,250)f[i][j][k]=n+1;
	f[0][0][0]=0;
	for(;q--;){
		scanf("\n");
		g=getchar();
		scanf("%d",&w);
		if(q==1){
			int kk=0;
		}
		if(g=='+'){
			g=getchar();g=getchar();g-='a';
			wz[w]++;
			c[w][wz[w]]=g;
			int wzz=wz[w];
			if(w==3){
				fo(i,0,wz[1])fo(j,0,wz[2])f[i][j][wzz]=min(f[i][j][wzz],ne[f[i][j][wzz-1]][g]);
				fo(i,0,wz[1])fo(j,0,wz[2]){
					if(i)f[i][j][wzz]=min(f[i][j][wzz],ne[f[i-1][j][wzz]][c[1][i]]);
					if(j)f[i][j][wzz]=min(f[i][j][wzz],ne[f[i][j-1][wzz]][c[2][j]]);
				}
			}
			if(w==2){
				fo(i,0,wz[1])fo(j,0,wz[3])f[i][wzz][j]=min(f[i][wzz][j],ne[f[i][wzz-1][j]][g]);
				fo(i,0,wz[1])fo(j,0,wz[3]){
					if(i)f[i][wzz][j]=min(f[i][wzz][j],ne[f[i-1][wzz][j]][c[1][i]]);
					if(j)f[i][wzz][j]=min(f[i][wzz][j],ne[f[i][wzz][j-1]][c[3][j]]);
				}
			}
			if(w==1){
				fo(i,0,wz[2])fo(j,0,wz[3])f[wzz][i][j]=min(f[wzz][i][j],ne[f[wzz-1][i][j]][g]);
				fo(i,0,wz[2])fo(j,0,wz[3]){
					if(i)f[wzz][i][j]=min(f[wzz][i][j],ne[f[wzz][i-1][j]][c[2][i]]);
					if(j)f[wzz][i][j]=min(f[wzz][i][j],ne[f[wzz][i][j-1]][c[3][j]]);
				}
			}
		}else{
			if(w==1){
				fo(i,0,wz[2])fo(j,0,wz[3])f[wz[w]][i][j]=n+1;
			}
			if(w==2){
				fo(i,0,wz[1])fo(j,0,wz[3])f[i][wz[w]][j]=n+1;
			}
			if(w==3){
				fo(i,0,wz[1])fo(j,0,wz[2])f[i][j][wz[w]]=n+1;
			}
			wz[w]--;
		}
		if(f[wz[1]][wz[2]][wz[3]]<=n)printf("YES\n");else printf("NO\n");
	}
}