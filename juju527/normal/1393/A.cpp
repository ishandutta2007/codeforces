#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		cout<<n/2+1<<endl;
	}
	return 0;
}