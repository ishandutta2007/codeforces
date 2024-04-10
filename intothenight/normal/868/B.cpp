#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAX = 60 * 60 * 12;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	h = (3600 * h + 60 * m + s) % MAX, m = (720 * m + 12 * s) % MAX, s = s * 720, t1 = t1 * 3600 % MAX, t2 = t2 * 3600 % MAX;
	bool failed = false;
	for(int i = t1; i != t2; i = (i + 1) % MAX){
		if(i == h || i == m || i == s){
			failed = true;
			break;
		}
	}
	if(!failed){
		cout << "YES";
		return 0;
	}
	failed = false;
	for(int i = t2; i != t1; i = (i + 1) % MAX){
		if(i == h || i == m || i == s){
			failed = true;
			break;
		}
	}
	if(!failed){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}