#include <iostream>
#include <vector>

using namespace std;
// void p(vector<int>& v){
// 	for(int i : v) cout << i << " "; cout << endl;
// }
long long work(long long n){
	while (n % 3 == 0 && n != 0)
		n /= 3;
	return n / 3 + 1;
}
int main(){
// 		for(int i = 1; i <= 20; i++)
// 			cout << i << ":" << work(i) << endl;
	long long n;
	cin >> n;	
	cout << work(n) << endl;
	return 0;
}