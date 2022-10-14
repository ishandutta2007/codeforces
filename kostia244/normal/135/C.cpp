//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e2 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
string s;
int cnt[2], q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i]=='?') q++;
		else cnt[s[i]-'0']++;
	}
	int c0 = (s.size()-2)/2;
	int c1 = s.size()-2-c0;
	if(cnt[1]<=c1)
		cout << "00\n";
	if(cnt[0] <= s.size()/2 && (cnt[0]+q) >= s.size()/2) {
	if(s.back()=='1'||(s.back()=='?'&&cnt[1]<(s.size()+1)/2))
		cout << "01\n";
	if(s.back()=='0'||(s.back()=='?'&&cnt[0]<s.size()/2))
		cout << "10\n";
	}
	if(cnt[0]<=c0)
		cout << "11\n";

}