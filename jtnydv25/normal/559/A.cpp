#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int a[6];


int main(){
	int x;
	for(int i = 0; i <= 5; i++){
		cin >> a[i];
	}
	cout << (a[0] + a[1] + a[2]) *(a[0] + a[1] + a[2]) - a[0] * a[0] - a[2] * a[2] - a[4] * a[4];
}