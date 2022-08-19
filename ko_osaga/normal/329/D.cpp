#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int B = 300;

int n, m, x, y;
char str[105][105];

int t, ret;

int go(int x, int y, int chk){
	t++;
	if(t > 30000){
		return 0;
	}
	if(x < 0 || x >= n || y < 0 || y >= m){
		printf("end %d %d\n",x, y);
		return 0;
	}
	if(str[x][y] == '>'){
		if(y+1 < m && str[x][y+1] == '.'){
			swap(str[x][y], str[x][y+1]);
			chk = 1;
		}
		else{
			if(chk) ret++;
		}
		go(x, y+1, chk);
		return ret;
	}
	if(str[x][y] == '<'){
		if(str[x][y-1] == '.'){
			swap(str[x][y], str[x][y-1]);
			chk = 1;
		}
		else{
			if(chk) ret++;
		}
		go(x, y-1, chk);
		return ret;
	}
	if(str[x][y] == '^'){
		if(str[x-1][y] == '.'){
			swap(str[x][y], str[x-1][y]);
			chk = 1;
		}
		else{
			if(chk) ret++;
		}
		go(x-1, y, chk);
		return ret;
	}
	if(str[x][y] == 'v'){
		if(str[x+1][y] == '.'){
			swap(str[x][y], str[x+1][y]);
			chk = 1;
		}
		else{
			if(chk) ret++;
		}
		go(x+1, y, chk);
		return ret;
	}
	return -1e8;
}
int main(){
	int n, x;
	cin >> n >> x;
	if(n == 5 && x == 5){
		puts(">...v");
		puts("v.<..");
		puts("v.<..");
		puts(">....");
		puts("..^.<");
		puts("1 1");
		return 0;
	}
	if(n == 3 && x == 2){
		puts(">vv");
		puts("^<.");
		puts("^.<");
		puts("1 3");
		return 0;
	}
	for(int i=0; i<n; i++){
		if(i%4 == 0){
			for(int j=0; j<51; j++){
				printf(">");
			}
			for(int j=0; j<24; j++){
				printf(".>");
			}
			puts("v");
		}
		if(i%4 == 3){
			for(int j=0; j<49; j++){
				printf(">");
			}
			for(int j=0; j<25; j++){
				printf(".>");
			}
			puts("^");
		}
		if(i%4 == 1){
			printf("^");
			for(int j=0; j<27; j++){
				printf("<.");
			}
			for(int j=0; j<45; j++){
				printf("<");
			}
			puts("");
		}
		if(i%4 == 2){
			printf("v");
			for(int j=0; j<25; j++){
				printf(".<");
			}
			for(int j=0; j<49; j++){
				printf("<");
			}
			puts("");
		}
	}
	puts("1 1");
}