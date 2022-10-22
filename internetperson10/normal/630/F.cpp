#include <bits/stdc++.h>

using namespace std;

long long int arr[778][10];

int main() {
	for(int a=0; a<778; a++) {
		for(int b=0; b<=min(a, 8); b++) {
			if(b==0) arr[a][b]=1;
			else arr[a][b]=arr[a-1][b-1]+arr[a-1][b];
		}
	}
	int n;
	cin >> n;
	cout << arr[n][5]+arr[n][6]+arr[n][7] << '\n';
}