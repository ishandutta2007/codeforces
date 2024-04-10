#include<bits/stdc++.h>
using namespace std;
int tot=0,cur1,cur2;
int root[55],siz[55];
int trie[300005][26];
int fail[300005];
int dp[300005];
bool vis[300005];
stack<int>st;
vector<string>c[55];
queue<int>q;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int nwnode(){
	if(st.empty())return ++tot;
	int k=st.top();
	st.pop();
	vis[k]=0;
	return k;
}
void trash(int x){
	if(vis[x])return ;
	vis[x]=1;
	for(int i=0;i<26;i++)
		if(trie[x][i])
			trash(trie[x][i]);
	st.push(x);
	for(int i=0;i<26;i++)trie[x][i]=0;
	fail[x]=dp[x]=0;
	return ;
}
void ins(int v,string s){
	int x=root[v];
	for(int i=0;i<s.size();i++){
		int to=s[i]-'a';
		if(!trie[x][to])
			trie[x][to]=nwnode();
		x=trie[x][to];
	}
	dp[x]=1;
	return ;
}
void pre(int v){
	fail[root[v]]=root[v];
	for(int i=0;i<26;i++)
		if(trie[root[v]][i]){
			fail[trie[root[v]][i]]=root[v];
			q.push(trie[root[v]][i]);
		}
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int tmp=trie[k][i];
			if(tmp){
				fail[tmp]=trie[fail[k]][i];
				if(!fail[tmp])fail[tmp]=root[v];
				dp[tmp]+=dp[fail[tmp]];
				q.push(tmp);
			}
			else
				trie[k][i]=trie[fail[k]][i];
		}
	}
	return ;
}
int query(int v,string s){
	int ans=0;
	int x=root[v];
	for(int i=0;i<s.size();i++){
		int to=s[i]-'a';
//		cout<<"*"<<x<<" "<<flag[x]<<endl;
		x=trie[x][to];
		if(!x)x=root[v];
		ans+=dp[x];
	}
	return ans;
}
void out(int x){
	if(vis[x])return ;
	vis[x]=1;
	cout<<x<<"->";
	for(int i=0;i<26;i++)
		if(trie[x][i])
			cout<<char(i+'a')<<":"<<trie[x][i];
	cout<<endl;
	for(int i=0;i<26;i++)
		if(trie[x][i])
			out(trie[x][i]);
	return ;
}
int main(){
	int m;
	m=read();
	cur2=20;
	for(int i=1;i<=m;i++){
		int opt;
		string s;
		opt=read();
		cin>>s;
		if(opt==1){
			int pos=cur1+1;
			for(int j=0;j<=19;j++)
				if(siz[pos-1]==(1<<j))pos--;
				else break;
			siz[pos]=1<<(cur1+1-pos);
			for(int j=pos;j<=cur1;j++)trash(root[j]);
			root[pos]=nwnode();
			for(int k=0;k<c[pos].size();k++)
				ins(pos,c[pos][k]);
			for(int j=pos+1;j<=cur1;j++){
				for(int k=0;k<c[j].size();k++){
					ins(pos,c[j][k]);
					c[pos].push_back(c[j][k]);
				}
				c[j].clear();
			}
			ins(pos,s);
			c[pos].push_back(s);
			pre(pos);
			cur1=pos;
		}
		else if(opt==2){
			int pos=cur2+1;
			for(int j=0;j<=19;j++)
				if(siz[pos-1]==(1<<j))pos--;
				else break;
			siz[pos]=1<<(cur2+1-pos);
			for(int j=pos;j<=cur2;j++)trash(root[j]);
			root[pos]=nwnode();
			for(int k=0;k<c[pos].size();k++)
				ins(pos,c[pos][k]);
			for(int j=pos+1;j<=cur2;j++){
				for(int k=0;k<c[j].size();k++){
					ins(pos,c[j][k]);
					c[pos].push_back(c[j][k]);
				}
				c[j].clear();
			}
			ins(pos,s);
			c[pos].push_back(s);
			pre(pos);
			cur2=pos;
		}
		else{
			int ans=0;
			for(int j=1;j<=cur1;j++)
				ans+=query(j,s);
			for(int j=21;j<=cur2;j++)
				ans-=query(j,s);
			printf("%d\n",ans);
		}
		fflush(stdout);
	}
	return 0;
}