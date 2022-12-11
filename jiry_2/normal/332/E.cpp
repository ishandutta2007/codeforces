#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char p[1000100],s[300];
int n,k,x[2010],y[2010],m;
int check(int k1,int k2,int k3){
	for (;k2<=n;k2+=k3){
		if (k1>m||p[k1]!=s[k2]) return 0;
		k1+=k;
	}
	return k1>m;
}
void update(){
	for (int i=1;i<=k;i++) if (x[i]<y[i]){memcpy(y,x,sizeof x); return;} else if (x[i]>y[i]) return;
}
int main(){
	m=0; char ch=getchar(); while (ch!='\n'){p[++m]=ch; ch=getchar();}
	n=0; ch=getchar(); while (ch!='\n'){s[++n]=ch; ch=getchar();}
	scanf("%d",&k); int flag=0;
	for (int i=1;i<=k;i++) y[i]=1;
	for (int i=1;i<=n;i++){
		int now=i,pd=0;
		for (int j=k;j;j--)
			if (check(j,now,i)){
				x[j]=1; now--; if (now==0){pd=1; for (int k1=1;k1<j;k1++) x[k1]=0; break;}
			} else x[j]=0;
		if (pd){
			flag=1; update();
		}
	}
	if (flag) for (int i=1;i<=k;i++) printf("%d",y[i]); else cout<<0; cout<<endl;
	return 0;
}