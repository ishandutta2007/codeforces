#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		/*
		aaabaaaa



		*/
		deque<char>dq;
		int n;
		cin >> n;
		if(n==1){
			cout << "a\n";
			continue;
		}
		if(n%2==0){
			
			n--;
			dq.push_back('b');
			for(int i = 0; i<n; i++){
				if(i%2==0)dq.push_front('a');
				else dq.push_back('a');
			}
		}
		else{
			n-=2;
			dq.push_back('b');
			dq.push_back('c');
			for(int i = 0; i<n; i++){
				if(i%2==0)dq.push_front('a');
				else dq.push_back('a');
			}
		}
		while(dq.size()){
			cout << dq[0];
			dq.pop_front();
		}
		cout << "\n";
	}
	return 0;
}