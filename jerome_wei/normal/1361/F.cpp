#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 4e5+5;
int n,w[N],p[N],pos[N];
pair<int,int> mn[20][N];
int _lg[N];
void st_build(int n){
	for(int i=2;i<=n;i++)_lg[i]=_lg[i>>1]+1;
	for(int i=1;i<n;i++)mn[0][i]=pii(w[i],i);
	for(int i=1;1<<i<n;i++){
		for(int j=1;j<=n;j++)mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
	}
}
inline int qmn(int l,int r){
	int g=_lg[r-l+1];
	return min(mn[g][l],mn[g][r-(1<<g)+1]).second;
}
int s[N][2],fa[N];
int cnt=0;
inline int build(int x,int l,int r){
	// cerr << l << ":" << r << endl;
	int y=++cnt;
	fa[y]=x;
	if(l==r){
		pos[l]=y;return y;
	}
	int p=qmn(l,r-1);
	s[y][0]=build(y,l,p);
	s[y][1]=build(y,p+1,r);
	return y;
}

unsigned seed=19260817;
unsigned rnd(){
	seed^=seed<<17;seed+=142857u;seed^=seed>>5;seed^=seed<<3;
	return seed;
}

struct Node{
	int s,ch[2],sz;
	unsigned key;
}t[N*100];
int num;
void upd(int x){t[x].sz=1+t[t[x].ch[0]].sz+t[t[x].ch[1]].sz;}

inline int merge(int x,int y){
	if(!x||!y)return x|y;
	if(t[x].key<t[y].key){
		t[x].ch[1]=merge(t[x].ch[1],y);upd(x);
		return x;
	}else{
		t[y].ch[0]=merge(x,t[y].ch[0]);upd(y);
		return y;
	}
}
inline int delfirst(int x){
	if(!t[x].ch[0])return t[x].ch[1];
	t[x].ch[0]=delfirst(t[x].ch[0]);upd(x);
	return x;
}
inline pii split(int x,int k){
	if(!x)return pii(0,0);
	if(t[x].s<=k){
		pii r=split(t[x].ch[1],k);
		t[x].ch[1]=r.first;upd(x);
		return pii(x,r.second);
	}else{
		pii r=split(t[x].ch[0],k);
		t[x].ch[0]=r.second;upd(x);
		return pii(r.first,x);
	}
}
long long ans=0;
int rt[N];

long long Inv[N];
long long Sum[N];

inline void Ins(int x,int y){
	x=pos[x];
	while(fa[x]){
		ans-=min(Inv[fa[x]],Sum[fa[x]]-Inv[fa[x]]);
		t[++num].key=rnd();
		t[num].s=y;t[num].sz=1;
		int& rt0=rt[s[fa[x]][0]];
		int& rt1=rt[s[fa[x]][1]];
		if(s[fa[x]][0]==x){
			pii q=split(rt0,y);
			rt0=merge(q.first,merge(num,q.second));

			q=split(rt1,y);
			Inv[fa[x]]+=t[q.first].sz;
			rt1=merge(q.first,q.second);
			Sum[fa[x]]+=t[rt1].sz;
		}else{
			pii q=split(rt1,y);
			rt1=merge(q.first,merge(num,q.second));

			q=split(rt0,y);
			Inv[fa[x]]+=t[q.second].sz;
			rt0=merge(q.first,q.second);
			Sum[fa[x]]+=t[rt0].sz;
		}
		// cerr << fa[x] << ", " << Sum[fa[x]] << " -- " << Inv[fa[x]] << "," << ans << endl;
		ans+=min(Inv[fa[x]],Sum[fa[x]]-Inv[fa[x]]);
		// cerr << fa[x] << ", " << Sum[fa[x]] << " -- " << Inv[fa[x]] << "," << ans << endl;
		x=fa[x];
	}
}

inline void Del(int x,int y){
	x=pos[x];
	while(fa[x]){
		ans-=min(Inv[fa[x]],Sum[fa[x]]-Inv[fa[x]]);
		int& rt0=rt[s[fa[x]][0]];
		int& rt1=rt[s[fa[x]][1]];
		if(s[fa[x]][0]==x){
			pii q=split(rt1,y);
			Inv[fa[x]]-=t[q.first].sz;
			rt1=merge(q.first,q.second);
			Sum[fa[x]]-=t[rt1].sz;

			q=split(rt0,y-1);
			rt0=merge(q.first,delfirst(q.second));

		}else{
			pii q=split(rt0,y);
			Inv[fa[x]]-=t[q.second].sz;
			rt0=merge(q.first,q.second);
			Sum[fa[x]]-=t[rt0].sz;

			
			q=split(rt1,y-1);
			rt1=merge(q.first,delfirst(q.second));
		}
		ans+=min(Inv[fa[x]],Sum[fa[x]]-Inv[fa[x]]);
		
		// cerr << fa[x] << ", " << Sum[fa[x]] << " -- " << Inv[fa[x]] << endl;
		x=fa[x];
	}
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++)scanf("%d",&w[i]);
	st_build(n);
	build(0,1,n);
	for(int i=1;i<=n;i++)Ins(i,p[i]);
	// cerr << ans << "||" << endl;
	int m;cin >> m;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x^y){
			Del(x,p[x]),Del(y,p[y]);
			// cerr << ans << "---" << endl;
			swap(p[x],p[y]);
			Ins(x,p[x]),Ins(y,p[y]);
		}
		printf("%lld\n",ans);
	}
}