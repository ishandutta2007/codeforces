#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	int N , cnt , x1 = 0 , y1 = 0 , x2 = 0 , y2 = 0;
	cin >> N;
	bool f = 0;
	for(int i = 2 ; i <= N ; ++i){
		cout << "? " << i << ' ' << 1 << ' ' << N << ' ' << N << endl;
		cin >> cnt;
		if(!f && (cnt & 1)){
			x1 = i - 1;
			x2 = N;
			f = 1;
		}
		else
			if(f && !(cnt & 1)){
				x2 = i - 1;
				break;
			}
	}
	f = 0;
	for(int i = 2 ; i <= N ; ++i){
		cout << "? " << 1 << ' ' << i << ' ' << N << ' ' << N << endl;
		cin >> cnt;
		if(!f && (cnt & 1)){
			y1 = i - 1;
			y2 = N;
			f = 1;
		}
		else
			if(f && !(cnt & 1)){
				y2 = i - 1;
				break;
			}
	}
	if(x1 == 0){
		int L = 1 , R = N;
		while(L < R){
			int mid = (L + R + 1) >> 1;
			cout << "? " << mid << ' ' << y1 + 1 << ' ' << N << ' ' << N << endl;
			cin >> cnt;
			if(cnt & 1) L = mid;
			else R = mid - 1;
		}
		x1 = x2 = L;
	}
	if(y1 == 0){
		int L = 1 , R = N;
		while(L < R){
			int mid = (L + R + 1) >> 1;
			cout << "? " << x1 + 1 << ' ' << mid << ' ' << N << ' ' << N << endl;
			cin >> cnt;
			if(cnt & 1) L = mid;
			else R = mid - 1;
		}
		y1 = y2 = L;
	}
	cout << "? " << x1 << ' ' << y1 << ' ' << x1 << ' ' << y1 << endl;
	cin >> cnt;
	if(!(cnt & 1)) swap(y1 , y2);
	cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	return 0;
}