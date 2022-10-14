#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
	int N; cin >> N;
	vi v(N); for(int &i: v)cin >> i;
	sort(v.begin(),v.end());
	for(int i = 0; i < N-1; i++){
		if(v[i+1] < 2*v[i] && v[i+1] > v[i]){
			cout << "YES\n"; return 0;
		}
	}
	cout << "NO\n";
	return 0;
}