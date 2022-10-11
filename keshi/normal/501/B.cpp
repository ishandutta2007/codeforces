#include <bits/stdc++.h>
using namespace std;
int dsu[150], Size[150], n, m, cnt;
map<string, int> tr;
vector<string> v;
vector<string> r;

string a, b;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		//cout << tr[a] << '-' << tr[b] << " => ";
		if (tr[a] == 0){
			v.push_back(b);
			r.push_back(a);
			tr[a] = v.size();
		}
		else{
			v[tr[a] - 1] = b;
		}
		tr[b] = tr[a];
		tr[a] = 0;
		//cout << tr[a] << '-' << tr[b] << endl; 
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++){
		cout << r[i] << ' ' << v[i] << endl;
	}
	return 0;
}