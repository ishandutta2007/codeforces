#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef pair<int,int> pi;
int a[N],b[N],n,m,t,M=1<<18,f[N],c[N],pre[N];
int refl[N];
map<int,int> p,q;
pi tr[N*4],d[N];
void build(){
	for (int i=1;i<=t;i++)tr[i+M]=d[i];
	for (int i=M;i;i--)tr[i]=max(tr[i+i],tr[i+i+1]);
}
pi qmax(int l,int r){
	pi ans=make_pair(0,0);
	for (l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
		if (~l&1)ans=max(ans,tr[l^1]);
		if ( r&1)ans=max(ans,tr[r^1]);
	}return ans;
}
void add(int x,pi v){
	d[x]=max(d[x],v);
	for (x+=M;x;x>>=1)tr[x]=max(tr[x],v);
}
multiset<int> s,s1;
vector<int> w;
void pop(){
	s.erase(s.find(*s.rbegin()));
}
vector<pi> h;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]]=1;
	cin>>m;
	for (int i=1;i<=m;i++)scanf("%d",&b[i]),p[b[i]]=1;
	sort(b+1,b+m+1);
	for (auto x:p)
		if (x.first>0){
			q[x.first]=++t;
			refl[t]=x.first;
		}
	for (int i=1;i<=n;i++)
		if (a[i]>0)a[i]=q[a[i]];
	for (int i=1;i<=m;i++)b[i]=q[b[i]],c[b[i]]=1;
	h.push_back(make_pair(0,0));
	for (int i=1;i<=n;i++){
		if (a[i]>=0){
			int k=0;
			for (int u=1<<16;u;u>>=1){
				if (k+u<h.size()){
					if (h[k+u].first<a[i])k+=u;
				}
			}
			f[i]=k+1;
			pre[i]=h[k].second;
			if (k+1==h.size())h.push_back(make_pair(1e9,1e9));
			h[k+1]=min(h[k+1],make_pair(a[i],i));
		}
		else {
			int p=m;
			if (h.back().first<b[m]){
				while (b[p-1]>h.back().first)p--;
				h.push_back(make_pair(b[p],h.back().second));
			}
			for (int i=h.size()-1;i;i--){
//				if (h[i].first>=b[m])break;
				while (b[p-1]>h[i-1].first)p--;
				if (b[p]>h[i-1].first)h[i]=min(h[i],make_pair(b[p],h[i-1].second));
			}
		}
	}
	s.insert(-1);
	for (int i=1;i<=m;i++)s.insert(b[i]);
	pi z=make_pair(h.size()-1,h.back().second);
	int k=z.first-f[z.second];
	for (int i=n;k;i--){
		if (a[i]==-1){
			k--;
			a[i]=*s.rbegin();
			pop();
			while (*s.rbegin()==a[i]){
				s1.insert(*s.rbegin());
				pop();				
			}
			if (!k)break;
		}
	}
	while (!s.empty()&&*s.rbegin()>=a[z.second]){
		s1.insert(*s.rbegin());
		pop();
	}
	for (int now=z.second,x=pre[now];now;now=x,x=pre[x]){
		k=f[now]-f[x]-1;
		for (int i=now;k;i--){
			if (a[i]==-1){
				k--;
				a[i]=*s.rbegin();
				pop();
				while (*s.rbegin()==a[i]){
					s1.insert(*s.rbegin());
					pop();				
				}
				if (!k)break;
			}
		}
		while (!s.empty()&&*s.rbegin()>=a[x]){
			s1.insert(*s.rbegin());
			pop();
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i]==-1){
			a[i]=*s1.begin();
			s1.erase(s1.begin());
		}
		printf("%d ",refl[a[i]]);
	}
}