#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int N;

int main(){
	N = read(); vector < pair < int , int > > ans;
	for(int i = 2 ; i <= N ; i <<= 1)
		for(int j = 1 ; j + i <= N + 1 ; j += i)
			for(int k = 0 ; k < i / 2 ; ++k)
				ans.push_back(make_pair(j + k , j + k + i / 2));
	vector < int > lft; for(int p = 1 ; p <= N ; p <<= 1) if((N & p) == p) lft.push_back(p);
	if(lft.size() != 1){
		int p1 = 1 , cur = N; vector < int > pos; pos.push_back(p1++);
		for(int j = 0 ; j + 1 < lft.size() ; ++j){
			vector < int > pp; for(int t = cur ; t > cur - lft[j] ; --t) pp.push_back(t);
			while(pos.size() < pp.size()){
				vector < int > p2; while(p2.size() < pos.size()) p2.push_back(p1++);
				for(int j = 0 ; j < pos.size() ; ++j) ans.push_back(make_pair(p2[j] , pos[j]));
				pos.insert(pos.end() , p2.begin() , p2.end());
			}
			for(int j = 0 ; j < pos.size() ; ++j) ans.push_back(make_pair(pos[j] , pp[j]));
			pos.insert(pos.end() , pp.begin() , pp.end()); cur -= lft[j];
		}
	}
	cout << ans.size() << endl;
	for(auto t : ans) cout << t.first << ' ' << t.second << '\n';
	return 0;
}