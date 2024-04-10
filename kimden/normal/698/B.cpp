#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007



int main()
{
	int n;
	cin >> n;
	int a;
	int last = 0;
	vector<int> par(n,-1);
	for(int i=0;i<n;i++){
		cin >> a;
		a--;
		par[i] = a;
	}
	bool self;
	int ans = 0;
	int x;
	map<int,int> mp;
	vector<char> mkd(n,0);
	int root = -1;
	for(int i=0;i<n;i++){
		if(mkd[i]){
			continue;
		}
		mp.clear();
		x = i;
		mp[x] = 1;
		while(par[x]!=x && par[x]!=-2){
			mkd[x] = 1;
			x = par[x];
			if(mp[x]>0){
				par[x] = -2;
				ans++;
				break;
			}else{
				if(mkd[x]>0){
					break;
				}
				mp[x]++;
			}
		}
		if(mkd[x]==0){
			mkd[x] = 1;
			if(root<0){
				root = x;
			}else{
				if(x!=root){
					par[x] = root;
					ans++;
				}
			}
		}
	}
	if(root<0){
		int u=0;
		while(par[u]!=-2){
			u++;
		}
		par[u] = u;
		root = u;
	}
	cout << ans << "\n";
	for(int i=0;i<n;i++){
		if(i>0){
			cout << " ";
		}
		if(par[i]==-2){
			cout << root+1;
		}else{
			cout << par[i]+1;
		}
	}
}