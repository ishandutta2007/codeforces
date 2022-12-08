#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n,p[N],pos[N];
int fa[N];
pair<int,int> eular[N*2]; int num; // first : dep | second : id
int hed[N],to[N*2],nxt[N*2],cnt;
void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
int dep[N];
int fir[N];
inline void dfs(int x,int pre){
	dep[x] = dep[pre]+1;
	eular[++num] = make_pair(dep[x],x);
	fir[x] = num;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
		eular[++num] = make_pair(dep[x],x);
	}
}
pair<int,int> St[20][N];
int _log2[N];
inline void make_sparsetable(int n){
	_log2[1]=0;
	for(int i=2;i<=n;i++)_log2[i]=_log2[i>>1]+1;
	for(int i=1;i<=n;i++){
		St[0][i]=eular[i];
	}
	for(int i=1;1<<i<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			St[i][j] = min(St[i-1][j],St[i-1][j+(1<<(i-1))]);
		}
	}
}
inline void preset(){
	dfs(1,0);
//	for(int i=1;i<=num;i++)cout<<eular[i].second<<" ";puts("");
	make_sparsetable(num);
}
inline int Lca(int x,int y){
	x=fir[x],y=fir[y];
	if(x>y)swap(x,y);
	if(x == y)return eular[x].second; 
	int len = y-x+1, lg = _log2[len];
	return min(St[lg][x],St[lg][y-(1<<lg)+1]).second;
}
struct seg{
		int l,r;
		seg(int l=0,int r=0):l(l),r(r){}
		seg operator + (const int b)const{
			if((l==-1&&r==-1) || b==-1)return seg(-1,-1);
			int ca2=Lca(l,b),ca3=Lca(r,b),ca4=Lca(l,r);
			if(ca4==l||ca4==r){
				if(l==r)return seg(l,b);
				int t=l^r^ca4;
				if(ca2==l&&ca3==r)return seg(b,l^r^t);
				else if(ca2==ca3)return seg(b,t);
				else if(ca2==b||ca3==b)return seg(l,r);
				else return seg(-1,-1);
			}
//			cout<<l<<" "<<r<<" "<<b<<"::" <<ca2<<' '<<ca3<<" "<<ca4<<endl;
			if(ca2==b && ca3==b && ca4!=b && l!=r)return seg(-1,-1);
			if(ca2==l)return seg(b,r);
			if(ca3==r)return seg(l,b);
			if(ca2==b||ca3==b)return seg(l,r);
			return seg(-1,-1);
		}
		seg operator * (const seg B){
			return (B + l)+r;
		}
		bool ifnull(){return l==-1;}
};
struct SegT{
	seg t[N<<2];

	inline void build(int x,int l,int r){
		int mid=(l+r)>>1;
		if(l==r){t[x] = seg(pos[l],pos[l]);return ;}
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
		t[x] = t[x<<1] * t[x<<1|1];
//		cout<<t[x<<1].l<<" "<<t[x<<1].r<<" ------- "<<t[x<<1|1].l<<" "<<t[x<<1|1].r<<endl;
//		cout<<x<<" "<<l<<" "<<r<<":"<<t[x].l<<","<<t[x].r<<endl;
		return;
	}
	inline void chg(int x,int l,int r,int pos,seg tmp){
		int mid=(l+r)>>1;
		if(l==r){ t[x] = tmp; return ;}
		if(pos<=mid) chg(x<<1,l,mid,pos,tmp);
		else chg(x<<1|1,mid+1,r,pos,tmp);
		t[x] = t[x<<1] * t[x<<1|1];
	}
	inline int findans(int x,int l,int r,seg curSeg){//at the beginning : curSeg = (pos0,pos0);
		int mid=(l+r)>>1;
		if(l==r){
			if(!(curSeg*t[x]).ifnull())return l;
			else return l-1;
		}
		if(!(curSeg*t[x<<1]).ifnull())return findans(x<<1|1,mid+1,r,curSeg*t[x<<1]);
		else return findans(x<<1,l,mid,curSeg);
	}
}T;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		adde(fa[i],i);adde(i,fa[i]);
	};
	preset();
	T.build(1,0,n-1);
	int Q;cin >> Q;
	while(Q--){
		int opt;scanf("%d",&opt);
		if(opt==2) {
			printf("%d\n",1+T.findans(1,0,n-1,seg(pos[0],pos[0])));
		} else {
			int l,r;scanf("%d%d",&l,&r);
			swap(p[l],p[r]);
			pos[p[l]]=l,pos[p[r]]=r;
			T.chg(1,0,n-1,p[l],seg(pos[p[l]],pos[p[l]]));
			T.chg(1,0,n-1,p[r],seg(pos[p[r]],pos[p[r]]));
		}
	}
}