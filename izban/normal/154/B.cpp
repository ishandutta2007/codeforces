#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=100100;

int n,m,ans;
int lp[maxn];
bool f[maxn];
int p[maxn];
string s;
vector <int> v;

void eratosfen(int N) {
	vector<int> pr;
 
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	getline(cin,s);
	sscanf(s.c_str(),"%d%d",&n,&m);
	eratosfen(n);
	for (int i=0; i<m; i++) {
		getline(cin,s);
		char c; int x;
		sscanf(s.c_str(),"%c %d",&c,&x);
		if (c=='+') {
			int x0=x;
			if (f[x]) {
				cout << "Already on" << endl;
				continue;
			}
			v.clear();
			while (x>1) {
				v.push_back(lp[x]);
				x/=lp[x];
			}
			bool f1=false;
			for (int j=0; j<v.size(); j++) {
				if (p[v[j]]) {
					f1=true;
					ans=p[v[j]];
				}
			}
			if (f1) {
				cout << "Conflict with " << ans << endl;
			} else {
				for (int j=0; j<v.size(); j++) p[v[j]]=x0;
				f[x0]=true;
				cout << "Success" << endl;
			}
		} else {
			if (!f[x]) {
				cout << "Already off" << endl;
			} else {
				f[x]=false;
				while (x>1) {
					p[lp[x]]=0;
					x/=lp[x];
				}
				cout << "Success" << endl;
			}
		}
	}

	return 0;
}