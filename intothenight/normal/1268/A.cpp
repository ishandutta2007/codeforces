#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s, t = s;
	for(int i = k; i < n; ++ i) t[i] = t[i - k];
	for(int i = k; i < n; ++ i){
		if(t[i] > s[i]) break;
		if(t[i] < s[i]){
			int p = k - 1;
			while(t[p] == '9') t[p --] = '0';
			++ t[p];
			for(int j = k; j < n; ++ j) t[j] = t[j - k];
			break;
		}
	}
	cout << int(t.size()) << "\n" << t;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////