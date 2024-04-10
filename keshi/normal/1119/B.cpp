#include <bits/stdc++.h>
using namespace std;
int n, m, a;
bool check(priority_queue<int> p){
	int l = 0, o = 0;
	bool k = 0;
	while (!p.empty()){
		//cout << p.top() << ' ';
		if (p.top() > l || k){
			l = p.top();
			o += l;
			k = 0;
		}
		else if(!k){
			k = 1;
		}
		p.pop();
	}
	//cout << "#" <<  o << endl;
	if (o > m){
		return 0;
	}
	return 1;
}
int main(){
	priority_queue<int> p;	
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a;
		p.push(a);
		if (!check(p)){
			cout << i;
			return 0;
		}
	}
	cout << n;
	return 0;
}