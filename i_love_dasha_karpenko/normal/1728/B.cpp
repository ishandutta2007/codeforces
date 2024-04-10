#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
void solve() {
	int n;
	cin>>n;
	vector<int> ans;
	int bot = 0;
	int target = n*2-1;
	while(n){
		if (n==1){
			ans.push_back(1+bot);
			break;
		}
		else if (n==2){
			ans.push_back(2+bot);
			ans.push_back(1+bot);
			break;
		}
		else if (n==3){
			ans.push_back(3+bot);
			ans.push_back(1+bot);
			ans.push_back(2+bot);
			break;
		}
		ans.push_back(n+bot);
		ans.push_back(n-1+bot);
		ans.push_back(1+bot);
		n -= 3;
		bot += 1;
	}
	reverse(ans.begin(),ans.end());
	int x = 0;
	for(int to:ans){
		cout<<to<<' ';
		if (x<to){
			x += to;
		}
		else{
			x = 0;
		}
	}
	cout<<endl;
//	cout<<"GDB "<<x<<endl;
	assert(x==target);
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}