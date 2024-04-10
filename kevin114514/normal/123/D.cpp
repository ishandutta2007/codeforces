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
			state(int _val) : par(0),val(_val),cnt(0)
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
	string s;
	cin>>s;
	for(auto c:s)
		SAM.extend(c-'a');
	SAM.dfs();
	ll ans=0;
	for(auto x:SAM.nodes)
		ans+=1ll*(x->cnt)*(x->cnt+1)/2*(x->par->val-x->val);
	cout<<-ans<<endl;
	return 0;
}