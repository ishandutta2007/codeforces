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

int x;

int f(int x){
	return (x * x + 1) / 2;
}

int i;

int main(){
	cin >> x;
	for(i=1; ; i++){
		if(i%2 == 0){
			if(x%4 == 0 && f(i / 2 - 1) * 4 >= x){
				cout << i;
				return 0;
			}
		}
		else{
			int cnt_indep = 1; // remove one
			int cnt_twos = (i % 4 == 1 ? (i - 1) : (i - 3)); // remove two
			int cnt_all = f(i) - cnt_indep - cnt_twos; // remove four
			for(int i=0; i<=cnt_indep; i++){
				for(int j=0; j<=cnt_twos; j+=2){
					for(int k=0; k<=cnt_all; k+=4){
						if(i + j + k == x){
							cout << ::i;
							return 0;
						}
					}
				}
			}
			if(i % 4 == 3){
				int cnt_indep = 0;
				int cnt_twos = i + 1;
				int cnt_all = 4 * (f(i/2) - 1);
			for(int i=0; i<=cnt_indep; i++){
				for(int j=0; j<=cnt_twos; j+=2){
					for(int k=0; k<=cnt_all; k+=4){
						if(i + j + k == x){
							cout << ::i;
							return 0;
						}
					}
				}
			}
			}
		}
	}
}