#include<bits/stdc++.h>
using namespace std;
int sum[150001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N , K , minN = 0x7fffffff , minD;
	cin >> N >> K;
	for(int i = 1 ; i <= N ; i++){
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	for(int i = K ; i <= N ; i++)
		if(minN > sum[i] - sum[i - K])
			minN = sum[i] - sum[minD = i - K];
	cout << minD + 1;
    return 0;
}