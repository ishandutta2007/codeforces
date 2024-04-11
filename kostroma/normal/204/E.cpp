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
#define NAME "coins"

int timer=0;

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#else
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);
	int t = 1;
	while (t--)
		solve();
	return 0;
}

const int shift=1<<17;
//#define int li

int k, n;
string a[100500];
vector<int> hashes[100500];
int pr=97;
int step[100500];
vector<pair <int, int> > p;
vector<int> LCP;
int Hash (int num, int l, int r){
	return hashes[num][r]-((l>0)?hashes[num][l-1]:0)*step[r-l+1];
}
int lcp (pair<int,int> q, pair <int,int> w){
	if (a[q.first][q.second]!=a[w.first][w.second])
		return 0;
	int l=0, r=min( a[q.first].size()-q.second, a[w.first].size()-w.second );
	while (l+1<r){
		int m=l+r; m>>=1;
		if ( Hash(q.first, q.second, q.second+m)==Hash(w.first, w.second, w.second+m) )
			l=m;
		else
			r=m;
	}
	return l+1;
}
bool cmp (pair<int,int> q, pair<int,int> w){
	int cur=lcp(q,w);
	if (cur+w.second==a[w.first].size())
		return false;
	if (cur+q.second==a[q.first].size())
		return true;
	return a[q.first][q.second+cur]<a[w.first][w.second+cur];
}

int tree[2*shift+6];
int rmq (int l, int r){
	if (l>r)
		return 1<<30;
	if (l%2)
		return min(tree[l], rmq(l+1,r));
	if (r%2==0)
		return min(tree[r], rmq(l,r-1));
	return rmq(l/2,r/2);
}

int many[100500];
int what[100500];

int lcp1 (int num, int ll, int rr, pair <int,int> q){
	if (a[num][ll]!=a[q.first][q.second])
		return 0;
	int l=0, r=min( (int)a[q.first].size()-q.second, rr-ll+1 );
	while (l+1<r){
		int m=l+r; m>>=1;
		if ( Hash(q.first, q.second, q.second+m)==Hash(num, ll, ll+m) )
			l=m;
		else
			r=m;
	}
	/*if (num==0 && ll==0 && rr==1)
		cout<<"look  "<<q.first<<' '<<q.second<<' '<<a[q.first][q.second]<<" lcp = "<<l+1<<endl;*/
	return l+1;
}

bool cmp1 (int num, int ll, int rr, pair <int,int> q){
	int cur=lcp1(num,ll,rr,q);
	//cout<<"cur = "<<cur<<endl;
	if (cur+ll==rr+1)
		return true;
	if (cur+q.second==a[q.first].size())
		return false;
	return a[q.first][q.second+cur]>a[num][ll+cur];
}

bool good (int num, int ll, int rr){
	if (ll>rr)
		return true;
	int l=0, r=p.size();
	while (l+1<r){
		int m=l+r; m>>=1;
		if (!cmp1(num, ll, rr, p[m]))
			l=m;
		else
			r=m;
	}
	if (r == p.size())
		return false;
	if (cmp1(num, ll, rr, p[0]))
		r=0;
	if (lcp1(num, ll, rr, p[r]) != rr - ll + 1)
		return false;
	//cout<<"pos = "<<r<<' '<<what[r]<<"  "<<" num = "<<num<<"  borders: "<<ll<<' '<<rr<<endl;
	return what[r] >= rr - ll + 1;
}

void solve(){
	step[0]=1;
	for (int i=1; i<100500; ++i)
		step[i]=step[i-1]*pr;
	cin>>n>>k;
	for (int i=0; i<n; ++i){
		cin>>a[i];
		hashes[i].push_back(a[i][0]);
		for (int j=1; j<a[i].size(); ++j)
			hashes[i].push_back(hashes[i][j-1]*pr+a[i][j]);
		for (int j=0; j<a[i].size(); ++j)
			p.push_back(mp(i,j));
	}
	sort (all(p), &cmp);

	/*if (k==1){
		for (int i=0; i<n; ++i){
			li len=a[i].size();
			cout<<len*(len+1)/2<<' ';
		}
		return;
	}*/

	/*for (int i=0; i<p.size(); ++i){
		for (int j=p[i].second; j<a[p[i].first].size(); ++j)
			cout<<a[p[i].first][j];
		cout<<endl;
	}
	cout<<endl<<"all\n\n";*/

	LCP.assign(p.size()-1, 0);
	for (int i=0; i+1<p.size(); ++i)
		LCP[i]=lcp(p[i],p[i+1]), tree[i+shift]=LCP[i];

	/*for (int i=0; i+1<p.size(); ++i){
		cout<<LCP[i]<<' ';
	}
	cout<<endl;*/

	for (int i=shift-1; i>0; --i)
		tree[i]=min(tree[i*2], tree[i*2+1]);
	int cnt=0;
	int w=0;
	for (int i=0; i<p.size(); ++i){
		while (cnt < k && w < (int)p.size()){
			many[p[w].first]++;
			if (many[p[w].first]==1)
				++cnt;
			++w;
		}
		assert(w>i);
		//cout<<"see "<<i<<' '<<w<<endl;

		if (cnt>=k){
			if (w-2>=i)
				what[i]=rmq(i+shift, w+shift-2);
			else
				what[i]=a[p[i].first].size()-p[i].second;
		}
		else
			what[i]=-1;
		many[p[i].first]--;
		if (!many[p[i].first])
			--cnt;
		//cout<<what[i]<<' '<<endl;
	}
	//cout<<endl;
	what[p.size()]=-1;

	for (int i=0; i<n; ++i){
		int w=0;
		li ans=0;
		//cout<<i<<endl;
		for (int j=0; j<a[i].size(); ++j){
			while (w<(int)a[i].size() && good(i, j, w) )
				++w;
			--w;
			if (w>=j)
				ans+=(w-j+1);
			//cout<<j<<' '<<w<<endl;
		}
		//cout<<endl<<i<<" ans = "<<ans<<endl;
		cout<<ans<<' ';
	}
}