#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <map>
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,v) memset(a,v,sizeof(a))
#define INF (-1)
#define pb push_back
#define uint unsigned int
#define ll long long
#define ull unigned ll
using namespace std;

uint n;
uint data[105];

int main(){
	//freopen("A.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(uint i = 1;i <= n;i++)	cin >> data[i];
	
	uint maxn = data[1];
	for(uint i = 2;i <= n;i++) maxn = max(data[i],maxn);
	
	uint ans = 0;
	for(uint i = 1;i <= n;i++)
		ans += (maxn - data[i]);
		
	cout << ans << endl;
	
	return 0;
}