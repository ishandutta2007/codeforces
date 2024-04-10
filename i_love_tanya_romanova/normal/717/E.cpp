#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define debug_flag 1
#else
	#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p) 
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if (isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}

typedef long long int int64;

const int N = 205000;

int n;
int par[N];
vector<int> g[N];

vector<int> ans;
int used[N];

void dfs(int v)
{
	used[v]=1;
	ans.push_back(v);
	par[v]^=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
		ans.push_back(v);
		par[v]^=1;
		if (par[to]==0)
		{
			ans.push_back(to);
			ans.push_back(v);
			par[to]^=1;
			par[v]^=1;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d",&n);
	int flag=0;

	for (int i=1;i<=n;i++)
	{
		int val;
		scanf("%d",&val);
		if (val==1)
			par[i]=1;
		else
			par[i]=0;
		if (par[i]==0)
			flag=1;

	}

	if (flag==0)
	{
		cout<<1<<endl;
		return 0;
	}
	
	par[1]^=1;

	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	/*for (int i=1;i<=n;i++)
	{
		dbg(i,par[i]);
	}*/

	if (par[1]==0)
	{
		ans.push_back(g[1][0]);
		ans.push_back(1);
		ans.push_back(g[1][0]);
	}

	for (int i=0;i<ans.size();i++)
	{
		if (i)
			printf(" ");
		printf("%d",ans[i]);
	}

	puts("");

	return 0;
}