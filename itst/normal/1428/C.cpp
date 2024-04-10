#include<bits/stdc++.h>
using namespace std;

int main(){
	vector < char > pot; int T; string S;
	for(cin >> T ; T ; --T){
		cin >> S; pot.clear();
		for(auto t : S)
			if(pot.size() && t == 'B') pot.pop_back();
			else pot.push_back(t);
		cout << pot.size() << endl;
	}
	return 0;
}