#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x,id;
	bool operator<(const node&X)const{
		return x<X.x;
	}
}a[N];
int main(){
	int t=read();
	while(t--){
		int n=read(),k=read();
		for(int i=1;i<=n;i++){
			a[i].x=read();a[i].id=i;
		}
		sort(a+1,a+1+n);
		int res=0;
		for(int i=2;i<=n;i++)if(a[i].id!=a[i-1].id+1)res++;
		puts((res+1)<=k?"Yes":"No");
	}
	return 0;
}