/*
ID: noszaly1
TASK: {TASK}
LANG: C++11               
*/

//Noszly ron 11o Debreceni Fazekas Mihly Gimnzium

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
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);

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


const int MAXN=150021;
vector<int> curr[MAXN];
int par[MAXN], sz[MAXN];

void init() {
	memset(par, -1, sizeof par);
	for(int i=0;i<MAXN;++i) {
		sz[i]=1;
		curr[i]={i};
	}
}

int get(int x) {
	if(par[x]==-1) return x;
	return par[x]=get(par[x]);
}

void merge(int x, int y) {
	int px=get(x), py=get(y);
	
	if(px==py) return ;
	
	if(sz[px]>sz[py]) {
		swap(px, py);
		swap(x, y); //:) lyft
	}
	
	par[px]=py;
	sz[py]+=sz[px];
	for(auto i:curr[px]) curr[py].push_back(i);
}





int main() {
	IO;
	init();
	int n;
	cin>>n;
	for(int i=1;i<n;++i) {
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}
	
	int x=get(1);
	for(auto i:curr[x]) {
		cout<<i<<" ";
	}cout<<"\n";
	
	return 0;
}