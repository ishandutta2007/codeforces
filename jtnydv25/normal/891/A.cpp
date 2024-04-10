#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
int A[2005];
int main(){
	int n;
	cin >> n;
	int mn = 1e9;
	int cntone = 0;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		if(A[i] == 1) cntone++;
		int g = 0;
		for(int j = i; j >= 1; j--){
			g = __gcd(g, A[j]);
			if(g == 1){
				mn = min(mn, i - j + n - 1);
			}
		}
	}
	if(mn >= 1e8) mn = -1;
	if(cntone){
		cout << n - cntone;
	}
	else cout << mn ;
}