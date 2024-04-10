#include<bits/stdc++.h>
using namespace std;

int main(){
	int N , cnt = 0;
	string s;
	cin >> N >> s;
	for(int i = 0 ; i < N - 2 ; i++)
		if(s[i] == 'x' && s[i + 1] == 'x' && s[i + 2] == 'x')
			cnt++;
	cout << cnt;
	return 0;
}