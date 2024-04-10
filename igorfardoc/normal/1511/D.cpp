#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

string get_s(int k, int start) {
	string s = "";
	s += (char)(start + 'a');
	if(start == k - 1) {
		return s;
	}
	for(int i = start + 2; i < k; i++) {
		s += (char)(i + 'a');
		s += (char)(start + 'a');
	}
	s += (char)(start + 1 + 'a');
	s += get_s(k, start + 1);
	s += (char)(start + 'a');
	return s;
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
    string s = get_s(k, 0);
    string now = "";
    now += 'a';
    while(now.size() < n) {
    	now += s;
    }
    for(int i = 0; i < n; i++) {
    	cout << now[i];
    }
}