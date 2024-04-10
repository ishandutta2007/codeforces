#include<bits/stdc++.h>
using namespace std;
int a[45];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n,t0=0,t1=0;
		n=read();
		for(int i=0;i<n;i++){
			a[i]=read()%2;
			if(a[i])t1++;
			else t0++;
		}
		if(t0!=n/2+(n%2)){printf("-1\n");continue;}
		int k=0;
		for(int i=0;i<n;i++)
			if(a[i]%2!=i%2)k++;
		printf("%d\n",k/2);
	}
	return 0;
}