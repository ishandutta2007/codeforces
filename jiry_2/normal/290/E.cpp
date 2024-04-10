#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char a[1000100],b[1000100];
int n;
int main(){
	scanf("%s",a+1); n=strlen(a+1); int H=0,Q=0;
	for (int i=1;i<=n;i++) if (a[i]=='H') H++; else Q++;
	int k1=trunc(sqrt(Q)); if (k1*k1!=Q||H%(k1+1)){cout<<"No"<<endl; return 0;}
	if (Q==0){cout<<"Yes"<<endl; return 0;}
	int k2=1; for (;a[k2]!='Q';k2++); k2--;
	if (k2%2){cout<<"No"<<endl; return 0;} k2=k2/2;
	for (int i=k2+1;i<=k2+k1+H/(k1+1);i++) b[i-k2]=a[i]; int len=k1+H/(k1+1);
	int now=0;
	for (int i=1;i<=len;i++)
		if (b[i]=='H'){
			if (a[now+1]!='H'){cout<<"No"<<endl; return 0;} now++;
		} else {
			for (int j=1;j<=len;j++)
				if (a[now+j]!=b[j]){cout<<"No"<<endl; return 0;}
			now+=len;
		}
	cout<<"Yes"<<endl; return 0;
}