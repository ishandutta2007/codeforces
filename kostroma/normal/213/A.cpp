#pragma comment(linker, "/STACK:106777216")

#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;
typedef long double ld;
#define NAME "change me"

//int timer=0;

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	//cout<<NAME<<endl;
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
	int t = 1;
#ifdef _DEBUG
	//cin>>t;
#endif
	//cin>>t;
	while (t--)
		solve();
	return 0;
}

//#define int li
const int MAXN=500;
int n;
vector <int> g[MAXN];

int c[MAXN];
int deg[MAXN];

int deg1[MAXN];

void solve(){
	cin>>n;
	for (int i=0; i<n; ++i)
		cin>>c[i], --c[i];
	for (int i=0; i<n; ++i){
		int q; cin>>q;
		while (q--){
			int w; cin>>w;
			--w;
			g[w].push_back(i);
			++deg[i];
		}
		deg1[i]=deg[i];
	}
	int ans=1<<30;
	for (int start=0; start<3; ++start){
		int done=0;
		int curans=0;
		set <pair<int,int> > levs[3];
		for (int i=0; i<n; ++i)
			levs[c[i]].insert( mp (deg[i], i) ), deg1[i]=deg[i];
		int now=start;
		while (done < n){
			//cout<<now<<endl;
			while (!levs[now].empty()){
				pair <int, int> cur=*(levs[now].begin());
				if (cur.first > 0)
					break;
				levs[now].erase(levs[now].begin());
				++curans;
				++done;
				if (done==n)
					break;
				for (int j=0; j<g[cur.second].size(); ++j){
					int nex=g[cur.second][j];
					levs[c[nex]].erase(mp(deg1[nex], nex));
					deg1[nex]--;
					levs[c[nex]].insert(mp(deg1[nex], nex));
				}
			}
			now=(now+1)%3;
			if (done < n)
				++curans;
			if (curans > 100000)
				break;
		}
		ans=min(ans, curans);
	}

	cout<<ans;
}