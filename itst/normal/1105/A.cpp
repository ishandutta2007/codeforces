#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

int len[1010] , minN = 1e9 , ind , N;

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i)
		cin >> len[i];
	for(int i = 1 ; i <= 100 ; ++i){
		int sum = 0;
		for(int j = 1 ; j <= N ; ++j)
			if(len[j] > i)
				sum += len[j] - i - 1;
			else
				if(len[j] < i)
					sum += i - len[j] - 1;
		if(minN > sum){
			minN = sum;
			ind = i;
		}
	}
	cout << ind << ' ' << minN;
	return 0;
}