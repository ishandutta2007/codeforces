#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mo=1e7+19;
int fir[mo],ne[2000],size[2000],len,n,x[2000],w[2000],pd[2000],A[2000],sign;
void insert(int k1){
	int k=(k1%mo+mo)%mo;
	for (int i=fir[k];i;i=ne[k])
		if (w[i]==k1){
			size[i]++; return;
		}
	len++; ne[len]=fir[k]; size[len]=1; w[len]=k1; fir[k]=len;
}
int check(int k1){
//	cout<<"check "<<k1<<endl;
	int k=(k1%mo+mo)%mo;
	for (int i=fir[k];i;i=ne[k])
		if (w[i]==k1){
			if (pd[i]!=sign){
				pd[i]=sign; A[i]=0;
			}
			A[i]++; if (A[i]>size[i]) return 0; else return 1;
		}
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	len=0;
	for (int i=1;i<=n;i++) insert(x[i]);
	int an=0; int size0=0;
	for (int i=1;i<=n;i++) if (x[i]==0) size0++;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j){
				sign++;
				int a=x[i],b=x[j];
				if (a==0&&b==0){
					an=max(an,size0); continue;
				}
				check(a); check(b); int ans=2;
				while (1){
					int c=a+b; if (check(c)==0) break;
					ans++; a=b; b=c;
				}
				an=max(an,ans);
			}
	printf("%d\n",an);
	return 0;
}