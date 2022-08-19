// hope don't UKE
#include<bits/stdc++.h>
const int MAXN=200000;
namespace FastIO{
	const int BUF_SIZE=1<<22;
	char buf[BUF_SIZE],*p1,*p2;
	char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	int read_int(){
		int ans=0;
		char c=gc();
		for(;(~c)&&!isdigit(c);c=gc());
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		return ans;
	}
	char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
}
using namespace FastIO;
struct couple{
	int pos,del;
	bool operator<(const couple&a)const{
		return del!=a.del?del>a.del:pos>a.pos;
	}
	bool operator==(const couple&a)const{
		return pos==a.pos&&del==a.del;
	}
};
template<class T>struct heap{
	std::priority_queue<T>h1,h2;
	void push(const T&a){
		h1.push(a);
	}
	void update(){
		for(;!h2.empty()&&h1.top()==h2.top();){
			h1.pop();
			h2.pop();
		}
	}
	void pop(){
		update();
		h1.pop();
	}
	void erase(const T&a){
		h2.push(a);
	}
	bool empty(){
		update();
		return h1.empty();
	}
	T top(){
		update();
		return h1.top();
	}
};
int n,ans;
int l[MAXN],r[MAXN],a[MAXN],q[MAXN>>1][2];
bool sex[MAXN];
heap<couple>h;
void solve(){
	n=read_int();
	for(int i=0;i!=n;++i)
		sex[i]=(read_char()=='B');
	for(int i=0;i!=n;++i)
		a[i]=read_int();
	for(int i=0;i+1!=n;++i)
		r[i]=i+1;
	r[n-1]=-1;
	for(int i=0;i!=n;++i)
		l[i]=i-1;
	for(int i=0;i+1!=n;++i)
		if(sex[i]!=sex[i+1])
			h.push({i,abs(a[i]-a[i+1])});
	for(;!h.empty();){
		auto c=h.top();
		h.pop();
		int u=c.pos,v=r[u];
		q[ans][0]=u+1;
		q[ans][1]=v+1;
		++ans;
		int p=l[u],q=r[v];
		if(~p){
			r[p]=q;
			if(sex[p]!=sex[u])
				h.erase({p,abs(a[p]-a[u])});
		}
		if(~q){
			l[q]=p;
			if(sex[v]!=sex[q])
				h.erase({v,abs(a[v]-a[q])});
		}
		if(~p&&~q&&sex[p]!=sex[q])
			h.push({p,abs(a[p]-a[q])});
	}
	printf("%d\n",ans);
	for(int i=0;i!=ans;++i)
		printf("%d %d\n",q[i][0],q[i][1]);
}
int main(){
	solve();
	return 0;
}