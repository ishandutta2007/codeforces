#include<bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N; vector < pair < int , int > > pot;
	for(int i = 0 ; i <= N ; ++i)
		for(int j = 2 * i ; j <= 2 * (i + 1) ; ++j)
			for(int k = 2 * i ; k <= 2 * (i + 1) ; ++k)
				if((!(j & 1) || !(k & 1)) && (!i || (j != 2 * i) || k != (2 * i)))
					pot.push_back(make_pair(j , k));
	cout << pot.size() << endl;
	for(int i = 0 ; i < pot.size() ; ++i)
		cout << pot[i].first << ' ' << pot[i].second << endl;
	return 0;
}