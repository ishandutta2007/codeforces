#include<bits/stdc++.h>
using namespace std;

int T , N , A[1003];
void output(int x , int y , int z){cout << x << ' ' << y << ' ' << z << endl;}

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> A[i];}
		cout << N * 3 << endl;
		for(int i = 1 ; i <= N ; i += 2)
			for(int j = 0 ; j < 2 ; ++j){
				output(1 , i , i + 1); output(1 , i , i + 1); output(2 , i , i + 1);
			}
	}
	return 0;
}