#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,a[50050],pos[50050],id[50050],f[50050];ll res;
char s[50050];
priority_queue<pair<int,int> >q;

class SB{
	public:
	#define ls ((id<<1))
	#define rs (ls+1)
	#define md ((l+r)>>1)
	#define get() f[id]=min(f[ls],f[rs])
	int f[200500],x,y,k,w=-2,t[200500],res;
	
	void build(int id,int l,int r){
		if(l==r){f[id]=a[l];return;}
		build(ls,l,md);build(rs,md+1,r);
		get();
	}
	
	void add(int id,int l,int r){
		if(x<=l&&r<=y){
			f[id]+=w;t[id]+=w;
			return;
		}
		k=t[id];
		t[ls]+=k;t[rs]+=k;
		f[ls]+=k;f[rs]+=k;
		t[id]=0;
		if(x<=md)add(ls,l,md);
		if(y>md)add(rs,md+1,r);
		get();
	}
	
	void que(int id,int l,int r){
		if(x<=l&&r<=y){
			res=min(res,f[id]);
			return;
		}
		k=t[id];
		t[ls]+=k;t[rs]+=k;
		f[ls]+=k;f[rs]+=k;
		t[id]=0;
		if(x<=md)que(ls,l,md);
		if(y>md)que(rs,md+1,r);
		get();
	}
}sb;

int main(){
	cin>>s+1;
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		a[i]=a[i-1];
		if(s[i]=='?'){
			pos[++m]=i;id[i]=m;s[i]='(';
		}
		if(s[i]=='(')a[i]++;
		if(s[i]==')')a[i]--;
		if(a[i]<0){
			puts("-1");return 0;
		}
	}
	sb.build(1,1,n);
	if(a[n]&1){
		puts("-1");return 0;
	}
	t=a[n]/2;
	for(i=1;i<=m;i++){
		scanf("%d%d",&j,&k);
		res+=j;
		q.push({j-k,pos[i]});
	}
	while(t--){
		if(q.empty()){
			puts("-1");return 0;
		}
		auto [x,y]=q.top();q.pop();
		
		sb.x=y;sb.y=n;sb.res=114514;
		sb.que(1,1,n);
		if(sb.res<2){
			t++;continue;
		}
		res-=x;
		s[y]=')';
		sb.add(1,1,n);
	}
	cout<<res<<'\n'<<s+1;
}