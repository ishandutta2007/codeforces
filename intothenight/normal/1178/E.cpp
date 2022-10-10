#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string temp;
	cin >> temp;
	deque<char> s(temp.begin(), temp.end()), front, back;
	while(s.size() > 3){
		int n = s.size();
		if(s[0] == s[n - 1]){
			front.push_back(s[0]);
			back.push_front(s[n - 1]);
		}
		else if(s[1] == s[n - 1]){
			front.push_back(s[1]);
			back.push_front(s[n - 1]);
		}
		else if(s[0] == s[n - 2]){
			front.push_back(s[0]);
			back.push_front(s[n - 2]);
		}
		else{
			front.push_back(s[1]);
			back.push_front(s[n - 2]);
		}
		s.pop_front(), s.pop_front();
		s.pop_back(), s.pop_back();
	}
	if(s.size()){
		front.push_back(s[0]);
	}
	for(auto x: front){
		cout << x;
	}
	for(auto x: back){
		cout << x;
	}
	return 0;
}