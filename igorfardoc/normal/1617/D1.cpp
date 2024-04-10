#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi col;
int n;

int q(int a, int b, int c) {
	cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
	int res;
	cin >> res;
	return res;
}

void doit(int good, int bad) {
	for(int i = 0; i < n; i++) {
		if(col[i] == -1) {
			col[i] = q(good, bad, i);
		}
	}
}

void print() {
	vi ans;
	for(int i = 0; i < n; i++) {
		if(col[i] == 0) {
			ans.push_back(i);
		}
	}
	cout << "! " << ans.size() << ' ';
	for(const auto& el : ans) {
		cout << el + 1 << ' ';
	}
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
	    cin >> n;
	    col.assign(n, -1);
	    int bef = -1;
	    for(int i = 2; i < n; i++) {
	    	int here = q(i - 2, i - 1, i);
	    	if(i == 2) {
	    		bef = here;
	    	}
	    	if(here != bef) {
	    		if(bef == 0) {
	    			col[i - 3] = 0;
	    			col[i] = 1;
	    			doit(i - 3, i);
	    		} else {
	    			col[i - 3] = 1;
	    			col[i] = 0;
	    			doit(i - 3, i);
	    		}
	    		break;
	    	}
	    	bef = here;
	    }
	    print();
	}
}