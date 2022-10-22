#include<bits/stdc++.h>
using namespace std;
int n,a[210000],x[210000],c[210000];
char s[210000];
char calc(int x){ return x==1?'L':'R';}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	scanf("%s",s+1); int tot=0;
	for (int i=1;i<=n;i++){
		x[i]=(s[i]=='L'?1:-1);
		if (i>1) tot+=(x[i]==x[i-1]);
	}
	
	c[n]=x[n];
	for (int i=n-1;i>0;i--) c[i]=c[i+1]*(-1);
	
	int pos1=tot,pos2=tot+1;
	printf("%d %c\n",a[pos2],calc(c[pos2])),pos2++;
	for (int i=2;i<=n;i++)
		if (c[pos2-1]*x[i]<0)
			printf("%d %c\n",a[pos2],calc(c[pos2])),pos2++;
		else
			printf("%d %c\n",a[pos1],calc(c[pos1])),pos1--;
	return 0;
}