#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int N=5e5;
const LL P=1e9+7;
LL h,w;
int n;
struct date{
	LL x,y;
}d[3000];
bool operator < (date A,date B){
	return A.x<B.x||(A.x==B.x&&A.y<B.y);
}
LL jc[N],ny[N];
void init(){
	jc[0]=ny[0]=jc[1]=ny[1]=1;
	for(LL i=2;i<=300000;++i){
		jc[i]=jc[i-1]*i%P;
		ny[i]=(P-P/i)*ny[P%i]%P;
	}
	for(LL i=2;i<=300000;++i){
		ny[i]=ny[i-1]*ny[i]%P;
	}
}
LL C(LL x,LL y){
	return jc[y]*ny[x]%P*ny[y-x]%P;
}
LL a[3000];
int main(){
	init();
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i].x>>d[i].y;
	++n;
	d[n].x=1;d[n].y=1;
	++n;
	d[n].x=h;d[n].y=w;
	sort(d+1,d+1+n);
	for(int i=1;i<=n;++i) a[i]=C(d[i].x-1,d[i].x-1+d[i].y-1);
	//for(int i=1;i<=n;++i) cout<<a[i]<<" "<<d[i].x<<" "<<d[i].y<<endl;
	for(int i=2;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(d[j].y<d[i].y) continue;
			a[j]=(a[j]-a[i]*C(d[j].x-d[i].x,(d[j].x-d[i].x)+(d[j].y-d[i].y))%P+P)%P;
		}
	}
	cout<<(a[n]%P+P)%P<<endl;
	return 0;
}