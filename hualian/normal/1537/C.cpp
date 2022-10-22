#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N];
int main(){
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		if(n==2){
			cout<<a[1]<<" "<<a[2]<<endl;
			continue;
		}
		int mn=1e9,rt=0;
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]<mn)mn=a[i+1]-a[i],rt=i+1;
		}
		for(int i=rt;i<=n;i++)cout<<a[i]<<" ";
		for(int i=1;i<rt;i++)cout<<a[i]<<" ";puts("");
	}
	return 0;
}