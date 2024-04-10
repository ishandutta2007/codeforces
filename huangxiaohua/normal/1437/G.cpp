#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

int i,j,k,n,m,t,it,cur,id[300500],l[300500],r[305000],it0=-1,res,op,f[300500];

struct AC{
	int mp[30],fail,id;
}a[300500];

queue<int> q;
string s;
vector<int> v[300500];

struct SB{
	#define ls ((id<<1))
	#define rs (ls+1)
	#define md ((l+r)>>1)
	#define get() f[id]=max(f[ls],f[rs])
	
	int x,y,w;
	multiset<int> s[1200500];
	
	void add(int id,int l,int r){
		//printf("NMSL %d %d %d %d\n",id,l,r,w);
		if(x<=l&&r<=y){
			if(w>=0)s[id].insert(w);
			else s[id].erase(s[id].find(-w));
			return;
		}
		if(x<=md)add(ls,l,md);
		if(y>md)add(rs,md+1,r);
	}
	
	void que(int id,int l,int r){
		//printf("nmsl %d %d %d %d\n",id,l,r,w);
		if(!s[id].empty()){
			w=max(*(--s[id].end()),w);
		}
		if(l==r){return;}
		if(x<=md)que(ls,l,md);
		if(y>md)que(rs,md+1,r);
	}
	
}sb;

void dfs(int x,int fa){
	l[x]=++it0;
	for(auto i:v[x]){
		if(i!=fa)dfs(i,x);
	}
	r[x]=it0;
	
	//printf("NIMASILE %d %d %d %d\n",x,fa,l[x],r[x]);
}

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	//#ifdef __WIN32
	//	#define gc getchar()
	//#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	//#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	inline string reads(){
		string t; char s=gc;
		while(!isalpha(s))s=gc;
		while(isalpha(s))t+=s,s=gc;
		return t;
	}
	inline void print(int x){
		if(x<0)return putchar('-'),print(-x),void();
		if(x>9)print(x/10);
		putchar(x%10+'0');
	}
} using namespace IO;

int main() {
	//cin.tie(0);
	n=read();t=read();
	for(i=1;i<=n;i++){
		s=reads();
		cur=0;
		for(auto j:s){
			j-='a'-1;
			if(!a[cur].mp[j])a[cur].mp[j]=++it;
			cur=a[cur].mp[j];
		}
		a[cur].id=i;
		id[i]=cur;
	}
	for(i=1;i<=26;i++){
		if(a[0].mp[i]){
			v[0].push_back(a[0].mp[i]);
			q.push(a[0].mp[i]);
		}
	}
	while(!q.empty()){
		k=q.front();q.pop();
		//printf("NMSL%d %d\n",k,a[k].fail);
		for(i=1;i<=26;i++){
			if(a[k].mp[i]){
				a[a[k].mp[i]].fail=a[a[k].fail].mp[i];
				v[a[a[k].mp[i]].fail].push_back(a[k].mp[i]);
				q.push(a[k].mp[i]);
			}
			else a[k].mp[i]=a[a[k].fail].mp[i];
		}
	}
	dfs(0,0);

	for(i=1;i<=n;i++){
		sb.x=l[id[i]]+1;sb.y=r[id[i]]+1;sb.w=0;
		sb.add(1,1,it+1);
	}
	while(t--){
		op=read();
		if(op==2){
			s=reads();
			res=-1;cur=0;
			for(auto i:s){
				i-='a'-1;
				cur=a[cur].mp[i];
				sb.x=sb.y=l[cur]+1;sb.w=-1;
				sb.que(1,1,it+1);
				res=max(res,sb.w);
			}
			print(res);putchar('\n');
		}
		else{
			j=read();k=read();
			sb.x=l[id[j]]+1;sb.y=r[id[j]]+1;
			
			if(f[j]){
				sb.w=-f[j];
				sb.add(1,1,it+1);
			}
			if(k){
				sb.w=k;
				sb.add(1,1,it+1);
			}
			
			f[j]=k;
		}
	}
}