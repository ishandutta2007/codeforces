#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;


int main(){
	int T , N , M , x , y;
	for(cin >> T ; T ; --T){
		cin >> N >> M >> x >> y;
		cout << ((M - N) % (x + y) == 0 ? (M - N) / (x + y) : -1) << endl;
	}
	return 0;
}