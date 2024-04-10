#include<bits/stdc++.h>
typedef long long ll;
struct point{
	int x,y;
	point(int x0=0,int y0=0):x(x0),y(y0){}
	void read(){
		scanf("%d%d",&x,&y);
	}
	bool operator!=(const point&a)const{
		return x!=a.x||y!=a.y;
	}
	point operator+(const point&a)const{
		return point(x+a.x,y+a.y);
	}
	point operator-(const point&a)const{
		return point(x-a.x,y-a.y);
	}
	point operator*(int k)const{
		return point(x*k,y*k);
	}
	ll operator*(const point&a)const{
		return 1ll*x*a.x+1ll*y*a.y;
	}
	ll operator^(const point&a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
};
int t;
point a[2],b[2],c[2];
bool check3(const point&a0,const point&a1,const point&b0,const point&b1,const point&c0,const point&c1){
	if(a0!=b0)
		return 0;
	if(((a1-a0)^(c0-a0))!=0)
		return 0;
	if(((b1-b0)^(c1-b0))!=0)
		return 0;
	if(((a1-a0)^(b1-b0))==0)
		return 0;
	if((a1-a0)*(b1-b0)<0)
		return 0;
	if((a1-a0)*(c0-a0)*5<(a1-a0)*(a1-a0)||(a1-a0)*(c0-a0)*5>(a1-a0)*(a1-a0)*4)
		return 0;
	if((b1-b0)*(c1-b0)*5<(b1-b0)*(b1-b0)||(b1-b0)*(c1-b0)*5>(b1-b0)*(b1-b0)*4)
		return 0;
	return 1;
}
bool check2(point a[2],point b[2],point c[2]){
	return check3(a[0],a[1],b[0],b[1],c[0],c[1])||check3(a[0],a[1],b[1],b[0],c[0],c[1])||check3(a[1],a[0],b[0],b[1],c[0],c[1])||check3(a[1],a[0],b[1],b[0],c[0],c[1]);
}
bool check1(){
	return check2(a,b,c)||check2(a,c,b)||check2(b,a,c)||check2(b,c,a)||check2(c,a,b)||check2(c,b,a);
}
int main(){
	scanf("%d",&t);
	for(;t;--t){
		a[0].read();
		a[1].read();
		b[0].read();
		b[1].read();
		c[0].read();
		c[1].read();
		if(check1())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}