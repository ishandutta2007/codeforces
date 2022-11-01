#include<bits/stdc++.h>
using namespace std;

int main(){
	int T; vector < int > A(4);
	for(cin >> T ; T ; --T){
		cin >> A[0] >> A[1] >> A[2] >> A[3];
		sort(A.begin() , A.end()); cout << A[0] * A[2] << endl;
	}
	return 0;
}