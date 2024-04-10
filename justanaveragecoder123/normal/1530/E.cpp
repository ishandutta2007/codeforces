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

vector<int> zalgo(string& str) {
	vector<int> z(sz(str));
	int L=0, R=0;
	for(int i=1;i<sz(str);++i) {
		if(i>R) {
			L=i;R=i;
			while(R<sz(str) && str[R]==str[R-L]) R++;
			z[i]=R-L;
			R--;
		}else {
			if(z[i-L]+i<R) {
				z[i]=z[i-L];
			}else {
				L=i;
				while(R<sz(str) && str[R]==str[R-L]) R++;
				z[i]=R-L;
				R--;
			}
		}
	}
	
	return z;
}

pair<int,string> cost(string &s) {
	auto v=zalgo(s);
	return make_pair(*max_element(all(v)), s);
}

pair<int,string> solve(string s) {
	sort(all(s));
	pair<int, string> ans={1e9,""};
	do {
		ans=min(ans, cost(s));
	}while(next_permutation(s.begin(), s.end()));
	
	return ans;
}

int main() {
	IO;
	if(0) {
	string s;
	cin>>s;
	auto ans=solve(s);
	cout<<ans.xx<<" "<<ans.yy<<"\n";
	}
	
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		array<int,26> cnt;
		for(int& i:cnt) i=0;
		for(auto i:s) cnt[i-'a']++;
		
		int best=-1;
		for(int i=0;i<26;++i) {
			if(cnt[i]==1) {
				best=i;
				break ;
			}
		}
		
		if(best!=-1) {
			cnt[best]--;
			cout<<char(best+'a');
			for(int i=0;i<26;++i) {
				while(cnt[i]>0) {
					cout<<char(i+'a');
					cnt[i]--;
				}
			}
			cout<<"\n";
			continue ;
		}
		
		int mn=-1;
		for(int i=0;i<26;++i) if(cnt[i]>0) {mn=i; break;}
		
		auto orig=cnt;
		auto left=[&]() -> bool {
			for(int i=0;i<26;++i) if(i!=mn && cnt[i]) return true;
			return false;
		};
		
		pair<int,string> ans={1e9, ""};
		string A,B,C;
		
		//aa bababa...
		A.push_back(mn+'a');cnt[mn]--;
		A.push_back(mn+'a');cnt[mn]--;
		
		while(left()) {
			for(int j=0;j<26;++j) {
				if(mn!=j && cnt[j]) {
					A.push_back('a'+j);
					cnt[j]--;
					if(cnt[mn]) {
						A.push_back('a'+mn);
						cnt[mn]--;
					}
					break ;
				} 
			}
		}
		while(cnt[mn]) {
			A.push_back(mn+'a');cnt[mn]--;
		}
		if(sz(A)==sz(s)) ans=min(ans, cost(A));
		
		//ab aaaaaa c...
		cnt=orig;
		B.push_back(mn+'a');cnt[mn]--;
		int sc=0;
		for(int j=0;j<26;++j) {
			if(j!=mn && cnt[j]) {
				B.push_back(j+'a');cnt[j]--;
				sc=j;
				break ;
			}
		}
		while(cnt[mn]) {
			B.push_back(mn+'a');cnt[mn]--;
		}
		for(int j=0;j<26;++j) {
			if(j!=mn && j!=sc && cnt[j]) {
				B.push_back(j+'a');
				cnt[j]--;
				break ;
			}
		}
		
		while(left()) {
			for(int j=0;j<26;++j) {
				if(mn!=j && cnt[j]) {
					while(cnt[j]) {
						B.push_back('a'+j);
						cnt[j]--;
					}
					break ;
				} 
			}
		}
		if(sz(B)==sz(s)) ans=min(ans, cost(B));
		
		//abbbbb aaaa
		cnt=orig;
		C.push_back(mn+'a');cnt[mn]--;
		for(int j=0;j<26;++j) {
			if(j!=mn && cnt[j]) {
				while(cnt[j]>0) {
					C.push_back(j+'a');cnt[j]--;
				}
				break ;
			}
		}
		for(int j=0;j<26;++j) {
			if(cnt[j]) {
				while(cnt[j]>0) {
					C.push_back(j+'a');cnt[j]--;
				}
			}
		}
		if(sz(C)==sz(s)) ans=min(ans, cost(C));
		
		//~ auto ok=solve(s);
		//~ LOG(ok.yy);
		//~ LOG(B);
		//~ LOG(ans.yy);
		//~ assert(ok.yy==ans.yy);
		cout<<ans.yy<<"\n";
	}
	
	return 0;
}