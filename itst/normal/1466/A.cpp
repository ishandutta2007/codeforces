#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int T , N , X[103];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; set < int > val;
		for(int i = 1 ; i <= N ; ++i){
			cin >> X[i]; for(int j = 1 ; j < i ; ++j) val.insert(X[i] - X[j]);
		}
		cout << val.size() << endl;
	}
	return 0;
}