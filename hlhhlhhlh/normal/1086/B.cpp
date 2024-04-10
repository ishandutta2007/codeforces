// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int n,m,x,y;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int th,f1[maxn],f2[maxn],f3[maxn];
void add(int x,int y){
	th++; f2[th]=y; f3[th]=f1[x]; f1[x]=th;
}
int ha[maxn],mm;
double ans;
int main(){
	n=read(); m=read();
	for (i=1;i<n;i++){
		x=read(); y=read();
		add(x,y); add(y,x);
		ha[x]++; ha[y]++;
	}
	for (i=1;i<=n;i++){
		mm=mm+(ha[i]==1);
	}
	ans=m;
	ans=ans/mm;
	printf("%lf\n",ans*2);
	return 0;
}