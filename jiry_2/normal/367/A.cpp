#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[101000];
int n,f[101000][3];
int main(){
	scanf("%s",ch+1); int n=strlen(ch+1),m; scanf("%d",&m);
	memset(f,0x00,sizeof f);
	for (int i=1;i<=n;i++){
		f[i][0]=f[i-1][0]; f[i][1]=f[i-1][1]; f[i][2]=f[i-1][2];
		f[i][ch[i]-'x']++;
	}
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		int k3=f[k2][0]-f[k1-1][0],k4=f[k2][1]-f[k1-1][1],k5=f[k2][2]-f[k1-1][2];
		if ((abs(k3-k4)<=1&&abs(k3-k5)<=1&&abs(k4-k5)<=1)||(k2-k1+1<3)) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
	return 0;
}