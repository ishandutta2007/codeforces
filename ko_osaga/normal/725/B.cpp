#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

char w[5222];

int x(char t){
	if(t == 'f') return 0;
	if(t == 'e') return 1;
	if(t == 'd') return 2;
	if(t == 'a') return 3;
	if(t == 'b') return 4;
	if(t == 'c') return 5;
	assert(0);
}

int main(){
	cin >> w;
	char chk;
	lint n = 0;
	for(int i=0; w[i]; i++){
		if(w[i] <= '9' && w[i] >= '0'){
			n = n * 10 + w[i] - '0';
		}
		else{
			chk = w[i];
		}
	}
	n--;
	if(n % 4 == 2){
		n--;
	}
	else if(n % 4 == 1){
		n++;
	}
	n /= 2;
	lint ret = 1 + x(chk);
	if(n%2) ret--; 
	ret += 8 * n;
	cout << ret;
}