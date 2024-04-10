#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __int128 big;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
void solve() {
	int n,x,y;
	cin>>n>>x>>y;
	if (x<y){
		swap(x,y);
	}
	if (y==0){
		if (x==0){
			cout<<"-1\n";
			return;
		}
		if ((n-1)%x==0){
			int last = 1;
			int cnt = 1;
			cout<<1<<' ';
			for(int i = 3;i<=n;i+=1){
				if (cnt==x){
					cout<<i<<' ';
					cnt = 1;
					last = i;
				}
				else{
					cnt += 1;
					cout<<last<<' ';
				}
			}
			cout<<endl;
		}
		else{
			cout<<"-1\n";
			return;
		}
	}
	else{
		cout<<"-1\n";
		return;
	}

}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
	    solve();
    }
}