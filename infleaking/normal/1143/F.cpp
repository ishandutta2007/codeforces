#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+10;
struct dot{ll x,y;}p[N];
ll cross(dot a,dot b){return a.x*b.y-a.y*b.x;}
ll a[N],b[N],n,d[N],r;

bool comp(dot a,dot b){
	if (a.x==b.x)return a.y>b.y;
	return a.x>b.x;
}
dot operator -(dot a,dot b){return (dot){a.x-b.x,a.y-b.y};}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i].x=x;p[i].y=y-(ll)x*x;
	}
	sort(p+1,p+n+1,comp);
	d[r=1]=1;
	for (int i=2;i<=n;i++){
		if (p[i].x==p[i-1].x)continue;
		while (r>1&&cross(p[d[r-1]]-p[d[r]],p[i]-p[d[r]])>=0)r--;
		d[++r]=i;
	}
	cout<<r-1<<endl;
}