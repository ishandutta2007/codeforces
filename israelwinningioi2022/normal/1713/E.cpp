#include<iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
const int mod = 1e9 + 7;

struct dsu{
	vi p, sz, d;
	dsu(int n): p(n,-1), sz(n,1), d(n, 0){}
	int find(int c, int& dd){
		if (p[c]==-1){
			dd=0;
			return c;
		}
		p[c] = find(p[c], dd);
		d[c]=(dd^=d[c]);
		return p[c];
	}
	bool uni(int a, int b, int w){
		int da, db;
		a = find(a, da), b=find(b,db);
		w^=da, w^=db;
		if (a==b) return !w;
		if (sz[a]>sz[b]) swap(a,b);
		p[a]=b;
		sz[b]+=sz[a];
		d[a]=w;
		return 1;
	}
};
void solve(int tt){
	int n; cin>>n;
	dsu d(n);
	vvi mat(n, vi(n));
	loop(i,0,n)loop(j,0,n) cin>>mat[i][j];
	loop(i,0,n)loop(j,i+1,n){
		if (mat[i][j]==mat[j][i]) continue;
		int w=(mat[i][j]>mat[j][i]);
		if (w==d.uni(i, j, w)) swap(mat[i][j], mat[j][i]);
	}
	loop(i,0,n){loop(j,0,n) cout<<mat[i][j]<<" "; cout<<endl;}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	loop(i,0,t) solve(i+1);
	return 0;
}