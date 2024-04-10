#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,k,p;
int a[N],h[N];
struct node{
	int h,day,I;
	node(int hh=0,int dayy=0,int II=0):h(hh),day(dayy),I(II){}
	bool operator<(const node&x)const{
		return day>x.day;
	}
};
priority_queue<node>q;
bool check(int mid){
	while(!q.empty())q.pop(); 
	rep(i,n)
		if(mid-m*a[i]<h[i])q.push(node(mid,mid/a[i],i));
	rep(i,m){
		if(q.empty())return true;
		if(q.top().day<i)return false;
		rep(j,k){
			if(q.empty())return true;
			node x=q.top();q.pop();
			if((x.h+p)-m*a[x.I]>=h[x.I])continue;
			q.push(node(x.h+p,(x.h+p)/a[x.I],x.I));
		}
	}
	if(!q.empty())return false;
	return true;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read(),k=read(),p=read();
	rep(i,n)h[i]=read(),a[i]=read(); 
	int l=0,r=1e14;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}cout<<r+1<<endl;
	return 0;
}