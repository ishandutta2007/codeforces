#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=15;
int a[maxn];
int sum[1<<10];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=0;i<n;i++)a[i]=read();
		int S=(1<<n)-1;
		bool tag=0;
		for(int s=1;s<=S;s++){
			sum[s]=0;
			for(int i=0;i<n;i++)if((s>>i)&1)sum[s]+=a[i];
			for(int t=s;t;t=(t-1)&s)if(sum[s^t]==sum[t])tag=1;
			if(sum[s]==0)tag=1;
		}
		if(tag)puts("YES");
		else puts("NO");
	}
    return 0;
}