// Hydro submission #62c564d5c3a9fda562296ca0@1657103574352
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
char s[N],t[N];
int n,m,Next[N],f[N],g[N];
bool pan(int p){
	for(int j=1;j<=m;j++)
		if(s[p-j+1]!=t[m-j+1]&&s[p-j+1]!='?')return false;
	return true;
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	for(int i=2,j=0;i<=m;i++){
		while(j&&t[j+1]!=t[i])j=Next[j];
		if(t[j+1]==t[i])j++;
		Next[i]=j;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(pan(i)){
			g[i]=f[i-m]+1;
			for(int j=Next[m];j;j=Next[j])g[i]=max(g[i],g[i-(m-j)]+1);
			f[i]=max(f[i],g[i]);
        }
    }
    printf("%d\n",f[n]);
}