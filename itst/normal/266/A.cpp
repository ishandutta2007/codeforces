#include<bits/stdc++.h>
using namespace std;
int main(){
	int N , cnt = 0;
	char c = '0';
	cin >> N;
	while(N--){
		char s;
		cin >> s;
		if(s == c)	cnt++;
		else	c = s;
	}
	cout << cnt;
	return 0;
}