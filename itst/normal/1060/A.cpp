#include<bits/stdc++.h>
using namespace std;
int noEight , Eight;
int main(){
	int N , cnt = 0;
	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		char c;
		cin >> c;
		if(c == '8')
			Eight++;
		else
			noEight++;
	}
	while(Eight && Eight + noEight >= 11){
		Eight--;
		if(noEight >= 10)
			noEight -= 10;
		else{
			Eight -= 10 - noEight;
			noEight = 0;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}