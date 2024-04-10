#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int a[100100];
const int B=300;
struct query
{
	int l,r,ind;
	query(int _ind)
	{
		ind=_ind;
		cin>>l>>r;
	}
	friend bool operator <(const query &a,const query &b)
	{
		if(a.l/B==b.l/B)
			return a.r<b.r;
		return a.l/B<b.l/B;
	}
};
vector<query> qu;
int ans[100100];
deque<int> dq[100100];
deque<int> dq2[100100];
int d[100100];
int violate[100100];
int tot;
int cnt;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
		qu.pb(query(i));
	srt(qu);
	int l=1,r=0;
	for(int i=0;i<q;i++)
	{
		int L=qu[i].l,R=qu[i].r;
		while(r<R)
		{
			r++;
			int x=a[r];
			if(!sz(dq[x]))
				cnt++;
			if(sz(dq[x])>=1)
			{
				if(sz(dq2[x]))
				{
					if(r-dq[x].back()!=dq2[x].back())
					{
						violate[x]++;
						if(violate[x]==1)
							tot++;
					}
				}
				dq2[x].push_back(r-dq[x].back());
				dq[x].push_back(r);
			}
			else
			{
				dq[x].push_back(r);
			}
		}
		while(r>R)
		{
			int x=a[r];
			dq[x].pop_back();
			if(sz(dq2[x]))
			{
				int y=dq2[x].back();
				dq2[x].pop_back();
				if(sz(dq2[x]))
				{
					if(y!=dq2[x].back())
					{
						violate[x]--;
						if(!violate[x])
							tot--;
					}
				}
			}
			if(!sz(dq[x]))
				cnt--;
			r--;
		}
		while(l<L)
		{
			int x=a[l];
			dq[x].pop_front();
			if(sz(dq2[x]))
			{
				int y=dq2[x].front();
				dq2[x].pop_front();
				if(sz(dq2[x]))
				{
					if(y!=dq2[x].front())
					{
						violate[x]--;
						if(!violate[x])
							tot--;
					}
				}
			}
			if(!sz(dq[x]))
				cnt--;
			l++;
		}
		while(l>L)
		{
			l--;
			int x=a[l];
			if(!sz(dq[x]))
				cnt++;
			if(sz(dq[x])>=1)
			{
				if(sz(dq2[x]))
				{
					if(dq[x].front()-l!=dq2[x].front())
					{
						violate[x]++;
						if(violate[x]==1)
							tot++;
					}
				}
				dq2[x].push_front(dq[x].front()-l);
				dq[x].push_front(l);
			}
			else
			{
				dq[x].push_back(l);
			}
		}
		ans[qu[i].ind]=cnt-(bool)(cnt!=tot)+1;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}