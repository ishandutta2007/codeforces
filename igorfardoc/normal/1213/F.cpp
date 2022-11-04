#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
   	vi p(n), q(n);
   	for(int i = 0; i < n; i++) {
   		cin >> p[i];
   		--p[i];
   	}
   	for(int i = 0; i < n; i++) {
   		cin >> q[i];
   		--q[i];
   	}
   	string s = "";
   	for(int i = 0; i < n; i++) {
   		s += 'a';
   	}
   	vi where(n);
   	for(int i = 0; i < n; i++) {
   		where[p[i]] = i;
   	}
   	for(int i = 0; i < n; i++) {
   		q[i] = where[q[i]];
   	}
   	int prev = -1;
   	set<int> now;
   	char c = 'a';
   	bool ok = false;
   	for(int i = 0; i < n; i++) {
   		now.insert(q[i]);
   		if(*(now.begin()) == prev + 1 && *(now.rbegin()) == i) {
   			now.clear();
   			for(int j = prev + 1; j <= i; j++) {
   				s[p[j]] = c;
   			}
   			if(c != 'z') {
   				++c;
   			} else {
   				ok = true;
   			}
   			prev = i;
   		}
   	}
   	if(!ok && 'a' + k > c) {
   		cout << "NO";
   		return 0;
   	}
   	cout << "YES\n" << s;
}