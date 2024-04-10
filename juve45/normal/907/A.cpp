#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, tata, mama, son, masha;
string s;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> tata >> mama >> son >> masha;

	//masha > small, son > small, small <= 2 * son
	int small = min(2 * son, 2 * masha);
	int med = 2 * mama;
	int large = 2 * tata;


	if(son > small || masha > small) {
		cout << -1;
	}
	else if(small > son * 2 || small > masha * 2) {
		cout << -1;
	}
	else if(masha * 2 >= med || masha * 2 >= large)
	{
		cout << -1;
	} 
	else cout << large << '\n' << med << '\n' << small << '\n';
}