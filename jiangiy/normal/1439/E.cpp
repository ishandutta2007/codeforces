#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100010,INF=1e9+10;
std::vector<PI>get_ancestors(int x,int y){
	std::vector<PI>res;
	res.push_back(MP(x,y));
	for(int i=0;i<30;i++){
		if(x>>i&1){
			assert(~y>>i&1);
			x^=1<<i;
			res.push_back(MP(x,y));
		}
		if(y>>i&1){
			y^=1<<i;
			res.push_back(MP(x,y));
		}
	}
	return res;
}
std::map<int,std::vector<PI>>fx,fy;
std::map<int,int>g;
void add(std::map<int,std::vector<PI>>&f,int x,int l,int r){
	f[x].push_back(MP(l,r));
}
void add(int x1,int y1,int x2,int y2){
	if(x1==x2)add(fx,x1,y2+1,y1);
	else{
		assert(y1==y2);
		add(fy,y1,x2+1,x1);
	}
}
int getdir(int x,int y){
	int xt=x&-x,yt=y&-y;
	if(xt==0)xt=1<<30;
	if(yt==0)yt=1<<30;
	if(xt<yt)return 1;
	return 2;
}
void addp(int x,int y){
	if(getdir(x,y)==1)add(fy,y,x,x);
	else add(fx,x,y,y);
}
void addseg(int l,int r){
	g[l]^=1;
	g[r+1]^=1;
}
void work2(int v,std::vector<PI>&s){
	std::vector<PI>t;
	for(PI x:s){
		t.push_back(MP(x.fi,1));
		t.push_back(MP(x.se+1,-1));
	}
	std::sort(t.begin(),t.end());
	int sum=0,lst=INF;
	for(PI x:t){
		sum+=x.se;
		if(sum==0)addseg(v+lst,v+x.fi-1),lst=INF;
		if(sum)lst=std::min(lst,x.fi);
	}
}
void work(std::map<int,std::vector<PI>>&f){
	for(auto&a:f)work2(a.fi,a.se);
}
int main(){
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		std::vector<PI>a=get_ancestors(x1,y1);
		std::vector<PI>b=get_ancestors(x2,y2);
		int u=0,v=0;
		while(a[u]!=b[v]){
			int ad=a[u].fi+a[u].se,bd=b[v].fi+b[v].se;
			if(ad>bd)u++;
			else v++;
		}
		bool flag;
		if(u==0||v==0){
			flag=0;
		}
		else{
			int ad=getdir(a[u-1].fi,a[u-1].se),bd=getdir(b[v-1].fi,b[v-1].se);
			if(ad!=bd)flag=0;
			else{
				flag=1;
				int as=a[u-1].fi+a[u-1].se,bs=b[v-1].fi+b[v-1].se;
				if(bs<as)b.swap(a),std::swap(u,v);
			}
		}
		if(!flag){
			for(int j=0;j<u;j++){
				add(a[j].fi,a[j].se,a[j+1].fi,a[j+1].se);
			}
			for(int j=0;j<v;j++){
				add(b[j].fi,b[j].se,b[j+1].fi,b[j+1].se);
			}
			addp(b[v].fi,b[v].se);
		}
		else{
			for(int j=0;j<u-1;j++){
				add(a[j].fi,a[j].se,a[j+1].fi,a[j+1].se);
			}
			for(int j=0;j<v-1;j++){
				add(b[j].fi,b[j].se,b[j+1].fi,b[j+1].se);
			}
			add(b[v-1].fi,b[v-1].se,a[u-1].fi,a[u-1].se);
			addp(a[u-1].fi,a[u-1].se);
		}
	}
	work(fx),work(fy);
	int ans=0;
	for(PI x:g) if(x.fi&&x.se)ans++;
	printf("%d\n",ans);
}