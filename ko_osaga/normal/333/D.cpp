#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<double, int> pi;

int n, m;
int a[1005][1005];
vector<int> v;

int pan[1005][1005];

bool trial(int x){
	memset(pan, -1, sizeof(pan));
	for(int i=0; i<n; i++){
		vector<int> v;
		for(int j=0; j<m; j++){
			if(a[i][j] >= x) v.push_back(j);
		}
		for(int j=0; j<v.size(); j++){
			for(int k=0; k<j; k++){
				if(pan[v[j]][v[k]] == -1){
					pan[v[j]][v[k]] = i;
				}
				else{
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d",&a[i][j]);
			v.push_back(a[i][j]);
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	int s = 0, e = v.size()-1;
	while(s != e){
		int m = (s+e+1)/2;
		if(trial(v[m])) s = m;
		else e = m-1;
	}
	cout << v[s];
}