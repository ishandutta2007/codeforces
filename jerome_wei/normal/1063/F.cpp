#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
char s[N];

struct SuffixAutomaton{
	struct node{
		int ch[26],par;
		int len;
	}t[N<<1];
	int root,tail,cnt;
	inline int newnode(int len){
		t[++cnt].len=len;return cnt;
	}
	inline void init(){
		root=tail=newnode(0);
	}
	inline int extend(int c){
		int p=tail,np=newnode(t[tail].len+1);
		for(;p&&!t[p].ch[c];p=t[p].par)t[p].ch[c]=np;
		if(!p)t[np].par=root;
		else if(t[t[p].ch[c]].len==t[p].len+1)t[np].par=t[p].ch[c];
		else{
			int q=t[p].ch[c],nq=newnode(t[p].len+1);
			memcpy(t[nq].ch,t[q].ch,sizeof(t[nq].ch));
			t[nq].par=t[q].par;
			t[np].par=t[q].par=nq;
			for(;p&&t[p].ch[c]==q;p=t[p].par)t[p].ch[c]=nq;
		}
		return tail=np;
	}
}SAM;
int id[N];

typedef pair<int,int> pii;
namespace tree{
	int hed[N<<1],to[N<<1],nxt[N<<1],fa[N<<1],cnt,anc[N<<1][20];
	int fromlen[N<<1];
	inline void adde(int u,int v){
		++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
	}
	vector<pii> tags[N<<1];
	inline void dfs(int x,int pre){
		fa[x]=pre;anc[x][0]=fa[x];
		fromlen[x]=SAM.t[SAM.t[x].par].len+1;
		if(x==1)fromlen[x] = 0;
		for(int i=1;i<20;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];dfs(v,x);
		}
	}
	inline void pushtag(int x,int id,int f){
//		cout << "pushtag" << x << " " << id << " " << f << endl;
		int pos=x;
		for(int i=19;~i;i--){
			if(SAM.t[anc[pos][i]].len > f)pos=anc[pos][i];
		}
		while(tags[pos].size()==0||tags[pos].back().first <= f){
//			cout << pos << " " << tags[pos].size() << endl;
			if(tags[pos].size()!=0&&tags[pos].back().first == SAM.t[pos].len)break;
			tags[pos].push_back(pii(min(SAM.t[pos].len,f),id));
			pos = fa[pos];
		}
//		cout << "? " << endl;
	}
	inline int find(int x,int id){
//		cout << "find" << x << " " << id << endl;
		int pos=x;
		for(int i=19;~i;i--){
			int nxtpos = anc[pos][i];
			if(!nxtpos)continue;
			if(tags[nxtpos].size()==0)pos = nxtpos;
			else{
				if(fromlen[nxtpos]+tags[nxtpos][0].second > id){
					pos = nxtpos;
				}
			}
		}
		pos = fa[pos];
		if(!pos)return 0;
		int l=0,r=(int)tags[pos].size()-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			int stlen = (mid==0?fromlen[pos]:tags[pos][mid-1].first+1);
			if(stlen+tags[pos][mid].second <= id)l=mid;
			else r=mid-1;
		}
		int finalend=min(tags[pos][l].first,id-tags[pos][l].second);
		return finalend;
	}
}
int f[N];

int main()
{
	SAM.init();
	cin >> n;
	scanf("%s",s+1);
        reverse(s+1,s+n+1);
	for(int i=1;i<=n;++i)id[i]=SAM.extend(s[i]-'a');
	for(int i=1;i<=SAM.cnt;i++)if(SAM.t[i].par)tree::adde(SAM.t[i].par,i);
	tree::dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
//		cout << "we are now dealing with" << i << endl;
		f[i]=max(f[i],tree::find(id[i],i-1)+1);
		if(i<n)f[i+1]=max(f[i+1],tree::find(id[i],i)+1);
		ans=max(ans, f[i]);
		tree::pushtag(id[i],i,f[i]);
	}
	cout << ans << endl;
}