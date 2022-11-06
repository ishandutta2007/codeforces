#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int k;
	cin >> k;
	string s;
	cin >> s;
	vector<int>hm(s.size());
	vector<int>hm2(s.size());
	for(int i = 0; i<hm.size(); i++){
		hm[i] = hm.size()-1-i;
	}
	if(true){
		int cur = 1;
		while(cur<hm.size()){
			reverse(hm.begin()+cur,hm.begin()+cur*2+1);
			cur = cur*2+1;
		}
	}
	for(int i = 0; i<hm.size(); i++){
		//cout << hm[i] << " ";
		hm2[hm[i]] = i;
	}
	//cout << "\n";
	int mxn = 1<<(k+1);
	vector<int>arr(1<<(k+1));
	if(true){
		for(int i = mxn-1; i>=0; i--){
			if(i>=s.size()){
				arr[i] = 1;
			}
			else{
				if(s[hm[i]]=='1'){
					arr[i] = arr[2*i+2];
				}
				else if(s[hm[i]]=='0'){
					arr[i] = arr[2*i+1];
				}
				else{
					arr[i] = arr[2*i+1]+arr[2*i+2];
				}
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int p;
		cin >> p;
		p--;
		char ch;
		cin >> ch;
		int i = hm2[p];
		s[p] = ch;
		while(i!=0){
			if(s[hm[i]]=='1'){
				arr[i] = arr[2*i+2];
			}
			else if(s[hm[i]]=='0'){
				arr[i] = arr[2*i+1];
			}
			else{
				arr[i] = arr[2*i+1]+arr[2*i+2];
			}
			i--;
			i/=2;
		}
		i = 0;
		if(s[hm[i]]=='1'){
				arr[i] = arr[2*i+2];
			}
			else if(s[hm[i]]=='0'){
				arr[i] = arr[2*i+1];
			}
			else{
				arr[i] = arr[2*i+1]+arr[2*i+2];
			}
		cout << arr[0] << "\n";
	}
	return 0;
}