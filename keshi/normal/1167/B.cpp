#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ans[6], k, l;
map <int, pair<int, int> > m;
pair <int, int> b;
pair <int, int> c;
pair <int, int> d;
map <int, bool> v;
void f(pair<int, int> s, pair<int, int> y, int o){
	v[c.first] = 1;
	v[d.first] = 1;
	v[c.second] = 1;
	v[d.second] = 1;
	
	if (c.first == d.first){
		ans[o + 1] = c.first;
		ans[o] = c.second;
		ans[o + 2] = d.second;
	}
	if (c.first == d.second){
		ans[o + 1] = c.first;
		ans[o] = c.second;
		ans[o + 2] = d.first;
	}
	if (c.second == d.first){
		ans[o + 1] = c.second;
		ans[o] = c.first;
		ans[o + 2] = d.second;
	}
	if (c.second == d.second){
		ans[o + 1] = c.second;
		ans[o] = c.first;
		ans[o + 2] = d.first;
	}
}

int main(){
	int a[6] = {4, 8, 15, 16, 23, 42};
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			b.first = a[i];
			b.second = a[j];
			m[a[i] * a[j]] = b;
		}
	}
	
	cout << "? " << 1 << ' ' << 2 << endl;;
	fflush(stdout);
	cin >> k;
	c = m[k];
	
	for (int i = 1; i < 4; i++){
		cout << "? " << i + 1 << ' ' << i + 2 << endl;
		cout.flush();
		cin >> k;
		d = m[k];
		f(c, d, i - 1);
		c.first = d.first;
		c.second = d.second;
	}
	for (int i=0; i < 6; i++){
		if (!v[a[i]]){
			ans[5] = a[i];
		}
	}
	cout << "! ";
	for (int i = 0; i< 6; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	cout.flush();
	return 0;
}