#include<iostream>
using namespace std;
int a[4];
long long eshterak(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3,long long x4,long long y4){
	long long t,a,xx1=max(x1,x3),yy1=max(y1,y3),xx2=min(x2,x4),yy2=min(y2,y4);
	if(xx2<xx1 || yy2<yy1)
		return 0;
	t=xx2-xx1;
	a=yy2-yy1;
	return t*a;
}
int eshterak2(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3,long long x4,long long y4){
	long long t,xx1=max(x1,x3),yy1=max(y1,y3),xx2=min(x2,x4),yy2=min(y2,y4);
	if(xx2<xx1 || yy2<yy1){
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		return 0;
	}
	a[0]=xx1;a[1]=yy1;a[2]=xx2;a[3]=yy2;
	return 0;
}
int main(){
	long long x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,ms,l,ms1,ms2;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
	ms=(x2-x1)*(y2-y1);
	ms1=eshterak(x1,y1,x2,y2,x3,y3,x4,y4);
	ms2=eshterak(x1,y1,x2,y2,x5,y5,x6,y6);
	eshterak2(x3,y3,x4,y4,x5,y5,x6,y6);
	l=ms-(ms1+ms2)+eshterak(a[0],a[1],a[2],a[3],x1,y1,x2,y2);//cout<<ms<<endl<<ms1<<endl<<ms2<<endl<<eshterak(x3,y3,x4,y4,x5,y5,x6,y6);
	if(l>0)
		cout<<"YES";
	else
		cout<<"NO";
}