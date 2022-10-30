#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,it,cx,cy,r1,r2,h;
set<pair<int,int> > s[400500];

int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
int f[100500];

void add(int id,int l,int r,int ls,int rs){
	int md=(l+r)>>1;
	if(ls<=l&&r<=rs){
		if(cx<=0)s[id].erase({cx,cy});
		else s[id].insert({-cx,cy});
		return;
	}
	if(ls<=md)add(id*2,l,md,ls,rs);
	if(rs>md)add(id*2+1,md+1,r,ls,rs);
}

void get(int id,int l,int r,int ls,int rs){
	int md=(l+r)>>1;
	if(!s[id].empty()){
		auto [x,y]=*s[id].begin();x=-x;
		if(x>r1){r1=x;r2=y;}
	}
	if(ls<=l&&r<=rs){return;}
	if(ls<=md)get(id*2,l,md,ls,rs);
	if(rs>md)get(id*2+1,md+1,r,ls,rs);
}

struct sb{
	int id,l,r,h,k;
	bool operator<(const sb a)const{
		if(h==a.h) return id<a.id;
		return h<a.h;
	}
}s1[200500];

int main(){
	f[0]++;//
	scanf("%d%d%d",&h,&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d",&s1[i].h,&s1[i].l,&s1[i].r,&k);
		s1[i].id=i;
		s1[i].k=k+1;
		s1[m+i]=s1[i];
		s1[m+i].h+=k+1;
		s1[m+i].id*=-1;
	}
	m+=m+1;
	s1[m].h=h+1;
	s1[m].id=1000000000;
	sort(s1+1,s1+m+1);
	for(i=1;i<=m;i++){
		auto [id,l,r,h,k]=s1[i];
		if(id==1000000000){
			int ans=0;
			for(j=1;j<=n;j++){
				r1=-1;r2=0;
				get(1,1,n,j,j);
				ans=su(ans,f[r2]);
			}
			printf("%d",ans);return 0;
		}
		if(id>0){
			r1=-1;r2=0;
			if(l==1){
				get(1,1,n,r+1,r+1);
				f[id]=su(f[r2],f[r2]);
			}
			else{
				get(1,1,n,l-1,l-1);
				if(r==n){
					f[id]=su(f[r2],f[r2]);
				}
				else{
					f[id]=f[r2];
					r1=-1;r2=0;
					get(1,1,n,r+1,r+1);
					f[id]=su(f[id],f[r2]);
				}
			}
			cx=h;cy=id;
		}
		else{
			cx=-h+k;cy=-id;
		}
		add(1,1,n,l,r);
	}
}