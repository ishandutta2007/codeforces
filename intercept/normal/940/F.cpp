#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=2e5+9;
const int B=1400;
int n,q,num,n1,n2;
int a[M],b[M],c[M<<1],cnt[M],f[M<<1],ans[M];
int x[M],y[M],o[M];
struct P{
	int x,y,t;
}d[M],p[M];
int block(int x){
	return (x-1)/B+1;
}
void del(int x){
	cnt[f[x]]--;
	f[x]--;
	cnt[f[x]]++;
}
void add(int x){
	cnt[f[x]]--;
	f[x]++;
	cnt[f[x]]++;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		c[++num]=a[i];
	}
	for(int i=1;i<=q;++i){
		cin>>o[i]>>x[i]>>y[i];
		if(o[i]==2)c[++num]=y[i];
	}
	sort(c+1,c+num+1);
	num=unique(c+1,c+num+1)-c-1;
	for(int i=1;i<=n;++i)a[i]=lower_bound(c+1,c+num+1,a[i])-c;
	for(int i=1;i<=q;++i){
		if(o[i]==1){
			d[++n1]=P{x[i],y[i],i};
		}
		else {
			y[i]=lower_bound(c+1,c+num+1,y[i])-c;
			p[++n2]=P{x[i],y[i],i};
		}
	}
	sort(d+1,d+n1+1,[&](const P&l,const P&r){
		if(block(l.x)!=block(r.x))return l.x<r.x;
		if(block(l.y)!=block(r.y))return l.y<r.y;
		return l.t<r.t;
	});
	sort(p+1,p+n2+1,[&](const P&l,const P&r){
		return l.t<r.t;
	});
	for(int i=1,l=1,r=0,m=0;i<=n1;++i){
		int x=d[i].x,y=d[i].y;
		if(block(d[i-1].x)!=block(x)||block(d[i-1].y)!=block(y)||i==1){
			m=0;
			for(int j=1;j<=n;++j)b[j]=a[j];
			l=1,r=0;
			memset(cnt,0,sizeof(cnt));
			memset(f,0,sizeof(f));
		}
		while(r<y)add(b[++r]);
		while(l>x)add(b[--l]);
		while(r>y)del(b[r--]);
		while(l<x)del(b[l++]);
		while(m<n2&&p[m+1].t<d[i].t){
			m++;
			if(p[m].x>=l&&p[m].x<=r){
				del(b[p[m].x]);
				b[p[m].x]=p[m].y;
				add(b[p[m].x]);
			}
			else b[p[m].x]=p[m].y;
		}
		for(int j=1;j<500;++j){
			if(!cnt[j]){
				ans[d[i].t]=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;++i){
		if(o[i]==1)cout<<ans[i]<<"\n";
	}
	return 0;
}
/*
10 2
1 2 3 12 1 2 2 2 9 9
2 4 4
1 1 4

*/