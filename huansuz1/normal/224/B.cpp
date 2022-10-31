#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>

#define f first
#define s second
#define mp make_pair
#define ll long long

using namespace std;

int n , m , a[123456] , z=0 , x=-1 , y=-1 , w=1, mi=123567 , b[123456] , c[123345];	

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (b[a[i]]==0) z++;
		b[a[i]]++;
	
		if (z==m) {y=i;break;}
	}
	if (z<m) {cout<<"-1 -1"; return 0;}
	for (int i = 1; i <= n; i++){
		b[a[i]]--;
		if (b[a[i]]==0) {cout<< i << " " << y; return 0; }

	}
		
	
	




}