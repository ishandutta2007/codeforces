/*********************************************************************
	Problem:CF710F
	Author:hydd
	Date:2020/7/26
*********************************************************************/
#include<cstdio>
#include<cstring>
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int m,op;
char s[310000];
struct node{
	int tot,cnt[310000],son[310000][26],ch[310000][26];
	int top,rt[21],sz[21],que[310000],fail[310000],num[310000];
	int merge(int x,int y){
		if (!x||!y) return x|y;
		cnt[x]+=cnt[y];
		for (int i=0;i<26;i++) son[x][i]=merge(son[x][i],son[y][i]);
		return x;
	}
	void build(int x){
		int head=1,tail=0;
		fail[x]=x;
		for (int i=0;i<26;i++){
			ch[x][i]=son[x][i];
			if (ch[x][i]){
				fail[ch[x][i]]=x;
				que[++tail]=ch[x][i];
			} else ch[x][i]=x;
		}
		while (head<=tail){
			int now=que[head++];
//			if (now==3) puts("");
			for (int i=0;i<26;i++){
				ch[now][i]=son[now][i];
				if (ch[now][i]){
					fail[ch[now][i]]=ch[fail[now]][i];
					que[++tail]=ch[now][i];
				}
				else ch[now][i]=ch[fail[now]][i];
			}
			num[now]=cnt[now]+num[fail[now]];
		}
	}
	void ins(char *s){
		int n=strlen(s+1);
		rt[++top]=++tot; sz[top]=1;
		int x=tot;
		for (int i=1;i<=n;i++){
			if (!son[x][s[i]-'a']) son[x][s[i]-'a']=++tot;
			x=son[x][s[i]-'a'];
		}
		cnt[x]++;
		while (top>1&&sz[top]==sz[top-1]){
			rt[top-1]=merge(rt[top-1],rt[top]); sz[top-1]+=sz[top];
			top--;
		}
		build(rt[top]);
	}
	int query(char *s){
		int n=strlen(s+1);
		int res=0;
		for (int i=1;i<=top;i++){
			int x=rt[i];
			for (int j=1;j<=n;j++){
				x=ch[x][s[j]-'a'];
				res+=num[x];
			}
		}
		return res;
	}
} T1,T2;
int main(){
	scanf("%d",&m);
	while (m--){
		scanf("%d%s",&op,s+1);
		if (op==1) T1.ins(s);
		if (op==2) T2.ins(s);
		if (op==3) printf("%d\n",T1.query(s)-T2.query(s)),fflush(stdout);
	}
	return 0;
}
/*
4
1 abc
2 abc
1 aba
3 abababc
*/