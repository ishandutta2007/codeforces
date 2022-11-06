#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	int ab,ac,bc;
	int xy,xz,yz;
	cout << "or 1 2" << endl;
	cin >> ab;
	cout << "or 1 3" << endl;
	cin >> ac;
	cout << "or 2 3" << endl;
	cin >> bc;
	cout << "and 1 2" << endl;
	cin >> xy;
	cout << "and 1 3" << endl;
	cin >> xz;
	cout << "and 2 3" << endl;
	cin >> yz;
	int a = 0; int b = 0; int c = 0;
	for(int i = 0; i<31; i++){
		bool apair = false;
		if(xy&(1<<i)){
			a|=(1<<i);
			b|=(1<<i);
			apair = true;
		}
		if(xz&(1<<i)){
			a|=(1<<i);
			c|=(1<<i);
			apair = true;
		}
		if(yz&(1<<i)){
			b|=(1<<i);
			c|=(1<<i);
			apair = true;
		}
		if(!apair){
			if(!(ab&(1<<i))&&!(ac&(1<<i))){
				continue;
			}
			if(!(ab&(1<<i))){
				c|=(1<<i);
			}
			else if(!(ac&(1<<i))){
				b|=(1<<i);
			}
			else{
				a|=(1<<i);
			}
		}
	}
	vector<int>arr;
	arr.push_back(a); arr.push_back(b); arr.push_back(c);
	for(int i = 4; i<=n; i++){
		int or1; int and1;
		cout << "or 1 " << i << endl;
		cin >> or1;
		cout << "and 1 " << i << endl;
		cin >> and1;
		int v = 0;
		for(int j = 0; j<31; j++){
			if(and1&(1<<j)){
				v|=(1<<j);
			}
			else if(or1&(1<<j)){
				if(!(a&(1<<j))){
					v|=(1<<j);
				}
			}
		}
		arr.push_back(v);
	}
	sort(arr.begin(),arr.end());
	cout << "finish " << arr[k-1] << endl;
	return 0;
}