#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	//int n;
	//cin >> n;
	int b[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	int kol = 0;
	int tek = 0;
	for (int i = 0; i < 15; i++){
		cout << b[i] << endl;
		cout << flush;
		string a;
		cin >> a;
		if (a[0] == 'y'){
			kol++;
			tek = b[i];
		}
		if (kol > 1){
			cout << "composite";
			return 0;
		}
	}
	if (kol == 1){
		if (tek <= 10){
			cout << tek*tek << endl;
			cout << flush;
			string a;
			cin >> a;
			if (a[0] == 'y'){
				cout << "composite";
				return 0;
			}
		}
	}
	cout << "prime";
}