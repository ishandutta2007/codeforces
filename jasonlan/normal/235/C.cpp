#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int SIZE=2020000,chrg=26;
int n,m;
char s[SIZE];
inline int read(){
	int res=0;
	char ch=getchar(),ch2=ch;
	while(!isdigit(ch))ch2=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch2=='-'?-res:res;
}
struct SAM{
	int ver,last;
	int nxt[chrg][SIZE],link[SIZE],len[SIZE];
	int vis[SIZE],cnt[SIZE];
	vector<int> v[SIZE];
	void init(){
		link[0]=-1;
		len[0]=ver=0;
	}
	void insertSAM(int ch){
		int cur=++ver,p=last;
		len[cur]=len[last]+1;
		while(~p&&!nxt[ch][p]){
			nxt[ch][p]=cur;
			p=link[p];
		}
		if(p==-1)
			link[cur]=0;
		else{
			int q=nxt[ch][p];
			if(len[q]==len[p]+1)link[cur]=q;
			else{
				int clone=++ver;
				for(register int i=0;i<chrg;++i)
					nxt[i][clone]=nxt[i][q];
				len[clone]=len[p]+1;
				while(~p&&nxt[ch][p]==q){
					nxt[ch][p]=clone;
					p=link[p];
				}
				link[clone]=link[q];
				link[q]=link[cur]=clone;
			}
		}
		last=cur;
		++cnt[last];
	}
	void dfs(int p){
		for(register int i=0;i<v[p].size();++i)
			dfs(v[p][i]),cnt[p]+=cnt[v[p][i]];
	}
	void getcnt(){
		for(register int i=1;i<=ver;++i)
			v[link[i]].push_back(i);
		dfs(0);
	}
	void query(int tsp){
		int L=strlen(s+1),ans=0;
		for(register int i=1;i<=L;++i)
			s[i+L]=s[i];
		for(register int st=0,ed=1,now=0;st<L;++ed){
			while(!nxt[s[ed]-'a'][now]){
				now=link[now];
				if(now==-1){
					puts("0");return;
				}
				else st=ed-1-len[now];
			}
			if(now==-1)break;
			now=nxt[s[ed]-'a'][now];
			if(ed-st==L){
				if(vis[now]^tsp)ans+=cnt[now];
				vis[now]=tsp;
				++st;
				if(len[link[now]]==L-1)now=link[now];
			}
		}
		printf("%d\n",ans);
	}
}T;
int main(){
	scanf("%s",s+1);
	T.init();
	for(register int i=1;s[i];++i)
		T.insertSAM(s[i]-'a');
	T.getcnt();
	for(register int i=read();i;--i){
		scanf("%s",s+1);
		T.query(i);
	}
	return 0;
}