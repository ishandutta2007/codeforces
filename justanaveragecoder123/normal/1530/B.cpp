#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

using ll = long long;
using ull = unsigned long long ;
using ld = long double ;
using str = string;
using ordered_set=tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)
int d1[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1}, {1,-1},{1,0},{1,1}};

int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n,m;
		cin>>n>>m;
		vector<string> orig(n, string(m,'0'));
		auto ans=orig;
		int anscnt=0;
		
		auto cnter=[&](vector<string>& s, int x, int y) {
			int res=0;
			for(int i=0;i<8;++i) {
				int nx=x+d1[i][0], ny=y+d1[i][1];
				if(nx>=0 && ny>=0 && nx<n && ny<m) res+=s[nx][ny]=='1';
			}
			
			return res;
		};
		
		for(pair<int,int> a:vector<pair<int,int>>({{0,0},{0,1},{1,0}})) {
			for(pair<int,int> b:vector<pair<int,int>>({{0,m-1},{0,m-2},{1,m-1}})) {
				for(pair<int,int> c:vector<pair<int,int>>({{n-1,m-1},{n-1,m-2},{n-2,m-1}})) {
					for(pair<int,int> d:vector<pair<int,int>>({{n-1,0},{n-1,1},{n-2,0}})) {
						auto s=orig;
						s[a.xx][a.yy]='1';
						s[b.xx][b.yy]='1';
						s[c.xx][c.yy]='1';
						s[d.xx][d.yy]='1';
		
						for(int i=0;i<n;++i) {
							for(int j=0;j<m;++j) {
								if(i==0 || i==n-1 || j==0 || j==m-1) {
									if(cnter(s, i, j)==0 && s[i][j]=='0') s[i][j]='1';
								} 
							}
						}

						bool ok=true;
						int cnt=0;
						for(int i=0;i<n;++i) {
							for(int j=0;j<m;++j) {
								if(s[i][j]=='1') {
									cnt++;
									ok&=cnter(s,i,j)==0;
								}
							}
						}
						
						if(ok) {
							if(anscnt<cnt) {
								anscnt=cnt;
								ans=s;
							}
						}
					}
				}
			}			
		}
		for(auto i:ans) cout<<i<<"\n";
	}
	return 0;
}