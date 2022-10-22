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
int mxh,mxm;
int h,m;
int to[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
void add(){
	m++;
	if(m==mxm)h++,m=0;
	if(h==mxh)h=0;
	return;
}
inline bool check(){
	int a=h/10,b=h%10;
	int c=m/10,d=m%10;
	a=to[a],b=to[b],c=to[c],d=to[d];
	swap(a,d),swap(b,c);
	if(a==-1||b==-1||c==-1||d==-1)return false;
	if(c*10+d<mxm&&a*10+b<mxh)return true;
	return false;
}
int main(){
	int t=read();
	while(t--){
		mxh=read();
		mxm=read();
		h=read(),m=read();
		while(1){
			if(check())break;
			add();
		}
		if(h/10==0)putchar('0');cout<<h<<":";
		if(m/10==0)putchar('0');cout<<m<<endl;
	}
	return 0;
}