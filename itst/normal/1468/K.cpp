#include<bits/stdc++.h>
using namespace std;

vector < pair < int , int > > ans;

int main(){
	ios::sync_with_stdio(0); int T; string s;
	for(cin >> T ; T ; --T){
		cin >> s; int x = 0 , y = 0 , ansx = 0 , ansy = 0;
		for(auto t : s){switch(t){case 'L': --x; break; case 'R': ++x; break; case 'U': ++y; break; case 'D': --y; break;} ans.push_back(make_pair(x , y));}
		for(auto t : ans){
			x = 0; y = 0; int px = 0 , py = 0;
			for(auto p : s){
				switch(p){case 'L': --x; break; case 'R': ++x; break; case 'U': ++y; break; case 'D': --y; break;}
				if(x == t.first && y == t.second){x = px; y = py;} px = x; py = y;
			}
			if(!x && !y){ansx = t.first; ansy = t.second;}
		}
		cout << ansx << ' ' << ansy << endl;
	}
	return 0;
}