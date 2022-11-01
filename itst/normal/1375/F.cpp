#include<bits/stdc++.h>
using namespace std;

int main(){
	long long arr[4]; cin >> arr[1] >> arr[2] >> arr[3];
	cout << "First" << endl << 2000000000 << endl;
	int id; cin >> id; arr[id] += 2000000000;
	int pos[4] = {0,1,2,3}; sort(pos + 1 , pos + 4 , [&](int p , int q){return arr[p] < arr[q];});
	long long x1 = arr[pos[2]] - arr[pos[1]] , x2 = arr[pos[3]] - arr[pos[2]];
	cout << x1 + 2 * x2 << endl; cin >> id;
	if(id == pos[1]) cout << x2 << endl;
	else cout << x1 + x2 << endl;
	return 0;
}