#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 100002;
const int mod = 1000000007;
const double eps = 1e-8;

int main()
{
	int n;
	cin >> n;
	int a,b;
	int a1=0,b1=0;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		if(a>b){
			a1++;
		}else if(a< b){
			b1++;
		}
	}
	if(a1>b1){
		cout << "Mishka";
	}else{
		if(a1<b1){
			cout << "Chris";
		}else{
			cout << "Friendship is magic!^^";
		}
	}
}