#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mid (l+r>>1)
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=16+2,M=8+2,T=1e6;
const ll U=1e18;
int p[N];
struct SET
{
int p[M],n;
void push(int x){p[++n]=x;}

ll q[T];int id[T];int tail;
void bfs()
{
	q[tail=1]=1;id[1]=1;
	rep(head,1,tail)
	{
		ll x=q[head];
		ll now=U/x;
		rep(j,id[head],n)
		{
			if(p[j]>now)break;
			++tail;
			q[tail]=x*p[j];
			id[tail]=j;
		}
	}
	sort(q+1,q+tail+1);
}
}S1,S2;

ll xiao(const ll &a)
{
	int t2=S2.tail;ll ans=0;
	rep(h1,1,S1.tail)
	{
		ll now=a/S1.q[h1];
		while(S2.q[t2]>now) 
		{
			--t2;
			if(!t2)goto End;
		}
		ans+=t2;
	}
	End: ;
	return ans;
}
ll erfen()
{
	ll k;
	cin>>k;
	ll l=0,r=U;
	while(l+1!=r)
	if(xiao(mid)<k)l=mid;
	else r=mid;
	return r;
}

int main()
{
//	freopen("1.in","r",stdin);
	int n;
	cin>>n;
	rep(i,1,n)cin>>p[i];

	int m=(n+1)/2;
	rep(i,1,m)
	if(i%2)S1.push(p[i]);
	else S2.push(p[i]);

	int *p2=p+m;
	rep(i,1,n-m)
	if(i%2)S2.push(p2[i]);
	else S1.push(p2[i]);
	
//	cout<<m<<" "<<S1.n<<" "<<S2.n<<endl;
	
	S1.bfs();S2.bfs();
	
//	cout<<S1.tail<<" "<<S2.tail<<endl;
	
	cout<<erfen();
}