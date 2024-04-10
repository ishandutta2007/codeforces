#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sum,a[666][666],it,tmp,b[666][666];

string sb;

int mex(vector<int> v){
	int a[10]={0},i,j;
	for(auto i:v){a[i]++;}
	for(i=0;;i++){
		if(!a[i]){return i;}
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);tmp=k;
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		it=1;
		if(n&1){
			if(k<(m/2)){puts("NO");goto aaa;}
			k-=(m/2);
			if(k&1){puts("NO");goto aaa;}
			else{
				k=tmp;
				puts("YES");
				for(i=1;i<=m;i+=2){
					a[1][i]=a[1][i+1]=it;it++;k--;
				}
				for(i=1;i<=m;i+=2){
					for(j=2;j<=n;j+=2){
						if(!k){break;}
						a[j][i]=a[j][i+1]=it;it++;
						a[j+1][i]=a[j+1][i+1]=it;it++;k-=2;
					}
				}
				for(i=1;i<=n;i++){
					for(j=1;j<=m;j++){
						if(!a[i][j]){
							a[i][j]=a[i+1][j]=it;it++;
						}
					}
				}
				goto bbb;

			}
		}
		if(m&1){
			if(k>(m/2)*n){puts("NO");goto aaa;}
			if(k&1){puts("NO");goto aaa;}
			else{
				k=tmp;
				puts("YES");
				for(i=1;i<m;i+=2){
					for(j=1;j<=n;j+=2){
						if(!k){break;}
						a[j][i]=a[j][i+1]=it;it++;
						a[j+1][i]=a[j+1][i+1]=it;it++;k-=2;
					}
				}
				for(i=1;i<=n;i++){
					for(j=1;j<=m;j++){
						if(!a[i][j]){
							a[i][j]=a[i+1][j]=it;it++;
						}
					}
				}
				goto bbb;
			}
		}
		else{
			if(k&1){puts("NO");goto aaa;}
			
			k=tmp;
			puts("YES");
			for(i=1;i<=m;i+=2){
				for(j=1;j<=n;j+=2){
					if(!k){break;}
					a[j][i]=a[j][i+1]=it;it++;
					a[j+1][i]=a[j+1][i+1]=it;it++;k-=2;
				}
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(!a[i][j]){
						a[i][j]=a[i+1][j]=it;it++;
					}
				}
			}
			goto bbb;
		}
		
		bbb:;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(b[i][j]){continue;}
				if(a[i][j]==a[i][j+1]){
					b[i][j]=b[i][j+1]=mex({b[i-1][j],b[i-1][j+1],b[i][j-1],b[i][j+2],b[i+1][j],b[i+1][j+1]});
				}
				if(a[i][j]==a[i+1][j]){
					b[i][j]=b[i+1][j]=mex({b[i-1][j],b[i][j-1],b[i][j+1],b[i+1][j-1],b[i+1][j+1],b[i+2][j]});
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				putchar(b[i][j]+'a');
			}puts("");
		}
		aaa:;
	}
}