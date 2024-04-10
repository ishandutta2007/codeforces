//CF 34C Page Numbers
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#define ll long long
#define ms(lsy) memset(lsy,0,sizeof(lsy))
using namespace std;

int n = 1;
ll data[10000];

int g_num(char c){
	return c-'0';
}

void __init__(){
	ms(data);
}

int main(){
	__init__();
	
	string inp;
	int len,pos = 0,i;
	cin >> inp;
	len = inp.length();
	inp += ',';
	while(pos < len){
		while(inp[pos] != ','){
			data[n] *= 10;
			data[n] += g_num(inp[pos]);
			pos++;
		}
		pos++;
		n++;
	}
	n--;
	
	sort(data,data + n + 1);
	
	pos = 1;
	int lhs = 1,rhs = 0;
	while(pos <= n){
		if(data[pos] < data[pos+1]-1 || pos == n){
			rhs = pos;
			if(data[lhs] == data[rhs]) cout << data[lhs];
			else cout << data[lhs] << '-' << data[rhs];
			if(pos != n)cout << ',';
			lhs = pos + 1;
		}
		pos++;
	}
	//for(i = 1;i <= n;i++)cout << data[i] << ' ';
	return 0;
}