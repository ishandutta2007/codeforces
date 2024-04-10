//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef pair<int,int> pii;
typedef long double Lf;
typedef pair<Lf,Lf> point;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
int read()
{
    char c;
    while(gc<'-');
    if(c=='-')
    {
        int x=gc-'0';
        while(gc>='0')x=x*10+c-'0';
        return -x;
    }
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}
#undef gc
const Lf eps=1e-12;
const Lf I=sqrt(-1);
const point O=mp(0,0);
int cmp(const Lf &x)
{
	return x<-eps?-1:x>eps;
}
void read(point &p)
{
	cin>>p.first>>p.second;
}
point operator -(const point &p1,const point &p2)
{
	return mp(p1.first-p2.first,p1.second-p2.second);
}
void operator -=(point &p1,const point &p2)
{
	p1.first-=p2.first;p1.second-=p2.second;
}
Lf sqr(const Lf &x)
{
	return x*x;
}
Lf dis2(point p1,point p2=O)
{
	return sqr(p1.first-p2.first)+sqr(p1.second-p2.second);
}
Lf dis(point p1,point p2=O)
{
	return sqrt(sqr(p1.first-p2.first)+sqr(p1.second-p2.second));
}
point a,b,c;
Lf t1,t2;
void jie(Lf &x1,Lf &x2,Lf a,Lf b,Lf c)
{
//	if(cmp(b*b-4*a*c)<0)
//			puts("-1");
	Lf s=-b/(2*a),d=cmp(b*b-4*a*c)<=0?0:sqrt(b*b-4*a*c)/(2*a);
	x1=s-d;x2=s+d;
}
bool ok(point B,Lf l1,point C,Lf l2,Lf l)
{
	if(cmp(l1-dis(B)-l)>=0)return 1;
	if(cmp(l-dis(B)-l1)>=0)return 1;
	Lf a=2*B.first,b=2*B.second,c=sqr(l1)-sqr(l)-sqr(B.first)-sqr(B.second);
	Lf x1,x2,y1,y2;
	if(!cmp(b))
	{
//		if(!cmp(a))
//			puts("-1");
		x1=x2=-c/a;
		if(cmp(sqr(l)-sqr(x1))<=0)
		{
			y1=y2=0;
		}
		else
		{
			y1=sqrt(sqr(l)-sqr(x1));
			y2=-y1;
		}
	}
	else
	{
		a=-a/b;c=-c/b;
		jie(x1,x2,1+sqr(a),2*a*c,sqr(c)-sqr(l));
		y1=a*x1+c;y2=a*x2+c;
	}
/*	if(cmp(dis(C,mp(x1,y1))-l2)<=0)
		printf("%lf %lf\n",x1,y1);
	if(cmp(dis(C,mp(x2,y2))-l2)<=0)
		printf("%lf %lf\n",x2,y2);*/
	return cmp(dis(C,mp(x1,y1))-l2)<=0||cmp(dis(C,mp(x2,y2))-l2)<=0;
}
bool ok(const Lf &l)
{
	Lf l2=t2-l,l1=t1-l;
	if(cmp(sqr(l1+l2)-dis2(b,c))<0)return 0;
	return ok(b,l1,c,l2,l)||ok(c,l2,b,l1,l)||ok(b-c,l1,O-c,l,l2);
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	cin>>t2>>t1;
	read(a);read(b);read(c);
	b-=a;c-=a;
	t1+=dis(b);t2+=dis(c);
//	printf("%lf %lf %lf\n",dis(c),dis(b,c),t1);
	if(cmp(dis(c)+dis(b,c)-t1)<=0) 
	{
		printf("%lf\n",(double)min(t2+dis(b,c),t1));
		return 0;
	}
	Lf l=0,r=min(t1,t2);
	rep(o,1,40)
	{
		Lf mid=(l+r)/2;
		if(ok(mid))l=mid;
		else r=mid;
	}
//	printf("%d\n",ok(l));
	printf("%lf\n",(double)l);
}