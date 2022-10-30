#include<bits/stdc++.h>
using namespace std;

int pot[5];

int main(){
	int N , cnt = 0;
	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		int a;
		cin >> a;
		if(a == 4)
			cnt++;
		else
			pot[a]++;
	}
	while(pot[1] && pot[3]){
		pot[1]--;
		pot[3]--;
		cnt++;
	}
	while(pot[3]){
		cnt++;
		pot[3]--;
	}
	while(pot[2] >= 2){
		pot[2] -= 2;
		cnt++;
	}
	while(pot[2]){
		pot[1] -= 2;
		pot[2]--;
		cnt++;
	}
	while(pot[1] > 0){
		pot[1] -= 4;
		cnt++;
	}
	cout << cnt;
	return 0;
}