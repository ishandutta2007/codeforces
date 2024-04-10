#include<bits/stdc++.h>
using namespace std;

 int ans[8];

inline int changeNum(string s){
	int now = 0;
	for(int i = 0 ; i < s.size() ; i++)
		switch(s[i]){
			case 'A':
				now++;
				break;
			case 'B':
				now += 2;
				break;
			case 'C':
				now += 4;
		}
	return now;
}

int main(){
	memset(ans , 0x3f , sizeof(ans));
	ans[0] = 0;
	int N;
	for(cin >> N ; N ; N--){
		string s;
		int k;
		cin >> k >> s;
		int t = changeNum(s);
		for(int i = 7 ; i >= 0 ; i--)
			ans[i | t] = min(ans[i | t] , ans[i] + k);
	}
	cout << (ans[7] == 0x3f3f3f3f ? -1 : ans[7]);
	return 0;
}