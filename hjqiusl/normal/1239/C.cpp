//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
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
int n,m;
int a[N];
set<int>S,S1;
pa b[N];
int now;
int ans[N];
deque<int>Q;
int ckmn()
{
	if (S1.empty()) return inf;
	return (*S1.begin());
}
void LYC_music()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]={a[i],i};
	sort(b+1,b+n+1);
	int l=1;
	while (l<=n||!S.empty()||!Q.empty())
	{
		if (S.empty()&&Q.empty())
		{
			now=b[l].fi+m;
		} else now+=m;
		while (!S.empty()&&ckmn()>(*S.begin()))
		{
			Q.push_back((*S.begin()));
			S1.insert((*S.begin()));
			S.erase(S.begin());
		}
		while (l<=n&&b[l].fi<=now)
		{
//			S.insert(b[l].se);/
			if (ckmn()>b[l].se)
			{
				Q.push_back(b[l].se);
				S1.insert(b[l].se);
			} else S.insert(b[l].se);
			l++;
		}
		ans[Q.front()]=now;
		S1.erase(Q.front());
		Q.pop_front();
	}
	for (int i=1;i<=n;i++) writesp(ans[i]);
		
}
signed main()
{
	LYC_music();
}
/*
3 1000000000
3 1 2
*/