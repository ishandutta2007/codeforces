#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi apply(vi a, vi here) {
	vi ans;
	int now = 0;
	vector<pair<int, int>> b;
	for(int i = 0; i < here.size(); i++) {
		b.push_back({now, now + here[i] - 1});
		now += here[i];
	}
	for(int i = b.size() - 1; i >= 0; i--) {
		for(int j = b[i].first; j <= b[i].second; j++) {
			ans.push_back(a[j]);
		}
	}
	return ans;
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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	--a[i];
    }
    vector<vector<int>> ans;
    while(true) {
    	bool ok = true;
    	for(int i = 0; i < n; i++) {
    		if(a[i] != i) {
    			ok = false;
    			break;
    		}
    	}
    	if(ok) {
    		break;
    	}
    	vi pos(n);
    	for(int i = 0; i < n; i++) {
    		pos[a[i]] = i;
    	}
    	/*int am = 0;
		for(int i = 1; i < n; i++) {
			am += a[i] == a[i - 1] + 1;
		}
		cout << am << endl;*/
		/*
		for(int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
		*/
    	for(int i = 0; i < n; i++) {
    		if(a[i] != n - 1 && pos[a[i] + 1] < i) {
    			int start = i;
    			while(start != 0 && a[start - 1] == a[start] - 1) {
    				--start;
    			}
    			vi here;
    			if(pos[a[i] + 1] != 0) {
    				here.push_back(pos[a[i] + 1]);
    			}
    			here.push_back(start - pos[a[i] + 1]);
    			here.push_back(i - start + 1);
    			if(i != n - 1) {
    				here.push_back(n - 1 - i);
    			}
    			//cout << i << ' ' << pos[a[i] + 1] << ' ' << start << ' ' << end << endl;
    			ans.push_back(here);
    			a = apply(a, here);
    			break;
    		}
    	}
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
    	cout << ans[i].size() << ' ';
    	for(int j = 0; j < ans[i].size(); j++) {
    		cout << ans[i][j] << ' ';
    	}
    	cout << '\n';
    }
}