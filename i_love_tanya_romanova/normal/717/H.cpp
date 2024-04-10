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

const int N = 1001001;

int n,e;
int a[N],b[N];
vector<int> g[N];
int T;
vector<int> cand[N];
vector<int> order;
int ans_team[N],ans_conf[N];
int team[N],conf[N];
vector<int> contestant_list[N];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d",&n);
	scanf("%d",&e);
	for (int i=1;i<=e;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		//a[i]=rand()%n+1;
		//b[i]=rand()%n+1;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	for (int i=1;i<=n;i++)
	{
		int cnt;
		scanf("%d",&cnt);
///		cnt=16;
		for (int j=0;j<cnt;j++)
		{
			int val;
			scanf("%d",&val);
	//		val=j+1;
			T=max(T,val);
			cand[i].push_back(val);
		}
	}

	while (true)
	{

		for (int i=1;i<=T;i++)
		{
			contestant_list[i].clear();

		}
		for (int i=1;i<=n;i++)
		{
			team[i]=rand()%(cand[i].size());
			team[i]=cand[i][team[i]];
			contestant_list[team[i]].push_back(i);
		}

		order.clear();
		for (int i=1;i<=T;i++)
		{
			order.push_back(i);
		}
		random_shuffle(order.begin(),order.end());
		for (int i=1;i<=T;i++)
		{
			conf[i]=0;
		}


		for (int i=0;i<order.size();i++)
		{
			int id=order[i];
			int cnt1=0;
			int cnt2=0;

			for (int j=0;j<contestant_list[id].size();j++)
			{
				//dbg(i,j);

				int contestant_id=contestant_list[id][j];
				for (int q=0;q<g[contestant_id].size();q++)
				{
					int other=g[contestant_id][q];
					int other_team=team[other];
					if (conf[other_team]==0)
						continue;
					if (conf[other_team]==1)
						cnt1++;
					else
						cnt2++;
				}
			}
			if (cnt1>cnt2)
			{
				conf[id]=2;
			}
			else if (cnt1<cnt2)
			{
				conf[id]=1;
			}
			else
			{
				conf[id]=rand()%2+1;
			}
		}

		int good_edges=0;

		for (int i=1;i<=e;i++)
		{
			int g1=conf[team[a[i]]];
			int g2=conf[team[b[i]]];
			if (g1!=g2)
				good_edges++;
		}
		// dbg(good_edges,e);
		if (good_edges*2<e)
			continue;
		/*for (int i=1;i<=e;i++)
		{
			int g1=conf[team[a[i]]];
			int g2=conf[team[b[i]]];
			dbg(g1,g2,a[i],b[i]);
		}*/
		for (int i=1;i<=n;i++)
		{
			ans_team[i]=team[i];
		}
		for (int i=1;i<=T;i++)
		{
			ans_conf[i]=conf[i];
		}
		break;
	}

	for (int i=1;i<=n;i++)
	{
		if (i>1)
			printf(" ");
		printf("%d",ans_team[i]);
	}
	puts("");

	for (int i=1;i<=T;i++)
	{
		if (i>1)
			printf(" ");
		printf("%d",ans_conf[i]);
	}
	puts("");

	return 0;
}