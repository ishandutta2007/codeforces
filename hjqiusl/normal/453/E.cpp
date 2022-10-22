//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],m[N];
int vis[N];
int Q;
struct
{
	int rt[N],cnt,tr[N*35];
	int lson[N*35];
	int rson[N*35];
	void pushup(int k)
	{
		tr[k]=tr[lson[k]]+tr[rson[k]];
	}
	void update(int &k,int lst,int l,int r,int L,int val)
	{
		k=++cnt;
		lson[k]=lson[lst];
		rson[k]=rson[lst];
		tr[k]=tr[lst];
		if (l==r) return tr[k]+=val,void();
		int mid=l+(r-l)/2;
		if (L<=mid) update(lson[k],lson[lst],l,mid,L,val);
		else update(rson[k],rson[lst],mid+1,r,L,val);
		pushup(k);
	}
	int query(int k,int lst,int l,int r,int L,int R)
	{
		if (L>R) return 0;
		if (k==lst) return 0;
		if (L<=l&&r<=R) return tr[lst]-tr[k];
		int mid=l+(r-l)/2,res=0;
		if (L<=mid) res+=query(lson[k],lson[lst],l,mid,L,R);
		if (R>mid) res+=query(rson[k],rson[lst],mid+1,r,L,R);
		return res;
	}
}T1,T2; 
multiset<pa>S;
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),m[i]=read(),b[i]=read();
		S.insert(mp(i,0));
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==0)
		{
			T1.rt[i]=T1.rt[i-1];
			T2.rt[i]=T2.rt[i-1];
			continue;
		}
		T1.update(T1.rt[i],T1.rt[i-1],0,N-5,ceil(m[i]*1.0/b[i]),b[i]);
		T2.update(T2.rt[i],T2.rt[i-1],0,N-5,ceil(m[i]*1.0/b[i]),m[i]);
	}
	S.insert(mp(0,0));
	S.insert(mp(n+1,0));
	Q=read();
	for (int i=1;i<=Q;i++)
	{
		int opt=read(),l=read(),r=read();
		int ans=0;
		auto it=S.lower_bound(mp(l,0));
		if ((*it).fi!=l)
		{
			it--;
			S.insert(mp(l,(*it).se));
		}
		it=S.lower_bound(mp(r+1,0));
		if ((*it).fi!=r+1)
		{
			it--;
			S.insert(mp(r+1,(*it).se));
		}
		it=S.lower_bound(mp(l,0));
		while ((*it).fi!=r+1)
		{
			auto U=(*it);
			int u=U.fi,v=U.se;
			auto it2=it;
			it2++;
			int nxt=(*it2).fi;
			if (!vis[u])
			{
				if (a[u]+opt*b[u]>=m[u])
					ans+=m[u];
				else ans+=a[u]+opt*b[u];
				// cout<<"???"<<u<<" "<<ans<<endl;
				vis[u]=1;
			} else
			{
				ans+=T1.query(T1.rt[u-1],T1.rt[nxt-1],0,N-5,opt-v+1,N-5)*(opt-v)+
				T2.query(T2.rt[u-1],T2.rt[nxt-1],0,N-5,0,opt-v);
				// cout<<"?"<<u<<" "<<nxt<<" "<<opt<<" "<<v<<" "<<T1.query(T1.rt[u-1],T1.rt[nxt-1],0,N-5,opt-v+1,N-5)<<" "<<
				// T2.query(T2.rt[u-1],T2.rt[nxt-1],0,N-5,0,opt-v)<<endl;
				// T2.query(T2.rt[u-1],T2.rt[nxt-1],0,N-5,0,opt-v)<<endl;
			}
			auto it1=it;
			it++;
			S.erase(it1);
		}
		S.insert(mp(l,opt));
		writeln(ans);
	}
		
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/