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
	vector<int> v;
	int a,prev=0;
	int ans=0;
	bool first = true;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a==1){
			if(prev==0){
				ans += (first ? 1 : 2);
				first = false;
			}else{
				ans++;
			}
		}
		prev = a;
	}
	cout << ans;
}