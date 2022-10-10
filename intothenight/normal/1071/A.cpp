#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int a, b;
	cin >> a >> b;
	int x = 0;
	long long s = 0;
	while(s + x + 1 <= a + b){
		++ x;
		s += x;
	}
	bool swapped = false;
	if(a > b){
		swapped = true;
		swap(a, b);
	}
	vector<int> resa, resb;
	for(auto i = x; i >= 1; -- i){
		if(i <= a){
			a -= i;
			resa.push_back(i);
		}
		else{
			resb.push_back(i);
		}
	}
	if(swapped){
		swap(resa, resb);
	}
	cout << (int)resa.size() << "\n";
	for(auto x: resa){
		cout << x << " ";
	}
	cout << "\n";
	cout << (int)resb.size() << "\n";
	for(auto x: resb){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////