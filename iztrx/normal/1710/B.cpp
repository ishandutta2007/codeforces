#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define ll long double
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define N 1000005
#define mod 998244353
struct node{
	ll x,y;
}vv[N],jd[N],uu,qwq;
int T,n,m,tot,s,j,las,cnt,i,x[N],p[N];
inline bool cmp(node aa,node bb){
	return aa.x<bb.x;
} 
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m;cnt=tot=0;j=1;
		for(i=1;i<=n;++i)cin>>x[i]>>p[i],
		vv[++tot].x=x[i]-p[i]+1,vv[tot].y=1,
		vv[++tot].x=x[i]+1,vv[tot].y=-2,
		vv[++tot].x=x[i]+p[i]+1,vv[tot].y=1;
		sort(vv+1,vv+tot+1,cmp);
		s=0;ll vn=0;las=0; 
		for(i=1;i<=tot;i=j){
			j=i;
			while(vv[j].x==vv[i].x&&j<=tot){
				s+=vv[j].y;++j;
			}
			vn+=(vv[i].x-vv[i-1].x)*las;
			if(i!=1&&las>=0&&s<=0){
				jd[++cnt].x=vv[i].x-1;
				jd[cnt].y=vn;
			}
			las=s;
		}tot=0;
		for(i=1;i<=cnt;++i){
			if(jd[i].y>m)vv[++tot]=jd[i];//,cout<<vv[tot].x<<" "<<vv[tot].y<<"\n";
		}
		if(!tot){
			for(i=1;i<=n;++i)cout<<1;cout<<"\n";continue;
		}
		qwq=vv[1];
		for(i=2;i<=tot;++i){
			if(vv[i].y>=qwq.y+abs(qwq.x-vv[i].x))qwq=vv[i];
			else if(qwq.y<=vv[i].y+abs(qwq.x-vv[i].x)){
				if(qwq.x>vv[i].x)swap(qwq,vv[i]);
				uu.y=((vv[i].x-qwq.x)+vv[i].y+qwq.y)/2;
				uu.x=((vv[i].y-qwq.y)+vv[i].x+qwq.x)/2;
				qwq=uu;
			}
		}
		for(i=1;i<=n;++i){
			if(p[i]+m-qwq.y+1e-6>=abs(qwq.x-x[i]))cout<<"1";
			else cout<<0;
		}
		cout<<"\n";
	}
}