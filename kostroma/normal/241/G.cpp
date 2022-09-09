#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;
typedef long long li;
typedef pair<int, int> pi;
#define FILENAME "arrays"

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
void solve();
int main(){


#ifdef room210
	freopen("in.txt","r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
#else
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}

//#define int li

int n;
double x[1000];
double p[1000];
double r[1000];

void solve(){
	//freopen("in.txt", "w", stdout);
	
	int N = 400;

	cout<<N<<endl;

	r[0] = 100000.0;

	cout<<0<<' '<<100000<<endl;

	int cnt = N - 2;

	int coor = r[0] + cnt;

	for (int i = 0; i < N - 2; ++i){
		cout<<coor<<' '<<cnt<<endl;
		coor += 2 * cnt - 1;
		--cnt;
	}

	cout<<500000<<' '<<1000000<<endl;
	return;

	/*double last = 1000000.0;
	x[0] = 0;
	r[0] = 1000000.0;
	for (int i = 1; i < N - 1; ++i){
		x[i] = x[i - 1] + 2 * (int)r[i - 1] + 7;
		r[i] = ( r[i - 1] * (last - x[i]) * (last - x[i]) / (last - x[i - 1]) / (last - x[i - 1])  + (x[i] - x[i - 1]) * (x[i] - x[i - 1]) / 4.0 / r[i - 1]) / 2.0;
		r[i] = (double)((int)r[i]);
	}

	x[N - 1] = last;
	r[N - 1] = 1000000.0;

	cout<<N<<endl;
	for (int i = 0; i < N; ++i)
		printf ("%.10lf %.10lf\n", x[i], r[i]);
	return;
	*/
	/*cin>>n;
	for (int i = 0; i < n; ++i)
		cin>>x[i]>>p[i];
	vector <int> s;
	double ans1 = 0;
	int whobest = -1;
	for (int i = 0; i < n; ++i){
		//cout<<s.size()<<endl;
		r[i] = p[i];
		for (int j = 0; j < min((int)s.size(), 300); ++j){
			int ind = (int)s.size() - 1 - j;
			int t = s[ind];
			if (r[i] > (x[t] - x[i]) * (x[t] - x[i]) / 4.0 / r[t]){
				r[i] = min(r[i], (x[t] - x[i]) * (x[t] - x[i]) / 4.0 / r[t]);
				if (i == n - 1)
					whobest = t;
			}
		}
		ans1 += r[i];
		while (!s.empty() && r[s.back()] <= r[i]){
			s.pop_back();
		}
		//cout<<r[i]<<endl;
		s.push_back(i);
	}

	s.clear();
	double ans2 = 0;
	int whobest1 = -1;
	for (int i = 0; i < n; ++i){
		r[i] = p[i];
		for (int j = 0; j < (int)s.size(); ++j){
			int ind = (int)s.size() - 1 - j;
			int t = s[ind];
			if (r[i] > (x[t] - x[i]) * (x[t] - x[i]) / 4.0 / r[t]){
				r[i] = min(r[i], (x[t] - x[i]) * (x[t] - x[i]) / 4.0 / r[t]);
				if (i == n - 1)
					whobest1 = t;
			}
		}
		ans2 += r[i];
		while (!s.empty() && r[s.back()] <= r[i])
			s.pop_back();
		s.push_back(i);
	}

	cout<<whobest<<' '<<whobest1<<endl;

	printf ("%.10lf\n", r[n - 1]);
	printf ("%.10lf %.10lf\n", ans1, ans2);
	*/
}