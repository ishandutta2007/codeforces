#include<iostream>
#include<vector>

using namespace std;

int h1, a1, c1, h2, a2;
vector <string> v;

int main () {
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	while (h2>0) {
		if (h2-a1<=0) {
			v.push_back("STRIKE");
			h2-=a1;
		} else if (h1-a2<=0) {
			v.push_back("HEAL");
			h1=h1-a2+c1;
		} else {
			v.push_back("STRIKE");
			h1-=a2;
			h2-=a1;
		}
	}
	cout << v.size() << endl;
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}