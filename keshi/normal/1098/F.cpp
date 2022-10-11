#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
#define last last2
 
using namespace std;
 
typedef long long ll;
 
char str[200005];
int n;
 
struct BIT {
 
ll sumv[200005];
 
void add(int x,int num) {
  for(;x<=n;x+=lowbit(x)) sumv[x]+=num;
}
 
ll sum(int x) {
  ll s=0;
  for(;x;x-=lowbit(x)) s+=sumv[x];
  return s;
}
 
ll sum(int l,int r) {
  return sum(r)-sum(l-1);
}
 
};
 
vector <int> e[400005];
int pos[200005],mx[400005];
 
namespace SAM {
 
int ch[400005][26];
int fa[400005];
int tot=1,last=1;
 
void add(char x,int id) {
  x-='a';
  int p=last,np=++tot;
  mx[np]=mx[p]+1;
  pos[id]=np;
  for(;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
  if (!p) fa[np]=1;
  else {
  	int q=ch[p][x];
  	if (mx[q]==mx[p]+1) fa[np]=q;
  	else {
  		int nq=++tot;
  		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
  		mx[nq]=mx[p]+1;
  		fa[nq]=fa[q];
  		fa[q]=fa[np]=nq;
  		for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
	  }
  }
  last=np;
}
 
void build() {
  for(int i=n;i>0;i--) add(str[i],i);
  for(int i=2;i<=tot;i++) e[fa[i]].push_back(i);
}
 
}
 
ll ans[200005];
 
namespace HLD {
 
int fa[400005],dep[400005];
int size[400005],son[400005];
 
void dfs1(int x) {
  size[x]=1;
  for(int i=0;i<e[x].size();i++) {
  	int u=e[x][i];
  	fa[u]=x;dep[u]=dep[x]+1;
  	dfs1(u);
  	size[x]+=size[u];
  	if (size[u]>size[son[x]]) son[x]=u;
  }
}
 
int top[400005];
 
void dfs2(int x,int anc) {
  top[x]=anc;
  if (son[x]) dfs2(son[x],anc);
  for(int i=0;i<e[x].size();i++)
    if (e[x][i]!=fa[x]&&e[x][i]!=son[x]) dfs2(e[x][i],e[x][i]);
}
 
struct Data {
  int kind,x,y,id;
  Data() {}
  Data(int a,int b,int c,int d):kind(a),x(b),y(c),id(d) {}
  bool operator < (const Data & b) const {return (x!=b.x)?x<b.x:kind>b.kind;}
};
 
vector <Data> vt1[400005],vt2[400005];
 
void insert1(int x) {
  int y=pos[x];
  while (y) {
  	int r1=x+mx[fa[top[y]]],r2=mx[y]-mx[fa[top[y]]];
  	vt1[top[y]].push_back(Data(1,r1,0,0));
  	vt1[top[y]].push_back(Data(2,r1+r2,r2,0));
  	vt2[top[y]].push_back(Data(1,x,r2,0));
  	y=fa[top[y]];
  }
}
 
void insert2(int l,int r,int id) {
  int x=pos[l];
  while (x) {
  	if (mx[fa[top[x]]]<r-l+1) {
  		int t=mx[x]-mx[fa[top[x]]];
  		vt1[top[x]].push_back(Data(0,r,min(t,r-l+1-mx[fa[top[x]]]),id));
  		vt2[top[x]].push_back(Data(0,l-1,min(t,r-l+1-mx[fa[top[x]]]),id));
	  }
	x=fa[top[x]];
  }
}
 
void build() {
  for(int i=0;i<e[1].size();i++) {
  	int u=e[1][i];
  	dfs1(u);
  	dfs2(u,u);
  }
  for(int i=1;i<=n;i++) 
    insert1(i);
}
 
BIT s1,s2,s3,s4;
 
void solve() {
  for(int i=1;i<=SAM::tot;i++)
    if (vt1[i].size()) {
    	sort(vt1[i].begin(),vt1[i].end());
    	sort(vt2[i].begin(),vt2[i].end());
    	for(int j=0;j<vt1[i].size();j++) {
    		Data t=vt1[i][j];
    		if (!t.kind) {
    			ans[t.id]+=s1.sum(1,t.x-t.y)*t.y;
    			ans[t.id]+=s1.sum(t.x-t.y+1,t.x)*(t.x+1)-s2.sum(t.x-t.y+1,t.x);
    			ans[t.id]+=s3.sum(1,t.y);
    			ans[t.id]+=s4.sum(t.y+1,t.x)*t.y;
			}
			else if (t.kind==1) {
				s1.add(t.x,1);
				s2.add(t.x,t.x);
			}
			else {
				s1.add(t.x-t.y,-1);
				s2.add(t.x-t.y,-t.x+t.y);
				s3.add(t.y,t.y);
				s4.add(t.y,1);
			}
		}
	    for(int j=0;j<vt1[i].size();j++) {
	    	Data t=vt1[i][j];
	    	if (t.kind==1) {
	    		s1.add(t.x,-1);
	    		s2.add(t.x,-t.x);
			}
			else if (t.kind==2) {
				s1.add(t.x-t.y,1);
				s2.add(t.x-t.y,t.x-t.y);
				s3.add(t.y,-t.y);
				s4.add(t.y,-1);
			}
		}
		for(int j=0;j<vt2[i].size();j++) {
			Data t=vt2[i][j];
			if (!t.kind) {
				ans[t.id]-=s1.sum(1,t.y);
				ans[t.id]-=s2.sum(t.y+1,n)*t.y;
			}
			else {
				s1.add(t.y,t.y);
				s2.add(t.y,1);
			}
		}
		for(int j=0;j<vt2[i].size();j++) {
			Data t=vt2[i][j];
			if (t.kind==1) {
				s1.add(t.y,-t.y);
				s2.add(t.y,-1);
			}
		}
	}
}
 
}
 
int main() {
  scanf("%s",str+1);
  n=strlen(str+1);
  SAM::build();
  HLD::build();
  int m;
  scanf("%d",&m);
  for(int i=1;i<=m;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	HLD::insert2(x,y,i);
  }
  HLD::solve();
  for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
  return 0;
}