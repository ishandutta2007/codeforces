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
    int n;
    cin >> n;
    vi ans(n, n);
    set<int> s;
    for(int i = 1; i <= n; i++) {
    	s.insert(i);
    }
    while(s.size() >= 2) {
    	int a = *(s.begin());
    	s.erase(s.begin());
    	int b = *(s.begin());
    	s.erase(s.begin());
    	int a1, a2;
    	cout << "? " << a << ' ' << b << endl;
    	cin >> a1;
    	cout << "? " << b << ' ' << a << endl;
    	cin >> a2;
    	if(a1 > a2) {
    		ans[a - 1] = a1;
    		s.insert(b);
    	} else {
    		ans[b - 1] = a2;
    		s.insert(a);
    	}
    }
    cout << "! ";
    for(int i = 0; i < n; i++)  {
    	cout << ans[i] << ' ';
    }
    cout << endl;

}