#include "bits/stdc++.h"
using namespace std;

const int maxn = 16;
int n, arr[maxn];

bool check2(){
	return (arr[0] + arr[1] == arr[2] + arr[3] &&
			arr[2] + arr[3] == arr[0] + arr[2] &&
			arr[0] + arr[2] == arr[1] + arr[3] &&
			arr[1] + arr[3] == arr[0] + arr[3] &&
			arr[0] + arr[3] == arr[1] + arr[2]);
}

bool check3(){
	return (arr[0] + arr[1] + arr[2] == arr[3] + arr[4] + arr[5] &&
		   arr[3] + arr[4] + arr[5] == arr[6] + arr[7] + arr[8] &&
		   arr[6] + arr[7] + arr[8] == arr[0] + arr[3] + arr[6] &&
		   arr[0] + arr[3] + arr[6] == arr[1] + arr[4] + arr[7] &&
		   arr[1] + arr[4] + arr[7] == arr[2] + arr[5] + arr[8] &&
		   arr[2] + arr[5] + arr[8] == arr[0] + arr[4] + arr[8] &&
		   arr[0] + arr[4] + arr[8] == arr[2] + arr[4] + arr[6]);
}

void sub1(){
	sort(arr, arr + (n * n));

	do{
		if(n == 1 || (n == 2 && check2()) || (n == 3 && check3())){
		   		int sum = 0;
		   		for(int i = 0; i < n; ++i) sum += arr[i];
		   		cout << sum << '\n';

				for(int i = 0; i < n * n; ++i){
					cout << arr[i] << ' ';
					if((i + 1) % n == 0) cout << '\n';
				}
				return;
		   }
	} while(next_permutation(arr, arr + (n * n)));
}

int main(){
	cin >> n;
	for(int i = 0; i < n * n; ++i) cin >> arr[i];

	if(n < 4) sub1();
}