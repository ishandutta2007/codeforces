#include<bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
struct zb{
	int x,y;
}a[1010],b[1010];
bool cmp(zb x,zb y){
	return x.x>y.x||(x.x==y.x&&x.y>y.y);
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=n;i++)
		scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	int nx=a[1].x+b[n].x,ny=a[1].y+b[n].y;
	cout<<nx<<' '<<ny<<endl;
	return 0;
}