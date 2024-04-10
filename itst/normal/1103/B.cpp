#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

string s;

int main(){
	cin >> s;
	while(s == "start"){
		int L = 0 , R = 1;
		while(R < 1e9){
			cout << "? " << L << " " << R << endl;
			cin >> s;
			if(s == "x")
				break;
			L = R;
			R <<= 1;
		}
		R = min(R , (int)1e9);
		int cur = L;
		++L;
		while(L < R){
			int mid = (L + R) >> 1;
			cout << "? " << cur << ' ' << mid << endl;
			cin >> s;
			if(s == "x")
				R = mid;
			else
				L = mid + 1;
		}
		cout << "! " << L << endl;
		cin >> s;
	}
	return 0;
}