#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __int128 big;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 1e5+7;
int A[N];
void solve() {
	int n,x,y;
	cin>>n>>x>>y;
	for(int i = 1;i<=n;i+=1){
		char ch;
		cin>>ch;
		A[i] = ch=='1';
	}
	for(int i = 1;i<=n;i+=1){
		char ch;
		cin>>ch;
		A[i] ^= int(ch=='1');
	}
	vector<int> ind;
	for(int i = 1;i<=n;i+=1){
		if (A[i]==1){
			ind.push_back(i);
		}
	}
	int sz = ind.size();
	if (sz%2){
		cout<<"-1\n";
	}
	else{
		if (sz==2){
			if (abs(ind[0]-ind[1])>1){
				cout<<y<<endl;
			}
			else{
				if ((abs(n-ind[0])>1 && abs(n-ind[1])>1) || (abs(1-ind[0])>1 && abs(1-ind[1])>1)){
					cout<<min(x,2*y)<<endl;
				}
				else{
					cout<<x<<endl;
				}
			}
		}
		else{
			cout<<ll(sz/2)*y<<endl;
		}
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