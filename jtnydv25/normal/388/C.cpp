#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

vector<int> vec;

int main(){
	int x = 0, y = 0, n = 0;
	cin.tie(0);
	cin>> n;
	for(int i = 1; i <= n; i++){
		int sz;
		cin >> sz;
		for(int j = 1; j <= sz; j++){
			int val;
			cin >> val;
			if(j <= sz / 2) x += val;
			else if(2 * j - 1 == sz) vec.push_back(val);
			else y += val;
		}
	}
	sort(vec.begin(), vec.end());
	int sz = vec.size();
	for(int i =sz - 1; i >= 0; i -= 2) x += vec[i];
	for(int i = sz - 2; i >= 0; i -= 2) y += vec[i];
	cout << x << " " << y << endl;
}