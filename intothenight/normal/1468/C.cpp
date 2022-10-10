#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	set<int> s;
	set<array<int, 2>> t;
	vector<int> a(qn);
	int c = 0;
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			cin >> a[c];
			s.insert(c);
			t.insert({-a[c], c});
			++ c;
		}
		else if(type == 2){
			int i = *s.begin();
			s.erase(i), t.erase({-a[i], i});
			cout << i + 1 << " ";
		}
		else{
			int i = (*t.begin())[1];
			s.erase(i), t.erase({-a[i], i});
			cout << i + 1 << " ";
		}
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