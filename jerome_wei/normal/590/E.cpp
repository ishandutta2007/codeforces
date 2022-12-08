#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+5, M = 755;
int cur,n,lft[M],rgt[M];
char s[N];
int g[M][M];

struct ACautomaton{
	int c[N][2],val[N],fail[N],cnt;
	void ins(char *s,int len,int t){
		int now=0;
		for(int i=0;i<len;i++){
			int v=s[i]-'a';
			if(!c[now][v])c[now][v]=++cnt;
			now=c[now][v];
		}
		val[now] = t;
	}
	queue<int> q;
	void build(){
		for(int i=0;i<2;i++)if(c[0][i])fail[c[0][i]]=0,q.push(c[0][i]);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<2;i++){
				if(c[u][i])fail[c[u][i]]=c[fail[u]][i],q.push(c[u][i]);
				else c[u][i]=c[fail[u]][i];
			}
			if(!val[u])val[u]=val[fail[u]];
		}
	}
	inline void run(char *s,int len,int t){
		int now=0;
		for(int i=0;i<len;i++){
			int ch=s[i]-'a';
			now = c[now][ch];
			if(val[now])g[t][val[now]]=1;
			if(val[fail[now]])g[t][val[fail[now]]]=1;
		}
	}
}AC;

bool vis[M];
int match[M];
inline bool dfs(int x){
	for(int j=1;j<=n;j++){
		if(g[x][j] && !vis[j]){
			vis[j]=1;
			if(match[j]==0||dfs(match[j])){
				match[j]=x;
				return 1;
			}
		}
	}
	return 0;
}

inline void MATCH(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)vis[j]=0;
		ans+=dfs(i);
	}
	cout << n - ans << endl;
}
int nxt[N],col[N];

int main()
{
	cin >> n;
	cur = 0;
	for(int i=1;i<=n;i++){
		scanf("%s",s+cur);
		int l=strlen(s+cur);
		lft[i]=cur,rgt[i]=cur+l-1;
		AC.ins(s+cur,l,i);
		cur+=l;
	}
	AC.build();
	for(int i=1;i<=n;i++){
		AC.run(s+lft[i],rgt[i]-lft[i]+1,i);
	}
	for(int i=1;i<=n;i++)g[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(g[j][i]){
			for(int k=1;k<=n;k++)if(g[i][k]){
				g[j][k]=1;
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++)cout << g[i][j] << " ";
	// 	puts("");
	// }
	MATCH();
	vector<int> st;
	for(int i=1;i<=n;i++)if(match[i])nxt[match[i]]=i;else st.push_back(i); 
	while(1){
		for(size_t i=0;i<st.size();i++){
			for(size_t j=0;j<st.size();j++){
				if(g[st[i]][st[j]]){
					st[i] = nxt[st[i]];
					goto END;
				}
			}
		}
		break;
		END:;
	}
	for(size_t i=0;i<st.size();i++)printf("%d ",st[i]?st[i]:1);puts("");
}