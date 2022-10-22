#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=400010;
int T=1,opt;
int n,m;
int t1,t2,t3,z;
int a[maxn],b[maxn];
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		m=n; z=0;
		for (int i=1;i<n;i++){
			if (m==0) break;
			sort(a+1,a+m+1);
			for (int i=1;i<m;i++) b[i]=a[i+1]-a[i];
			if (z!=0){
				b[m]=a[1]; m++;
			}
			if (m) sort(b+1,b+m);
			if (z) z--;
			t1=0;
			for (int i=1;i<m;i++) if (b[i]){
				t1++; a[t1]=b[i];
			}
			else z++;
			m=t1;
		}
		if (m==0) printf("0\n");
		else printf("%d\n",a[1]);
	}

	return 0;
}