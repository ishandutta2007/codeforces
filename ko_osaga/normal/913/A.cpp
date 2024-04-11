#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

int main(){
	int n, m;
	cin>>n>>m;
	if(n >= 30) cout << m;
	else cout << m % (1 << n);
}