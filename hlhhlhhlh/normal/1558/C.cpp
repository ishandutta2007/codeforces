#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=10010;
int T=1,opt;
int n,a[maxn],fla,t1,t2;
int anss,ans[maxn];
void res(int l,int r){
	anss++; ans[anss]=r;
	for (int i=1;i<=r/2;i++) swap(a[i],a[r-i+1]);
}
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); fla=1; anss=0;
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++){
			if (a[i]%2!=i%2){
				printf("-1\n");
				fla=0;
				break;
			}
		}
		if (fla==0) continue;
		for (int i=n;i>=2;i-=2){
			for (int j=1;j<=i;j++){
				if (a[j]==i){
					t1=j; break;
				}
			}
			for (int j=1;j<=i;j++){
				if (a[j]==i-1){
					t2=j; break;
				}
			}
			t2++;
			if (t1==t2){
				res(1,t1);
				res(1,i);
			}
			else{
				res(1,t1);
				t2--;
				if (t2<=t1) t2=t1-t2+1;
				t2++;
				res(1,t2-2);
				res(1,t2);
				res(1,3);
				res(1,i);
			}
		}
		printf("%d\n",anss);
		for (int i=1;i<=anss;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	
	return 0;
}