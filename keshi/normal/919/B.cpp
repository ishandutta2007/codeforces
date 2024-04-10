#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n, i, m, b;

vector <int> a;

int main(){
	cin >> n;
	a.pb(1);
	a.pb(9);
	m = 1;
	i = a.size() - 1;
	while (m < n){
		/*cout << m << ": ";
		for(int j = 0; j < a.size(); j++){
			cout << a[j];
		}
		cout << endl;*/
		a[i - 1]++;
		b = a[i];
		a[i] = 0;
		a.back() = b - 1;
		if(a[0] == 10){
			a[0] = 1;
			a.pb(9);
		}
		if(a.back()){
			i = a.size() - 1;
		}
		else{
			i--;
		}
		m++;
	}
	for(int j = 0; j < a.size(); j++){
		cout << a[j];
	}
	cout << endl;
	return 0;
}