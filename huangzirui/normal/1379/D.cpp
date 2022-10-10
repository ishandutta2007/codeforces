#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=200010;
struct node{
	int s,id;
}a[maxn];
int i,j,k,n,m,h,ans=1e9,Ans;
bool cmp(node a,node b){
	return a.s<b.s;
}
int main() {
	cin>>n>>h>>m>>k;
	for(i=1;i<=n;i++){
		int x,y;
		x=read();y=read();
		y%=(m/2);a[i]={y,i};
	}sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)a[n+i]={a[i].s+m/2,a[i].id};
	int r=0;
//	for(i=1;i<=n;i++)cout<<a[i].s<<' ';cout<<endl;
	for(i=1;i<=n;i++){
		while(r<=2*n && a[r].s<a[i].s+k)++r;
//		cout<<a[i].s<<" l="<<i<<" r="<<r<<endl;
		if(r-i-1<ans){ans=r-i-1;Ans=i;}
	}cout<<ans<<' '<<(a[Ans].s+k)%(m/2)<<endl;
	for(i=Ans+1;a[i].s<a[Ans].s+k;i++)printf("%d ",a[i].id);
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}