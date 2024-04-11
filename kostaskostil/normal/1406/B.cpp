#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define int long long
// - - - - -
// + - - + -
// + + - + +
// ? -> -
// ? -> +
// 0 1 2 3 4 - - - - +
// 0 1 2 4 5

// + - - + + + - + ...
// if there is no positive int => just take product of max numbers, it will be negative anyways
// if there exists a + => max + should be used, otherwise you can improve
// sort by modulus, find 4 max +, 4 max - (if they exist, excluding the chosen +), group by 2s, choose 2 max out of the products
// if there are >5 numbers, and not all are negative - we can always find a non-negative combination

bool cmpMod(int a, int b){
	return abs(a) > abs(b);
}

int maxProd(vector<int> &a){
	sort(a.begin(), a.end(), [](int a, int b){ return a > b; });
	// for(int i = 0; i < a.size(); i++){ // check sorting
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	int maxEl = a[0];
	if(maxEl <= 0 || a.size() == 5){
		return a[0]*a[1]*a[2]*a[3]*a[4];
	}
	else{
		sort(a.begin()+1, a.end(), cmpMod);
		// for(int i = 0; i < a.size(); i++){ // check sorting
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
		vector<int> pos(0);
		vector<int> neg(0);
		for(int i = 1; i < a.size(); i++){
			if(a[i] >= 0 && pos.size() < 4){
				pos.push_back(a[i]);
				// cout << "pos: " << a[i] << endl;
			}
			else if(a[i] <= 0 && neg.size() < 4){
				neg.push_back(a[i]);
				// cout << "neg: " << a[i] << endl;
			}

		}
		int result = 0;
		if (neg.size() >= 4)
            result=max(result, maxEl*neg[0]*neg[1]*neg[2]*neg[3]);
		if (pos.size() >= 4)
            result=max(result, maxEl*pos[0]*pos[1]*pos[2]*pos[3]);
		if ((neg.size() >= 2) and (pos.size() >= 2))
            result=max(result, maxEl*pos[0]*pos[1]*neg[0]*neg[1]);
        return result;
	}
}

main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		cout << maxProd(a) << endl;
	}
	return 0;
}