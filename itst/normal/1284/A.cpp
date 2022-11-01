#include<bits/stdc++.h>
using namespace std;

string arr1[25] , arr2[25] , arr[10003];
int N , M , Q;

int main(){
	cin >> N >> M;
	for(int i = 0 ; i < N ; ++i) cin >> arr1[i];
	for(int j = 0 ; j < M ; ++j) cin >> arr2[j];
	for(int i = 0 ; i < N * M ; ++i)
		arr[i] = arr1[i % N] + arr2[i % M];
	for(cin >> Q ; Q ; --Q){
		int x; cin >> x; --x;
		cout << arr[x % (N * M)] << endl;
	}
	return 0;
}