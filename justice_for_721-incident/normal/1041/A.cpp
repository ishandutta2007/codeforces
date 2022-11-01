#include<iostream>
using namespace std;
int mini=1e9,maxi=0;
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n ;i++){
		int a;
		cin >> a;
		mini=min(mini,a);
		maxi=max(maxi,a);
	}
	cout << maxi-mini-n+1 << endl;
}