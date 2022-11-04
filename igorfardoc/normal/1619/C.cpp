#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi to_vec(ll a) {
	vi res;
	while(a) {
		res.push_back(a % 10);
		a /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
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
    	ll a, s;
    	cin >> a >> s;
    	auto a1 = to_vec(a);
    	auto s1 = to_vec(s);
    	int now = s1.size() - 1;
    	bool ok = true;
    	vi b;
    	for(int i = a1.size() - 1; i >= 0; i--) {
    		int here1, here2;
    		if(now < 0) {
    			here1 = 0;
    			here2 = 0;
    		} else {
    			here1 = s1[now];
    			if(now > 0) {
    				here2 = s1[now - 1] * 10 + here1;
    			} else {
    				here2 = here1;
    			}
    		}
    		if(here1 - a1[i] < 0 && (here2 - a1[i] > 9 || here2 - a1[i] < 0)) {
    			ok = false;
    			break;
    		}
    		if(here1 - a1[i] >= 0) {
    			b.push_back(here1 - a1[i]);
    			--now;
    			continue;
    		}
    		b.push_back(here2 - a1[i]);
    		now -= 2;
    	}
    	if(!ok) {
    		cout << "-1\n";
    		continue;
    	}
    	while(now >= 0) {
    		b.push_back(s1[now]);
    		--now;
    	}
    	while(b[b.size() - 1] == 0) {
    		b.pop_back();
    	}
    	reverse(b.begin(), b.end());
    	for(const auto& el : b) {
    		cout << el;
    	}
    	cout << '\n';
    }
}