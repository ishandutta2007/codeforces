#include<bits/stdc++.h>
using namespace std;

int T , N , K; string str;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> K >> str; string target; vector < pair < int , int > > op;
		for(int i = 1 ; i <= N / 2 - K + 1 ; ++i) target.push_back('(');
		for(int i = 1 ; i <= N / 2 - K + 1 ; ++i) target.push_back(')');
		for(int i = 1 ; i <= K - 1 ; ++i){target.push_back('('); target.push_back(')');}
		
		for(int i = 0 ; i < N ; ++i)
			for(int j = i ; j < N ; ++j)
				if(str[j] == target[i]){
					reverse(str.begin() + i , str.begin() + j + 1);
					op.push_back(make_pair(i , j)); break;
				}
		cout << op.size() << endl;
		for(int i = 0 ; i < op.size() ; ++i){
			pair < int , int > t = op[i]; cout << t.first + 1 << ' ' << t.second + 1 << endl;
		}
	}
	return 0;
}