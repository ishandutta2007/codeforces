#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void print(vi a) {
	for(int i = 0; i < a.size(); i++) {
		if(a[i]) {
			cout << 'B';
		} else {
			cout << 'W';
		}
	}
}

vi get_k(vi a, int k) {
	vi b;
	for(int i = 0; i < a.size(); i++) {
		b.push_back(a[(k + i + a.size()) % a.size()]);
	}
	return b;
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a;
    bool ok = true;
    for(int i = 0; i < n; i++) {
    	if(s[i] == 'B') {
    		a.push_back(1);
    	} else {
    		a.push_back(0);
    	}
    }
    for(int i = 0; i < n - 1; i++) {
    	if(a[i] == a[i + 1]) {
    		ok = false;
    		break;
    	}
    }
    if(ok && n % 2 == 0) {
    	if(k % 2 == 1) {
    		for(int i = 0; i < n; i++) {
    			a[i] = 1 - a[i];
    		}
    	}
    	print(a);
    	return 0;
    }
    vi b(n);
    int k1;
    for(int i = 0; i < n; i++) {
    	if(a[i] == a[(i + 1) % n]) {
    		k1 = (i + 1) % n;
    		break;
    	}
    }
    a = get_k(a, k1);
    vector<int> left(n, -1), right(n, -1);
    int prev = 0;
    for(int i = 1; i < n; i++) {
    	if(a[i] != a[(i + 1) % n] && a[i] != a[(i - 1 + n) % n]) {
    		left[i] = prev;
    		continue;
    	}
    	prev = i;
    	b[i] = a[i];
    }
    prev = n - 1;
    for(int i = n - 2; i >= 0; i--) {
    	if(a[i] != a[(i + 1) % n] && a[i] != a[(i - 1 + n) % n]) {
    		right[i] = prev;
    		continue;
    	}
    	prev = i;
    	b[i] = a[i];
    }
    for(int i = 0; i < n; i++) {
    	if(left[i] != -1 && right[i] != -1) {
    		pair<int, int> ans = {right[i] - i, a[right[i]]};
    		if(i - left[i] < right[i] - i) {
    			ans = {i - left[i], a[left[i]]};
    		}
    		if(ans.first <= k) {
    			b[i] = ans.second;
    		} else {
    			b[i] = a[i];
    			if(k % 2 == 1) {
    				b[i] = 1 - b[i];
    			}
    		}
    	}
    }
    b = get_k(b, -k1);
    print(b);
}