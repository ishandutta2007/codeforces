#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF=1e9;
static char ss[1<<17],*A=ss,*B=ss;
char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
int n,m;
int a[200005],b[200005];
void ou(){
	puts("YES");
	printf("%d\n",m);
	for(int i=1;i<=m;++i) printf("%d ",b[i]);
	puts("");
	return; 
}
void MAIN(){
	int u,v,s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s^=a[i];
	}
	if(s){
		puts("NO");
		return;
	}
	int l,r;
	m=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(a[i]==0){
			while(j<n&&a[j+1]==0) ++j;
			if(s==0){
				l=i;
				while(l>1){
					if(a[l-1]==1&&a[l-2]==1){
						b[++m]=l-2;
						a[l-1]=a[l-2]=0;
						l=l-2;
						continue;
					}
					if(a[l-1]==1&&a[l-2]==0){
						if(a[l-3]==0){
							b[++m]=l-3;
							b[++m]=l-2;
							a[l-3]=1;a[l-2]=a[l-1]=0;
							l=l-2;
						}
						else{
							b[++m]=l-3;
							l=l-3;
						}
						continue;
					}
					if(a[l-1]==0){
						l=l-1;
					}
				}
				r=j;
				while(r<n){
//					cout<<r<<endl;
//					for(int z=1;z<=5;++z) cout<<a[z]<<" ";cout<<endl;
					if(a[r+1]==1&&a[r+2]==1){
						b[++m]=r;
						a[r+1]=a[r+2]=0;
						r=r+2;
						continue;
					}
					if(a[r+1]==1&&a[r+2]==0){
						if(a[r+3]==0){
							b[++m]=r+1;
							b[++m]=r;
							a[r+1]=0;a[r+2]=0;a[r+3]=1;
							r=r+2;
						}
						else{
							b[++m]=r+1;
							r=r+3;
						}
						continue;
					}
					if(a[r+1]==0){
						r=r+1;
					}
				}
				ou();
				return;
			}
			else if((j-i+1)%2==1){
			//	cout<<"?"<<endl;
				while(j!=i){
					b[++m]=j-1;
					a[j]=a[j-1]=1;
					j=j-2;
				}
				b[++m]=i-1;
				a[i-1]=a[i+1]=0;
				i--;j++;
				l=i;
				while(l>1){
					if(a[l-1]==1&&a[l-2]==1){
						b[++m]=l-2;
						a[l-1]=a[l-2]=0;
						l=l-2;
						continue;
					}
					if(a[l-1]==1&&a[l-2]==0){
						if(a[l-3]==0){
							b[++m]=l-3;
							b[++m]=l-2;
							a[l-3]=1;a[l-2]=a[l-1]=0;
							l=l-2;
						}
						else{
							b[++m]=l-3;
							l=l-3;
						}
						continue;
					}
					if(a[l-1]==0){
						l=l-1;
					}
				}
				r=j;
				while(r<n){
//					cout<<r<<endl;
//					for(int z=1;z<=5;++z) cout<<a[z]<<" ";cout<<endl;
					if(a[r+1]==1&&a[r+2]==1){
						b[++m]=r;
						a[r+1]=a[r+2]=0;
						r=r+2;
						continue;
					}
					if(a[r+1]==1&&a[r+2]==0){
						if(a[r+3]==0){
							b[++m]=r+1;
							b[++m]=r;
							a[r+1]=0;a[r+2]=0;a[r+3]=1;
							r=r+2;
						}
						else{
							b[++m]=r+1;
							r=r+3;
						}
						continue;
					}
					if(a[r+1]==0){
						r=r+1;
					}
				}
				ou();
				return;
			}
		}
		s^=a[i];
	}
	puts("NO");
	return;
} 

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*
*/