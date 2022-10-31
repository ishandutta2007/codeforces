#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

class AC{
public:
	struct sb{
		int son[13],fail,f;
	}s[10005];
	int it1,i,j,k,it,x,y;
	queue<int> q;
	
	void add(string st,int w){
		for(auto &i:st)i-='a'-1;
		it=0;
		for(auto i:st){
			if(!s[it].son[i]){s[it].son[i]=++it1;}
			it=s[it].son[i];
		}
		s[it].f+=w;
	}
	
	void build(){
		for(i=1;i<=12;i++){
			if(s[0].son[i]){q.push(s[0].son[i]);}
		}
		while(!q.empty()){
			x=q.front();q.pop();
			for(i=1;i<=12;i++){
				if(s[x].son[i]){
					q.push(s[x].son[i]);
					s[s[x].son[i]].fail=s[s[x].fail].son[i];
				}
				else{
					s[x].son[i]=s[s[x].fail].son[i];
				}
			}
			s[x].f+=s[s[x].fail].f;
		}
	}
}ac;

void fuck(int w,string s){
	for(auto &i:s)i-='a'-1;
	int l[22]={0},r[22]={0},n=s.size(),i,j,k,st=-1,lst;
	string sb;
	
	for(i=1;i<n;i++){
		for(k=0;k<=1;k++){
			if(l[s[i]]!=s[i-1]&&r[s[i]]!=s[i-1]){
				if(!l[s[i]])l[s[i]]=s[i-1];
				else if(!r[s[i]])r[s[i]]=s[i-1];
				else return;
			} 
			swap(s[i],s[i-1]);
		}
	}
	for(i=1;i<=12;i++)if(l[i]&&!r[i])st=i;
	if(st==-1)return;
	sb+=char(st+'a'-1);
	lst=st;st=l[st];
	while(1){
		sb+=char(st+'a'-1);
		if(!r[st])break;
		if(l[st]==lst){lst=st;st=r[st];}
		else{lst=st;st=l[st];}
	}
	ac.add(sb,w);
	reverse(sb.begin(),sb.end());
	ac.add(sb,w);
}

#define b(x) (1<<((x)-1))
int f[5005][5005],res;
char ch[5005][5005];

int dfs(int pos,int msk){
	if(~f[pos][msk])return f[pos][msk];
	int i,j,k,w;
	f[pos][msk]=0;
	for(i=1;i<=12;i++){
		if(msk&b(i))continue;
		j=ac.s[pos].son[i];
		w=dfs(j,msk|b(i));
		if(w>=f[pos][msk]){
			ch[pos][msk]=i;
			f[pos][msk]=w;
		}
	}
	f[pos][msk]+=ac.s[pos].f;
	return f[pos][msk];
}

void dfs2(int pos,int msk){
	if(msk==4095)return;
	int c=ch[pos][msk];
	cout<<char(c+'a'-1);
	int i=ac.s[pos].son[ c ];
	dfs2(i,msk|b(c));
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		int w;string s;
		cin>>w>>s;
		fuck(w,s);
	}
	ac.build();
	memset(f,-1,sizeof(f));
	dfs(0,0);
	dfs2(0,0);
}