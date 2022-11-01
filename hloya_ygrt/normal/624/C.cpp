
#include <bits/stdc++.h>
const int maxn=50500;
const int inf=2e9;
const int eps=1e-9;
const int base=1e9+7;

#define mp make_pair
#define f first
#define sec second
#define pb push_back
#define ll long long
#define ld long double
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;
    int parent[maxn],_rank[maxn],step[maxn];
    void make_set (int v) {
	parent[v] = v;
	_rank[v] = 0;
}

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (_rank[a] < _rank[b])
			swap (a, b);
		parent[b] = a;
		if (_rank[a] == _rank[b])
			++_rank[a];
	}
}
vector<pair<int,int> > edges,noedges;
set<pair<int,int> > bedges;
bool ac[maxn];

void bad1()
{
            cout<<"No";
        exit(0);
}
int main()
{
    int n,m;

           // freopen("input.txt","r",stdin);
//             freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&m);
    char ans[maxn];
    for (int i=0;i<n;i++)
        ans[i] = 'd';
    for (int i=0;i<m;i++){
        int foo, bar;
        scanf("%d %d",&foo,&bar);
        foo--;
        bar--;
        edges.push_back(mp(foo,bar));
        bedges.insert(mp(foo,bar));
        bedges.insert(mp(bar,foo));
        step[foo]++;
        step[bar]++;
    }

    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (bedges.count(mp(i,j))==0)
                noedges.pb(mp(i,j));

    for (int i=0;i<n;i++)
        if (step[i]==n-1)
            {
                ac[i] = 0;
                ans[i] = 'b';
            }
        else
            ac[i] = 1;

    for (int i=0;i<n;i++)
            make_set(i);

    for (int i=0;i<m;i++){
        if (ac[edges[i].f]==1&&ac[edges[i].sec]==1)
            union_sets(edges[i].f,edges[i].sec);
    }
    bool bad = 0;
    for (int i =0;i<noedges.size();i++){
        int foo = noedges[i].f,bar=  noedges[i].sec;
        if (find_set(foo) == find_set(bar))
        {
            bad = 1;
            break;
        }
    }

    if (bad)
    {
        cout<<"No";
        exit(0);
    }
    map<int,char> sot;
    int cnt = 0;
    for (int i=0;i<n;i++){
        if (ans[i] == 'b')
            continue;
        int in = find_set(i);
        if (sot.count(in)!=0)
            continue;
        if (sot.empty())
            sot[in] = 'a';
        else{
            if (sot.size()==1)
                sot[in] = 'c';
            else
                bad1();
        }
    }
    for (int i=0;i<n;i++){
        if (ans[i] == 'b')
            continue;
        ans[i] = sot[find_set(i)];
    }
    cout<<"Yes"<<endl;
    for (int i=0;i<n;i++)
        printf("%c",ans[i]);
    return 0;
}