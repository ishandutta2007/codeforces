#include <bits/stdc++.h>
using namespace std;

string a, b;
bool f(int i, int j, int s){
	if(s % 2){
		bool t = 1;
		for(int k = 0; k < s; k++){
			if(a[i + k] != b[j + k]){
				t = 0;
			}
		}
		return t;
	}
	return f(i, j, s / 2) && f(i + s / 2, j + s / 2, s / 2) || f(i, j + s / 2, s / 2) && f(i + s / 2, j, s / 2);
}
int main(){
	cin >> a >> b;
	if(f(0, 0, a.size())){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}