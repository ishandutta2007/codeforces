#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))

bool prime(int n){
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return 0;
	return n >= 2;
}
vector<int> vec;
int main(){
	int n;
	cin >> n;

	for(int p = 2; p <= n; p++){
		if(prime(p)){
			int P = p;
			int i = 1;
			while(P <= n){
				vec.push_back(P);
				P *= p;
				i++;
			}
		}
	}

	cout << vec.size() << endl;
	for(int x : vec) cout << x << " ";
	cout << endl;
}