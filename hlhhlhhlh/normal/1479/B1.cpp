// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m,a[maxn],c[maxn],ans;
struct node{
	int x,num;
}b[maxn];
int main(){
	
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	j=0;
	for (i=1;i<n;i++){
		j++;
		if (a[i]!=a[i+1]){
			m++; b[m].x=a[i]; b[m].num=j; j=0;
		}
	}
	m++; j++; b[m].x=a[n]; b[m].num=j;
	for (i=1;i<=m;i++){
		if (b[i].num>1){
			k++; c[k]=i;
		}
	}
	for (i=1;i<k;i++){
		if (b[c[i]].x!=b[c[i+1]].x) continue;
		for (j=c[i]+1;j<=c[i+1]-2;j++){
			if ((b[j].x!=b[c[i]].x)&&(b[j+1].x!=b[c[i]].x)){ ans++; break; }
		}
		ans--;
	}
	
	printf("%d\n",k+m+ans);
	
	return 0;
}