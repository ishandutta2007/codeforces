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

string a;

bool solve(deque<int> pos[26], string b) {
	int akt=-1;
	bool ok=true;
	for(int i=0;i<sz(b);++i) {
		//~ LOG(i);
		//~ LOG(akt);
		if(pos[b[i]-'a'].empty()) {
			ok=false;
			break ;
		}
	
		int nxt=pos[b[i]-'a'].front();
		pos[b[i]-'a'].pop_front();
		
		//~ LOG(akt);
		//~ LOG(nxt);
		if(akt>nxt) {
			i--;
			continue ;
		}
		
		if(akt==-1) {
			//~ LOG(nxt);
			if(nxt%2==1) {
				i--;
			}else {
				akt=nxt;
			}
		}
		else {
			if((nxt-akt-1)%2==1) {
				i--;
				continue;
			}else {
				akt=nxt;
			}
		}
	}
	
	return ok;
}

int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		string b;
		cin>>a>>b;
		
		reverse(all(a));
		reverse(all(b));
		
		deque<int> pos[26];
		for(int i=0;i<sz(a);++i) {
			pos[a[i]-'a'].push_back(i);
		}
		
		bool ok=solve(pos, b);
		
		//~ for(int i=0;i<26;++i) pos[i].clear();
		//~ for(int i=0;i<sz(a);++i) {
			//~ pos[a[i]-'a'].push_back(i);
		//~ }
		
		//~ int ch=b[0]-'a';
		//~ if(!pos[ch].empty()) {
			//~ int parity=pos[ch].front()%2;
			//~ while(!pos[ch].empty() && pos[ch].front()%2==parity) pos[ch].pop_front();
			//~ ok|=solve(pos, b);
		//~ }
		
		cout<<(ok?"YES":"NO")<<"\n";
	}
	return 0;
}