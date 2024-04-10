#include<iostream>
#include<vector>

using namespace std;

const int INF = 10000000;

int a, b, mini, ind;
string s, t;
vector <int> sol;

int f (int pos, int flag) {
	int cnt=0;
	for (int i=0; i<a; i++) {
		if (i+pos==b) return INF;
		if (s[i]!=t[i+pos]) cnt++;
		if (s[i]!=t[i+pos] && flag) sol.push_back(i+1);
	}
	return cnt;
}

int main () {
	mini=INF;
	cin >> a >> b;
	cin >> s >> t;
	for (int i=0; i<b; i++) {
		int val=f(i, 0);
		if (val<mini) {
			mini=val;
			ind=i;
		}
	}
	f(ind, 1);
	cout << mini << endl;
	for (int i=0; i<sol.size(); i++) {
		cout << sol[i] << " ";
	}
	return 0;
}