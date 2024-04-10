#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,a[1000500],b[1000500],f[1005000],g[1005000],mn,it1,it2;
ll res;
void add(int x,int y){for(;x<=n;x+=(-x&x))f[x]+=y;}
void add2(int x,int y){for(;x;x-=(-x&x))g[x]+=y;}
int get(int x,int y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}
int get2(int x,int y=0){for(;x<=n;x+=(-x&x)){y+=g[x];}return y;}
struct sb{
	int x,y;
	bool operator<(const sb a)const{
		return (x==a.x)?(y>a.y):(x>a.x);
	}
}v[1005000];
void work(int bl,int br,int al,int ar){
	if(bl>br)return;
	int md=(bl+br)/2,pos,sb;
	mn=1145141919;
	while(it1<=n&&v[it1].x>b[md]){add(v[it1].y,1);it1++;}
	while(it1>1&&v[it1-1].x<=b[md]){add(v[it1-1].y,-1);it1--;}
	while(it2>=1&&v[it2].x<b[md]){add2(v[it2].y,1);it2--;}
	while(it2<n&&v[it2+1].x>=b[md]){add2(v[it2+1].y,-1);it2++;}
	for(i=al;i<=ar;i++){
		sb=get2(i+1)+get(i);
		if(mn>=sb){pos=i;mn=sb;}
	}
	res+=mn;
	work(bl,md-1,al,pos);
	work(md+1,br,pos,ar);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(f,0,n*4+50);
		res=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=m;i++)scanf("%d",&b[i]);
		for(i=1;i<=n;i++){
			v[i].x=a[i];v[i].y=i;
		}
		sort(v+1,v+n+1);
		for(i=1;i<=n;i++){
			res+=get(v[i].y);
			add(v[i].y,1);
		}
		a[0]=-1;
		a[n+1]=1145141919;
		sort(b+1,b+m+1);
		memset(f,0,n*4+50);
		memset(g,0,n*4+50);
		it1=1;it2=n;
		work(1,m,0,n);
		printf("%lld\n",res);
	}
}