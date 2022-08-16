#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
// #define endl '\n'
#endif

int n, k;
int val;
void ask(vector<int> v){
	cout << "? ";
	for(int x : v) cout << x + 1 << " ";
	cout << endl;
	fflush(stdout);
	int xr; cin >> xr;
	val ^= xr;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin >> n >> k;
	if(n % 2 == 1 && k % 2 == 0){
		cout << -1 << endl;
		fflush(stdout);
		return 0;
	}
	
	vector<int> freq(n);
	for(int i = 0; i < n; i++) freq[i] = 1;
	int s = n;
	while(s % k != 0 || k * (*max_element(all(freq))) > s){
		s += 2;
		freq[min_element(all(freq)) - freq.begin()] += 2;
	}

	for(int i = 0; i < s / k; i++){
		vector<int> q;
		vector<int> perm(n);
		iota(all(perm), 0);
		sort(all(perm), [&](int x, int y){return freq[x] > freq[y];});
		for(int j = 0; j < k; j++){
			q.push_back(perm[j]);	
			freq[perm[j]]--;
		}
		ask(q);
	}
	cout<< "! " << val << endl;
	fflush(stdout);
}