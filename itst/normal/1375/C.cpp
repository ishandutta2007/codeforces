#include<bits/stdc++.h>
using namespace std;

int T , N , M , arr[300003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; stack < int > stk;
		for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		stk.push(arr[N]);
		for(int i = N - 1 ; i ; --i){
			while(stk.size() > 1 && stk.top() > arr[i]) stk.pop();
			if(stk.top() < arr[i]) stk.push(arr[i]);
		}
		cout << (stk.size() == 1 ? "YES" : "NO") << endl;
	}
	return 0;
}