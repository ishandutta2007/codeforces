#include "bits/stdc++.h"
using namespace std;

long long t1(char x){
	switch(x){
	case 'f':	return 0;
	case 'e':	return 1;
	case 'd':	return 2;
	case 'a':	return 3;
	case 'b':	return 4;
	case 'c':	return 5;
	}
	return -1;
}

long long t2(long long row){
	long long rest = row % 4;
	switch(rest){
	case 0: return 0;
	case 1: return 7;
	case 2: return 0;
	case 3: return 7;	
	}
	return -1;
}

int main(){
	string s;
	cin >> s;
	char x = *s.rbegin();
	s = s.substr(0, s.size()-1);
	
	long long row = stoll(s) - 1;
	
	long long sol = 1 + t1(x) + t2(row) + 16ll*(row/4);
	
	cout << sol << endl;
	
	return 0;
}