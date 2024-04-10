#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

int arr[10];

int main(){
	int N; cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		char c = getchar();
		while(c == '\n' || c == '\r') c = getchar();
		if(c == 'L'){
			for(int j = 0 ; j < 10 ; ++j)
				if(!arr[j]){arr[j] = 1; break;}
		}
		else if(c == 'R'){
			for(int j = 9 ; j >= 0 ; --j)
				if(!arr[j]){arr[j] = 1; break;}
		}
		else arr[c - '0'] = 0;
	}
	for(int i = 0 ; i < 10 ; ++i) cout << arr[i];
	return 0;
}