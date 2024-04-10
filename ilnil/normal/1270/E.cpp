#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define mp make_pair
using namespace std;
const int N=1005;
int n;
struct P{
	int x,y;
}a[N];
bool bz[N];
void get(){
	int c[4]={0,0,0,0};
	fo(i,1,n)c[(a[i].x&1)*2+(a[i].y&1)]++;
	if(c[0]+c[3]&&c[1]+c[2]){
		fo(i,1,n)if(a[i].x+a[i].y&1)bz[i]=1;
		return;
	}
	if(c[0]&&c[3]){
		fo(i,1,n)if((a[i].x&1)&&(a[i].y&1))bz[i]=1;
		return;
	}
	if(c[1]&&c[2]){
		fo(i,1,n)if((a[i].x&1)&&(~a[i].y&1))bz[i]=1;
		return;
	}
	fd(i,1,n)
		a[i].x-=a[1].x,a[i].y-=a[1].y;
	fo(i,1,n)a[i].x>>=1,a[i].y>>=1;
	get();
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,1,n)cin>>a[i].x>>a[i].y;
	get();
	int m=0;
	fo(i,1,n)if(bz[i])++m;
	printf("%d\n",m);
	fo(i,1,n)if(bz[i])printf("%d ",i);
}