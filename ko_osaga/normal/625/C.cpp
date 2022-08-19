#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int n, k;

int arr[1005][1005];

int main(){
	cin >> n >> k;
	int piv = n * n;
	for(int i=0; i<n; i++){
		for(int j=n-1; j>=k-1; j--){
			arr[i][j] = piv--;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=k-2; j>=0; j--){
			arr[i][j] = piv--;
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		ret+=arr[i][k-1];
	}
	cout << ret << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ",arr[i][j]);
		}
		puts("");
	}
}