#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	static int arr[100003] , N;
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	for(int i = 30 ; i >= 0 ; --i){
		bool flg = 0; int id = 0;
		for(int j = 1 ; j <= N ; ++j)
			if(arr[j] >> i & 1)
				if(!id) id = j;
				else flg = 1;
		if(!flg && id){
			swap(arr[1] , arr[id]);
			break;
		}
	}
	for(int i = 1 ; i <= N ; ++i) cout << arr[i] << ' ';
	return 0;
}