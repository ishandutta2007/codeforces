#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
void gn(ll &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
const int mo=1000000007;
const int inf=1061109567;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,k;

struct node{
	ll x,y;int id;
}p[111111],q[111111];
int cmpx(const node &a,const node&b){
	return a.x<b.x;
}
int cmpy(const node &a,const node&b){
	return a.y<b.y;
}
int ind=0;
int off[111111];
int cnt=0;
void mark(int i){
	if(off[i]!=ind){
		off[i]=ind;
		cnt++;
	}
}

int main(){
	gn(n);gn(k);
	for (int i=1;i<=n;i++){
		int a,b,c,d;
		gn(a);
		gn(b);
		gn(c);
		gn(d);
		p[i].x=a+c;
		p[i].y=b+d;
		p[i].id=i;
	}
	for (int i=1;i<=n;i++)q[i]=p[i];
	sort(p+1,p+1+n,cmpx);
	sort(q+1,q+1+n,cmpy);
	
	ll mi=ll(6e18);
	for (int l=0;l<=k;l++)
		for (int r=0;r<=k;r++)
			for (int u=0;u<=k;u++)
				for (int d=0;d<=k;d++){
					++ind;cnt=0;
					for (int i=1;i<=l;i++)mark(p[i].id);
					for (int i=n;i>=n-r+1;i--)mark(p[i].id);
					for (int i=1;i<=d;i++)mark(q[i].id);
					for (int i=n;i>=n-u+1;i--)mark(q[i].id);
					if(cnt>k)continue;

					ll w=max(2ll,p[n-r].x-p[l+1].x);
					ll h=max(2ll,q[n-u].y-q[d+1].y);
					if(w&1)w++;
					if(h&1)h++;
					mi=min(mi,(w/2)*(h/2));
				}
	cout<<mi<<endl;
	return 0;
}