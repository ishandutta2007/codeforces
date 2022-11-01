#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int main(){
	R(n);
	if(n&1){
		printf("YES\n");
		fo(i,1,n)
			if(i&1)
				a[i]=i*2-1,a[i+n]=i*2;
			else 
				a[i]=i*2,a[i+n]=i*2-1;
		fo(i,1,n*2)printf("%d ",a[i]);
	}else{
		printf("NO");
	}
}