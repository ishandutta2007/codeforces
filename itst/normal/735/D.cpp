#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#include<random>
#include<cassert>
//This code is written by Itst
using namespace std;

int x;

bool chk(int x){
	for(int i = 2 ; i * i <= x ; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

int main(){
	cin >> x;
	if(chk(x))
		cout << 1;
	else
		if(!(x & 1) || chk(x - 2))
			cout << 2;
		else
			cout << 3;
	return 0;
}