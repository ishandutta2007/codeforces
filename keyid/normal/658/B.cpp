#include <bits/stdc++.h>
using namespace std;

const int MAXN=150005;

typedef pair <int,int> pii;

#define mp make_pair
#define fi first
#define sc second

priority_queue <pii,vector<pii>,greater<pii> > scr;
int a[MAXN];
bool inq[MAXN];

int main()
{
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int tpe,id;q--;)
	{
		scanf("%d%d",&tpe,&id);
		if (tpe==2) puts(inq[id]?"YES":"NO");
		else if (scr.size()<k)
		{
			scr.push(mp(a[id],id));
			inq[id]=true;
		}
		else if (scr.top().fi<a[id])
		{
			inq[scr.top().sc]=false;
			scr.pop();
			scr.push(mp(a[id],id));
			inq[id]=true;
		}
	}
	return 0;
}