#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

int main()
{
	int n;
	ll x;
	ll d;
	int ans=0;
	cin >> n >> x;
	char c;
	for(int i=0;i<n;++i){
		c='\n';
		while(c=='\n' || c==' '){
			cin >> c;
		}
		cin >> d;
		if(c=='+'){
			x += d;
		}else{
			if(x<d){
				ans++;
			}else{
				x -= d;
			}
		}
	}
	cout << x << " " << ans;
}