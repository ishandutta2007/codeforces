#include <bits/stdc++.h>
using namespace std;

map<int, int> freq;
int main(){
	int n;
	cin >> n;
	int x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		freq[x]++;
	}
	if(freq.size() == 2){
		set<int> st;
		vector<int > vec;
		for(auto it : freq){
			st.insert(it.second);
			vec.push_back(it.first);
		}
		if(st.size() == 1){
			cout << "YES" << endl;
			cout << vec[0] << " " << vec[1] << endl;
			return 0;
		}

	}
	cout << "NO" << endl;
}