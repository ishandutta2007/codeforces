#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5,mo=1e9+7;
int T,n,a,b,x,y,pl,pr,lim;
int d[N],ds,tr[N],mx[N],mx2[N],bz[N];
//int mxd[]={1,4,6,7,10,5,5,0,5,2};
int mxd[N];
int dir[N][2],in[N][2],dl[2][N],dss[2],l[2];
int t[2][N*4];
vector<int>e[N];
bool yes;
bool find(int x,int no){
	d[++ds]=x;
	if(x==b)return 1;
	for(int i:e[x])
		if(i!=no&&find(i,x))return 1;
	--ds;
	return 0;
}
bool dfs(int x){
	bool ist=0;
	++bz[x];
	mx[x]=mx2[x]=0;
	for(int i:e[x])if(!bz[i]){
		if(dfs(i))ist=1;
		if(mx[i]+1>mx[x])mx2[x]=mx[x],mx[x]=mx[i]+1;
		else if(mx[i]+1>mx2[x])mx2[x]=mx[i]+1;
	}
	if(mx[x]>=ds&&mx2[x]>=ds)ist=1;
	--bz[x];
	return ist;
}
void up(int v,int o){
	t[o][v]=max(t[o][v*2],t[o][v*2+1]);
}
void build(int v,int l,int r){
	if(l==r){
		t[0][v]=mxd[l]+l;
		t[1][v]=mxd[l]-l;
		return;
	}
	int m=l+r>>1;
	build(v*2,l,m);build(v*2+1,m+1,r);
	fo(o,0,1)
		up(v,o);
}
void work(){
	int mxlen=mxd[ds];
	fd(i,1,ds-1){
		++mxlen;
		if(mxd[i]>=ds&&mxlen>=ds&&mxd[0]>=ds-i)
			yes=1;
		mxlen=max(mxlen,mxd[i]);
	}
}
void push(int x,int o){
	if(in[x][o])return;
	//printf("%d %d\n",x,o);
	dl[o][++dss[o]]=x;
	in[x][o]=1;
}
int find(int v,int l,int r,int o){
	if(t[o][v]<lim)return -1;
	if(l==r){
		t[o][v]=-1e9;
		return l;
	}
	int m=l+r>>1,res=-1;
	if(pl<=m)res=find(v*2,l,m,o);
	if(res!=-1)return up(v,o),res;
	if(m<pr)res=find(v*2+1,m+1,r,o);
	return up(v,o),res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	fo(tss,1,T){
		fo(i,1,n)e[i].clear();
		memset(bz,0,sizeof bz);
		memset(dir,0,sizeof dir);
		memset(in,0,sizeof in);
		cin>>n>>a>>b;
		fo(i,2,n)cin>>x>>y,e[x].pb(y),e[y].pb(x);
		yes=0;
		if(1){
			ds=-1;
			find(a,0);
			fo(i,0,ds)bz[d[i]]=1;
			fo(i,0,ds)
				tr[i]=dfs(d[i]),mxd[i]=mx[d[i]];	
		}
		build(1,0,ds);
		l[0]=l[1]=dss[0]=dss[1]=0;
		if(mxd[0])push(0,0);
		if(mxd[ds])push(ds,1);
		for(int x;l[0]<dss[0]||l[1]<dss[1];){
			if(l[0]<dss[0]){
				x=dl[0][++l[0]];
				pl=max(x+1,x+ds-mxd[x]);
				pr=ds;
				dir[max(x+1,x+ds-mxd[x])][0]=1;
				//printf("dir %d %d 0\n",x,max(x,x+ds-mxd[x]));
				lim=ds+x;
				for(;;){
					y=find(1,0,ds,0);
					if(y==-1)break;
					push(y,1);
					//printf("%d 0-> %d 1\n",x,y);
				}
			}else{
				x=dl[1][++l[1]];
				pl=0;
				pr=min(x-1,x-ds+mxd[x]);
				dir[min(x-1,x-ds+mxd[x])][1]=1;
				//printf("dir %d %d 1\n",x,min(x,x-ds+mxd[x]));
				lim=ds-x;
				for(;;){
					y=find(1,0,ds,1);
					if(y==-1)break;
					push(y,0);
					//printf("%d 1-> %d 0\n",x,y);
				}
			}
		}
		fo(i,1,ds)dir[i][0]|=dir[i-1][0];
		fd(i,0,ds-1)dir[i][1]|=dir[i+1][1];
		if(tr[0]||tr[ds])yes=1;
		fo(i,1,ds-1){
			if(tr[i]){
				if(dir[i][0]||dir[i][1])yes=1;
			}
			if(mxd[i]>=ds){
				if(dir[i][0]&&dir[i][1])
					yes=1;
			}
		}
		work();
		reverse(mxd,mxd+ds+1);
		work();
		printf(yes?"YES\n":"NO\n");
	}
}