#include<bits/stdc++.h>
using namespace std;
int n,ans,Ans[6100];
char s[2100],t[2100],r[2100];
int getpos(int x,char c){//x<=i<=n s[i]=c
	while (x<=n&&s[x]!=c) x++;
	return x;
}
void rev(int x){
	Ans[++ans]=x;
	int cnt=0;
	for (int i=n;i>=n-x+1;i--) r[++cnt]=s[i];
	for (int i=1;i<=n-x;i++) r[++cnt]=s[i];
	for (int i=1;i<=n;i++) s[i]=r[i];
}
int main(){
	scanf("%d%s%s",&n,s+1,t+1);
	for (int i=1;i<=n;i++){
		int pos=getpos(i,t[n-i+1]);
		if (pos==n+1){
			puts("-1");
			return 0;
		}
		rev(n); rev(pos-1); rev(1);
	}
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) printf("%d ",Ans[i]);
	return 0;
}