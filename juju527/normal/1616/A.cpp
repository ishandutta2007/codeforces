#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t[205];
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
		for(int i=0;i<=200;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[read()+100]++;
		int res=0;
		if(t[100])res++;
		for(int i=1;i<=100;i++){
			if(t[i+100]+t[100-i]>=2)res+=2;
			else if(t[i+100]+t[100-i])res++;
		}
		printf("%d\n",res);
	}
    return 0;
}