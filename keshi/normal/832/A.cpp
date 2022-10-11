#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll a,b;
	cin >> a >> b;
	if ((a/b)%2==0){
		cout << "NO";
	}
	else{
		cout << "YES";
	}
	return 0;
}