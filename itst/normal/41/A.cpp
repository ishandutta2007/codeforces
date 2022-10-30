#include<bits/stdc++.h>
using namespace std;

int main(){
	string a , b;
	cin >> a >> b;
	reverse(a.begin() , a.end());
	puts(a == b ? "YES" : "NO");
	return 0;
}