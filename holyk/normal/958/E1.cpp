#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
#define ld long double
const ld EPS=1e-10;
inline int dcmp(ld x){
	return fabs(x)<EPS?0:(x>0?1:-1);
}
struct Point{
	ld x,y;
	Point(ld x=0,ld y=0):x(x),y(y){}
};
typedef Point Vector;
inline Vector operator+(const Vector A,const Vector B){return Vector(A.x+B.x,A.y+B.y);}
inline Vector operator-(const Point A,const Point B){return Vector(A.x-B.x,A.y-B.y);}
inline Vector operator*(const Vector A,const ld p){return Vector(A.x*p,A.y*p);}
inline Vector operator/(const Vector A,const ld p){return Vector(A.x/p,A.y/p);}
inline Vector operator*(const ld p,const Vector A){return Vector(A.x*p,A.y*p);}
inline Vector operator/(const ld p,const Vector A){return Vector(A.x/p,A.y/p);}
inline ld Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
inline bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
	if (min(a1.x,a2.x)>max(b1.x,b2.x)||max(a1.x,a2.x)<min(b1.x,b2.x)||min(a1.y,a2.y)>max(b1.y,b2.y)||max(a1.y,a2.y)<min(b1.y,b2.y)) return 0;
	ld c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
const int N=20;
Point a[N],b[N];
int p[N],vis[N],n;
bool dfs(int x){
	if (x==0){
		for (int i=1;i<=n;++i){
			for (int j=1;j<i;++j){
				if (SegmentProperIntersection(a[i],b[p[i]],a[j],b[p[j]])) return 0;
			}
		}
		return 1;
	}
	for (int i=1;i<=n;++i){
		if (!vis[i]){
			p[x]=i;
			vis[i]=1;
			if (dfs(x-1)) return 1;
			vis[i]=0;
		}
	}
	return 0;
}
int main(){
	int R=read(),B=read();
	if (R!=B){
		printf("No\n");
		return 0;
	}
	n=R;
	for (int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read();
	}
	for (int i=1;i<=n;++i){
		b[i].x=read(),b[i].y=read();
	}
	if (dfs(n)){
		printf("Yes\n");
	}
	else printf("No\n");
	return 0;
}