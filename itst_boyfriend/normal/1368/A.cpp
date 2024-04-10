#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T , A , B , N;
	for(cin >> T ; T ; --T){
		cin >> A >> B >> N; if(A > B) swap(A , B); int S = 0;
		while(B <= N){A += B; swap(A , B); ++S;}
		cout << S << endl;
	}
	return 0;
}