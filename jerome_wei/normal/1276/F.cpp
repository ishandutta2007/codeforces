#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,SZ=26;
typedef long long ll;

char s[N];
int e1[N],e2[N];
int n;

struct Tree{
	int hed[N],to[N],nxt[N],cnt;
	int len[N],dfn[N],num,idfn[N];
	inline void adde(int u,int v){
		// cout << u << ":" << v << endl;
		++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
	}
	int dep[N],anc[N][20],sz[N];
	ll v[N];
	void dfs(int x,int pre){
		// cout << x << "<::>" << pre << endl;
		dfn[x]=++num;idfn[num]=x;
		v[x] = 1ll*len[x] + v[pre];
		dep[x]=dep[pre]+1;anc[x][0]=pre;
		for(int i=1;i<=19;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
		sz[x]=1;
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];
			dfs(v,x);sz[x]+=sz[v];
			if(!hvy[x]||sz[v]>sz[hvy[x]])hvy[x]=v;
		}
	}
	int lca(int x,int y){
		if(dep[x] < dep[y])swap(x,y);
		for(int i=19;~i;i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
		if(x==y)return x;
		for(int i=19;~i;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
		return anc[x][0];
	}
	int hvy[N],top[N];
	void dfs2(int x,int tp){
		top[x]=tp;
		if(hvy[x])dfs2(hvy[x],tp);
		for(int i=hed[x];i;i=nxt[i]){
			if(to[i]==hvy[x])continue;
			dfs2(to[i],to[i]);
		}
	}
}t1,t2;

struct SuffixAutomaton
{
	struct NODE{
		int ch[SZ],fa;
		int len,right;
	}t[N];
	int root,last,cnt;
	inline int newnode(int _len){
		t[++cnt].len=_len;
		return cnt;
	}
	inline void init(){//"?
		root=last=newnode(0);
	}
	inline int ins(int c)//"c=(char)-'a';
	{
		int nq=newnode(t[last].len+1),q=last;
		for(;q&&!t[q].ch[c];q=t[q].fa)t[q].ch[c]=nq;
		if(q==0) t[nq].fa=root;
		else if(t[t[q].ch[c]].len==t[q].len+1)t[nq].fa=t[q].ch[c];
		else{
			int np=newnode(t[q].len+1),p=t[q].ch[c];
			memcpy(t[np].ch,t[p].ch,sizeof(t[p].ch));
			t[np].fa=t[p].fa;
			t[p].fa=t[nq].fa=np;
			for(;q&&t[q].ch[c]==p;q=t[q].fa)t[q].ch[c]=np;
		}
		t[nq].right=1,last=nq;
		// cout << t[last].len << endl;
		return last;
	}
}s1,s2;
struct VitualTree{
	set<int> s;
	ll ans;
	void ins(int Node){
		int mx = 0;
		if(s.find(t2.dfn[Node])!=s.end())return;
		s.insert(t2.dfn[Node]);
		set<int>::iterator i = s.find(t2.dfn[Node]), nxt = i, pre = i;
		if(pre!=s.begin()){
			pre--;
			int d=t2.lca(t2.idfn[*pre],Node);
			if(t2.dep[d]>t2.dep[mx])mx=d;
		}
		++nxt;
		if(nxt!=s.end()){
			int d=t2.lca(t2.idfn[*nxt],Node);
			if(t2.dep[d]>t2.dep[mx])mx=d;
		}
		ans += t2.v[Node]-t2.v[mx];
	}
}Tr[N];
vector<int> nd[N];
ll ANS;
void Dfs(int x){
	if(t1.hvy[x])Dfs(t1.hvy[x]);
	for(size_t i=0;i<nd[x].size();i++){
		Tr[t1.top[x]].ins(nd[x][i]);
		// cout << t1.top[x] << ": " << nd[x][i] << "::" << Tr[t1.top[x]].ans << endl;
	}
	for(int i=t1.hed[x];i;i=t1.nxt[i]){
		if(t1.to[i]==t1.hvy[x])continue;
		Dfs(t1.to[i]);
		for(set<int>::iterator j = Tr[t1.to[i]].s.begin();j != Tr[t1.to[i]].s.end();j++){
			Tr[t1.top[x]].ins(t2.idfn[*j]);
		}
	}
	// cout << x << ":" << (Tr[t1.top[x]].ans+1) << endl;
	// cout << t1.anc[x][0] << endl;
	ANS+=Tr[t1.top[x]].ans * t1.len[x];
	// if(x>1){
		// cout << x << ":" << t1.len[x] << " par " << s1.t[x].fa << "::" << s1.t[x].len << endl;
	ANS += t1.len[x];
	// }
}

int main()
{
	s1.init(),s2.init();
	scanf("%s",s+1);n=strlen(s+1);
	e1[0]=1;
	for(int i=1;i<=n;i++){
		e1[i]=s1.ins(s[i]-'a');
		// cout << e1[i] << " -- ";
	}//puts("");
	nd[e1[n-1]].push_back(1);
	for(int i=n;i;i--){
		e2[i]=s2.ins(s[i]-'a');
		if(i>1)nd[e1[i-2]].push_back(e2[i]);
	}
	t1.len[1]=1;for(int i=2;i<=s1.cnt;i++)t1.len[i] = s1.t[i].len-s1.t[s1.t[i].fa].len, t1.adde(s1.t[i].fa,i);
	t2.len[1]=1;for(int i=2;i<=s2.cnt;i++)t2.len[i] = s2.t[i].len-s2.t[s2.t[i].fa].len, t2.adde(s2.t[i].fa,i);
	t1.dfs(1,0);
	t2.dfs(1,0);
	t1.dfs2(1,1);
	Dfs(1);
	cout << ANS << endl;
}
/* 
iixkczcxckckkxzzxizzzxxxzzczccxikxickxzzzxckkzkzxc
 */