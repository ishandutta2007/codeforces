#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
signed main(){
	int n=read(),t=read();
	int k=read();
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		printf("? %d %d\n",1,mid);
		fflush(stdout);
		int res=read();
		if(mid-res>=k)r=mid-1;
		else l=mid+1;
	}cout<<"! "<<r+1<<endl;fflush(stdout);
	return 0;
}