#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
void f1(int n){
	if(n<6) cout << -1 << endl;
	else{
		for(int i=2; i<=n-2 ;i++){
			cout << 1 << ' ' << i << endl;
		}
		cout << 2 << ' ' << n-1 << endl << 2 << ' ' << n << endl;
	}
}
void f2(int n){
	for(int i=2; i<=n ;i++){
		cout << i-1 << ' ' << i << endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	f1(n);
	f2(n);
}