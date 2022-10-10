#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt0 = 0, cnt1 = 0;
	for(auto c: s){
		if(c == '0'){
			cnt0 ++;
		}
		else{
			cnt1 ++;
		}
	}
	if(cnt0 != cnt1){
		cout << "1\n" << s << "\n";
	}
	else{
		cout << "2\n" << s[0] << " " << s.substr(1, n - 1) << "\n";
	}
	return 0;
}