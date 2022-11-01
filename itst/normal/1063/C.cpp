#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	int N , L = 0 , R = 1e9;
	string s , s1;
	N = read();
	cout << 1 << ' ' << R << endl;
	cin >> s;
	for(int i = 2 ; i <= N ; ++i){
		int mid = L + R >> 1;
		cout << 1 << ' ' << mid << endl;
		cin >> s1;
		if(s1 == s)
			R = mid;
		else
			L = mid;
	}
	cout << 0 << ' ' << L << ' ' << 2 << ' ' << R;
	return 0;
}