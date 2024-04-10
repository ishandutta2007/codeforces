#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int a, int b, int c){
	cout << "? " << a << " " << b << " " << c << endl;
	int x;
	cin >> x;
	return x;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		for(int i = 3; i<=n; i+=3){
			arr[i] = f(i-2,i-1,i);
		}
		int idx0 = 0; int idx1 = 0;
		for(int i = 3; i<=n; i+=3){
			if(arr[i]==0){
				idx0 = i;
			}
			if(arr[i]==1){
				idx1 = i;
			}
		}
		vector<int>idx;
		idx.push_back(idx0-2);
		idx.push_back(idx0-1);
		idx.push_back(idx0);
		idx.push_back(idx1-2);
		idx.push_back(idx1-1);
		idx.push_back(idx1);
		int i0 = 0; int i1 = 0;
		for(int i = 3; i<6; i++){
			int v = f(idx[i-2],idx[i-1],idx[i]);
			if(v==1){
				i0 = idx[i-3]; i1 = idx[i];
				break;
			}
		}
		vector<int>ans(n+1);
		ans[i1] = 1;
		for(int i = 3; i<=n; i+=3){
			if(i-2==i0||i-1==i0||i==i0){
				for(int j = i-2; j<=i; j++){
					if(j==i0)continue;
					int v = f(j,i0,i1);
					if(v==1){
						ans[j] = 1;
					}
				}
				continue;
			}
			if(i-2==i1||i-1==i1||i==i1){
				for(int j = i-2; j<=i; j++){
					if(j==i1)continue;
					int v = f(j,i0,i1);
					if(v==1){
						ans[j] = 1;
					}
				}
				continue;
			}
			if(arr[i]==0){
				int v = f(i-2,i-1,i1);
				if(v==1){
					int v2 = f(i-2,i,i1);
					if(v2==1){
						ans[i-2] = 1;
					}
					else{
						ans[i-1] = 1;
					}
				}
				else{
					int v2 = f(i-2,i,i1);
					if(v2==1)
						ans[i] = 1;
				}
			}
			else{
				int v = f(i-2,i-1,i0);
				if(v==0){
					int v2 = f(i-2,i,i0);
					if(v2==0){
						ans[i-1] = ans[i] = 1;
					}
					else{
						ans[i-2] = ans[i] = 1;
					}
				}
				else{
					int v2 = f(i-2,i,i0);
					if(v2==1){
						ans[i] = 1;
					}
					ans[i-2] = ans[i-1] = 1;
				}
			}
		}
		cout << "! " << count(ans.begin(),ans.end(),0)-1 << " ";
		vector<int>vec;
		for(int i = 1; i<=n; i++){
			if(ans[i]==0){
				vec.push_back(i);
			}
		}
		for(int i = 0; i<vec.size(); i++){
			cout << vec[i];
			if(i+1<vec.size())cout << " ";
		}
		cout << endl;
	}
	return 0;
}