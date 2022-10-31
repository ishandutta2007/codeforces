#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

template<typename T>
    using order_statistic_set =
    tree<
      T,
      null_type,
      less<T>,
      rb_tree_tag,
    tree_order_statistics_node_update>;

int i,j,k,n,m,t,a[1005000],res[1005000],x,y,z,num[1005000];

order_statistic_set<pair<int,int> > s;

vector<int> v[1005000];
vector<tuple<int,int,int> >q[1005000];

void write(int x){
	if(x>=10){write(x/10);}
	putchar('0'+(x%10));
}

int get(int lim,int rnk){
	if(s.size()<rnk){
		return 0;
	}
	int n=s.size(),sb;
	sb=s.order_of_key({lim,0});
	if((n-sb)<rnk)return 0;
	return s.find_by_order(rnk+sb-1)->second;
}

void dfs(int x){
	if(num[a[x]]){
		s.erase({num[a[x]],a[x]});
	}
	num[a[x]]++;
	s.insert({num[a[x]],a[x]});
	
	for(auto [id,lim,rnk]:q[x]){
		res[id]=get(lim,rnk);
	}
	
	for(auto i:v[x]){
		dfs(i);
	}
	
	s.erase({num[a[x]],a[x]});
	num[a[x]]--;
	if(num[a[x]]){
		s.insert({num[a[x]],a[x]});
	}
}

int main() {
	ios::sync_with_stdio(0);
	t=read();
	while(t--){
		s.clear();
		n=read();m=read();
		
		for(i=1;i<=n;i++){
			a[i]=read();
			num[i]=0;
			v[i].clear();
			q[i].clear();
		}
		
		for(i=2;i<=n;i++){
			k=read();
			v[k].push_back(i);
		}
		
		for(i=1;i<=m;i++){
			res[i]=0;
			x=read();y=read();z=read();
			q[x].push_back({i,y,z});
		}
		
		dfs(1);
		
		for(i=1;i<=m;i++){
			if(!res[i]){
				putchar('-');
				putchar('1');
				putchar(' ');
				continue;
			}
			write(res[i]);
			putchar(' ');
		}
		puts("");
	}
}