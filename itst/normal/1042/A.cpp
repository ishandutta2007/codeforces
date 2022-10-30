#include<bits/stdc++.h>
using namespace std;
int num[101];
int main(){
	int N , M , sum = 0 , maxN = 0;
	cin >> N >> M;
	for(int i = 1 ; i <= N ; i++){
		cin >> num[i];
		maxN = max(maxN , num[i]);
		sum += num[i];
	}
	cout << max(maxN , (int)ceil((sum + M) * 1.0 / N)) << ' ' << maxN + M;
	return 0;
}