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
class SuffixAutomaton
{
	private:
	public:
		struct state
		{
			vector<state*> pt;
			state *par;
			map<int,state*> trans;
			int val;
			int cnt;
			int match;
			state(int _val) : par(0),val(_val),cnt(0),match(-1)
			{
				trans.clear();
				pt.clear();
			}
		};
		state *root=new state(0),*last=root;
		vector<state*> nodes;
		inline void extend(int w)
		{
			state *p=last;
			state *np=new state(p->val+1);
			nodes.pb(np);
			np->cnt=1;
			while(p&&!p->trans[w])
			{
				p->trans[w]=np;
				p=p->par;
			}
			if(!p)
				np->par=root;
			else
			{
				state *q=p->trans[w];
				if(p->val+1==q->val)
					np->par=q;
				else
				{
					state *nq=new state(p->val+1);
					nodes.pb(nq);
					nq->trans=q->trans;
					nq->par=q->par;
					q->par=nq;
					np->par=nq;
					while(p&&p->trans[w]==q)
					{
						p->trans[w]=nq;
						p=p->par;
					}
				}
			}
			last=np;
		}
		void build()
		{
			for(auto x:nodes) if(x->par)
				x->par->pt.pb(x);
		}
		void dfs(state *st)
		{
			for(auto x:st->pt) if(x)
			{
				dfs(x);
				st->cnt+=x->cnt;
			}
		}
		void dfs()
		{
			build();
			dfs(root);
		}
};
SuffixAutomaton SAM;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	for(auto c:s)
		SAM.extend(c-'a');
	SAM.dfs();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string x;
		cin>>x;
		int m=sz(x);
		int len=sz(x)*2-1;
		x+=x;
		SuffixAutomaton::state *st=SAM.root;
		int l=0;
		ll ans=0;
		for(int j=0;j<len;j++)
		{
			int tr=x[j]-'a';
			if(st->trans[tr])
			{
				l++;
				st=st->trans[tr];
			}
			else
			{
				while(st&&!st->trans[tr]) st=st->par;
				if(st)
				{
					l=st->val+1;
					st=st->trans[tr];
				}
				else
				{
					l=0;
					st=SAM.root;
				}
			}
			if(l>=m)
			{
				while(st->par&&st->par->val>=m) st=st->par;
				if(st->match<i)
				{
					st->match=i;
					ans+=st->cnt;
				}
				l=m;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}