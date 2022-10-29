#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e3 + 9;

bitset<MAXN> a[MAXN], b[MAXN], c[MAXN];
char s[MAXN];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < m; j++)
			a[i][j] = (s[m-1-j] == 'z');
		b[i].set(), c[i].set();
	}
	long long ans = 0;
	for(int k = 0; k < m && k < n; k++){
		for(int i = 0; i < n; i++)
			b[i] &= a[i] >> k;
		for(int i = 0; i + k < n; i++){
			c[i] &= a[i+k] >> k;
			ans += (b[i] & b[i+k] & c[i]).count();
		}
	}
	cout<<ans<<endl;
	return 0;
}