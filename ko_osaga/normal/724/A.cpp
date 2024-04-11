#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int v[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dal(string s){
	if(s == "monday") return 0;
	if(s == "tuesday") return 1;
	if(s == "wednesday") return 2;
	if(s == "thursday") return 3;
	if(s == "friday") return 4;
	if(s == "saturday") return 5;
	if(s == "sunday") return 6;
}

int main(){
	string a, b;
	cin >> a >> b;
	for(int i=0; i<11; i++){
		if((dal(a) + v[i]) % 7 == dal(b) % 7){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}