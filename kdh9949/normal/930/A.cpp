#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, c[N], r;
vector<int> e[N];

void f(int x, int y){
	c[y]++;
	for(int i : e[x]) f(i, y + 1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i = 2, x; i <= n; i++){
		cin >> x;
		e[x].push_back(i);
	}
	f(1, 1);
	for(int i = 1; i <= n; i++) r += (c[i] & 1); 
	cout << r << endl;
}