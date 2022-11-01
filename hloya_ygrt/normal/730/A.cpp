// In the name of God
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <assert.h>
#include <bitset>
#define sqr(a) (a)*(a)
#define all(a) (a).begin(), (a).end()
using namespace std;

template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}

string next_token() {
    char ch;
    string ans = "";
    do { ch = getchar(); } while(ch <= ' ');
    while(ch > ' ') {
        ans += ch;
        ch = getchar();
    }
    return ans;
}

const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int MAXN = (int)1e2 + 10;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-8;

long long bin_pow(long long a, long long b) {
	if(!b) return 1;
	long long ans = bin_pow(a, b / 2);
	ans = ans * ans % MOD;
	if(b % 2) ans = ans * a % MOD;
	return ans;
}   

int n;

void vost(vector<vector<int> > a) {
	cout << a.size() << "\n";
	for(int i = 0; i < a.size(); i++) {
		vector<int> ans(n, 0);

		for(int j = 0; j < a[i].size(); j++)
			ans[a[i][j]] = 1;

		for(int j = 0; j < n; j++) cout << ans[j];
		puts("");  
	}
}

int main() {
//	ios::sync_with_stdio(false);

//	freopen(".in", "r", stdin);

	cin >> n;

	vector<int> a(n);
	int mn = 100;
	for(int i = 0; i < n; i++) 
		cin >> a[i], mn = min(mn, a[i]);

	for(int ans = mn; ans >= 0; ans--) {
		if(ans == 0) {
			vector<vector<int> > ans;
		    for(int i = 0; i < n; i++) {
		    	while(a[i] > 0) {
		    		a[i]--;
		    		a[i == 0]--; 

		    		ans.push_back(vector<int>(0));
		    		
		    		ans.back().push_back(i);
		    		ans.back().push_back(i == 0);
		    	}
		    }

		    puts("0");
		    vost(ans);
			
			break;
		}

		multiset<pair<int, int> > b;
		for(int i = 0; i < n; i++)
			if(a[i] - ans) b.insert(make_pair(-(a[i] - ans), i));
		
		bool ok = 1;

		multiset<pair<int, int> > pr;

		vector<vector<int> > ansi;
		int k = 2;
		while(b.size()) {
			if(b.size() == 1) {
				if(ansi.size() == 0) {
					ok = 0;
					break;
				} else {
					ansi.pop_back();
					b = pr;
					k = 3;
					
					if(b.size() == 2) {
						ok = 0;
						break;
					}
				}				            
			}

			pr = b;

			#define new asdasdas

			multiset<pair<int, int> > new;
			ansi.push_back(vector<int>(0));
			for(multiset<pair<int, int> > :: iterator i = b.begin(); i != b.end(); i++) {
				if(k > 0) {
					ansi.back().push_back((*i).second);
					if((*i).first + 1) new.insert(make_pair((*i).first + 1, (*i).second));
				} else new.insert(*i);
			
				k--;
			}
			
			b = new;
			k = 2;
		}

		if(!ok) continue;

		cout << ans << "\n";
		vost(ansi);
		break;		
	}
}