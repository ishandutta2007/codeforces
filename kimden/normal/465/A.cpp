#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 100002;
const int mod = 1000000007;


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i;
	for(i=0;i<n;i++){
		if(s[i]!='1'){
			break;
		}
	}
	if(i==n){
		cout << n;
	}else{
		cout << i+1;
	}
}