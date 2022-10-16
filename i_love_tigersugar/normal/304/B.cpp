#include<cstdio>
const int nday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(const int &y) {
	if (y%400==0) return (true);
	if (y%100==0) return (false);
	return (y%4==0);
}
int day(const int &m,const int &y) {
	if (m==2) return (nday[2]+leap(y));
	return (nday[m]);
}
struct date {
	int d,m,y;
	date(){}
	void input(void) {
		scanf("%d:%d:%d",&y,&m,&d);		
	}
	bool operator < (const date &x) {
		if (y<x.y) return (true);
		if (y>x.y) return (false);
		if (m<x.m) return (true);
		if (m>x.m) return (false);
		return (d<x.d);
	}
	int value(void) const {
		int ret=0;
		int i;
		for (i=1;i<y;i=i+1)	
			ret=ret+365+leap(i);
		for (i=1;i<m;i=i+1)
			ret=ret+day(i,y);
		ret=ret+d;
		return (ret);
	}
};
void swap(date &a,date &b) {
	date sw;
	sw=a;a=b;b=sw;
}
int main(void) {
	date a,b;
	a.input();
	b.input();
	if (b<a) swap(a,b);
	printf("%d",b.value()-a.value());
	return 0;
}