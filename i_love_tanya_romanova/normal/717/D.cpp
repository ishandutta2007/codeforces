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

int n,x;
double prob[2000];
vector<vector<double> >v;

vector<vector<double> >mult(vector<vector<double> > a,vector<vector<double> > b)
{
	vector<vector<double> >res=a;
	for (int i=0;i<a.size();i++)
	{
		for (int j=0;j<a.size();j++)
		{
			res[i][j]=0;
		}
	}
	for (int k=0;k<a.size();k++)
	{
		for (int i=0;i<a.size();i++)
		{
			for (int j=0;j<a.size();j++)
			{
				if (a[i][k]>1e-50)
					res[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return res;
}

vector<vector<double> > pw(vector<vector<double> > v,int n)
{
	if (n==1)
	return v;
	if (n%2)
		return mult(v,pw(v,n-1));
	return pw(mult(v,v),n/2);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	cin>>n>>x;
	for (int i=0;i<=x;i++)
	{
		cin>>prob[i];
		//prob[i]=1.0/(x+1);
	}

	v.resize(128);
	for (int i=0;i<128;i++)
	{
		v[i].resize(128);
		for (int j=0;j<128;j++)
		{
			v[i][j]=0;
		}
	}

	for (int i=0;i<128;i++)
	{
		for (int j=0;j<=x;j++)
		{
			v[i][i^j]=prob[j];
		}
	}

	v=pw(v,n);

	cout.precision(10);

	cout<<fixed<<1.0-v[0][0]<<endl;

	return 0;
}