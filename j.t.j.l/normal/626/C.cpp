#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const ll INF = (1LL) << 60;

int main(){
	int n, m;
	cin>>n>>m;
	int p = 0, q = 0, r = 0;
	int i = 1;
	for(i = 1; p + q + r < n + m; i++){
		if (i % 6 == 0)
			r++;
		else{
			if (i % 2 == 0 && p < n)
				p++;
			if (i % 3 == 0 && q < m)
				q++;
		}
	}
	cout<<i - 1<<endl;
	return 0;
}