// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,a[maxn],tot,l,r,mi,ans,m;
int c[maxn*maxn],d[maxn*maxn];
struct node{
	int x,y;
}b[maxn];
bool cmp(node a,node b){
	return (a.x>b.x);
}
int main(){
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read();
		b[i].x=a[i]; b[i].y=i;
		tot=tot+a[i];
	}
	if (tot<(n-1)*2){
		printf("NO\n"); return 0;
	}
	sort(b+1,b+n+1,cmp);
	for (i=1;i<=n;i++){
		if (b[i].x>=2) l=i;
	}
	ans=0;
	for (i=1;i<l;i++){
		b[i].x--; b[i+1].x--; ans++;
		m++; c[m]=b[i].y; d[m]=b[i+1].y;
	}
	for (i=l+1;i<=n;i++){
		if (i-l<=2){
			ans++;
			if (i-l==1){
				b[1].x--; b[i].x--;
				m++; c[m]=b[1].y; d[m]=b[i].y;
			}
			if (i-l==2){
				b[l].x--; b[i].x--;
				m++; c[m]=b[l].y; d[m]=b[i].y;
			}
		}
		else{
			for (j=1;j<=l;j++){
				if (b[j].x!=0){
					b[j].x--; b[i].x--;
					m++; c[m]=b[j].y; d[m]=b[i].y;
					break;
				}
			}
		}
	}
	printf("YES %d\n",ans);
	printf("%d\n",m);
	for (i=1;i<=m;i++){
		printf("%d %d\n",c[i],d[i]);
	}
	return 0;
}