#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char s[N];
int nxt[N],n;
int stk[N], top;
int stk2[N], top2;
int type=0;

bool vis[N];
vector<int> path;
int to[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n%2){
		type=1;
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='L')cnt0++;
			else cnt1++;
		}
		s[++n]=cnt0<cnt1?'L':'R';
	}
	top=top2=0;
	for(int i=1;i<=n;i++){//L->R
		if(s[i]=='R'){
			if(!top)stk2[++top2]=i;
			else nxt[stk[top--]]=i;
		}
		else{
			stk[++top]=i;
		}
	}
	while(top){
		nxt[stk[top--]]=stk2[top2--];
	}
	top=top2=0;
	for(int i=1;i<=n;i++){//R->L
		if(s[i]=='L'){
			if(!top)stk2[++top2]=i;
			else nxt[stk[top--]]=i;
		}
		else{
			stk[++top]=i;
		}
	}
	while(top){
		nxt[stk[top--]]=stk2[top2--];
	}
	int S,T;
	S=T=1;
	vis[1]=1;
	while(!vis[nxt[T]])vis[nxt[T]]=1,to[T]=nxt[T],T=nxt[T];
	for(int j=2;j<=n;j++)if(!vis[j]){
		int ss=j;vis[ss]=1;int tt=ss;
		while(!vis[nxt[tt]])vis[nxt[tt]]=1,to[tt]=nxt[tt],tt=nxt[tt];
		if(s[T]!=s[ss]){
			to[T]=ss;
			T=tt;
		}else{
			int ns=to[S];
			to[S]=ss;
			to[tt]=ns;
		}
	}
	vector<int> path(1,S);
	for(int i=2;i<=n;i++){
		path.push_back(to[path.back()]);
	}
	int st=0;
	while(path[st]!=n)++st;
	vector<int> r;
	for(int i=1;i<=n;i++){
		r.push_back(path[(st+i)%n]);
	}
	if(type)r.pop_back();
	int ans=0;
	for(int i=0;i+1<(int)r.size();i++){
		if(r[i+1]<r[i])ans++;
	}
	cout << ans << endl;
	for(size_t i=0;i<r.size();i++)printf("%d ",r[i]);
	puts("");
}