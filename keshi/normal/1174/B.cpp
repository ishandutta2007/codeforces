#include <bits/stdc++.h>
using namespace std;
int n, b;
bool o, p;
vector<int> a;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> b;
		if (b % 2){
			p = 1;
		}
		else{
			o = 1;
		}
		a.push_back(b);
	}
	if (p && o){
		sort(a.begin(), a.end());
	}
	for (int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	return 0;
}