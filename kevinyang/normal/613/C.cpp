#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>freq(26);
	for(int i = 0; i<n; i++){
		cin >> freq[i];
	}
	int v = freq[0];
	for(int i = 0; i<n; i++){
		v = __gcd(v,freq[i]);
	}
	int cntodd = 0;
	for(int i = 0; i<n; i++){
		if(freq[i]%2==1)cntodd++;
	}
	if(cntodd>1){
		cout << "0\n";
		for(int i = 0; i<n; i++){
			for(int j = 0; j<freq[i]; j++){
				cout << (char)('a'+i);
			}
		}
		cout << "\n";
		return 0;
	}
	else if(cntodd==1){
		cout << v << "\n";
		char bad;
		for(int i = 0; i<n; i++){
			if(freq[i]%2==1){
				bad = (char)('a'+i);
				break;
			}
		}
		string s = "";
		for(int i = 0; i<n; i++){
			freq[i]/=v; freq[i]/=2;
			for(int j = 0; j<freq[i]; j++){
				s+=(char)('a'+i);
			}
		}
		string t = s;
		reverse(t.begin(),t.end());
		s+=bad;s+=t;
		string add = s;
		for(int i = 1; i<v; i++){
			s+=add;
		}
		cout << s << "\n";
	}
	else{
		cout << v << "\n";
		string s = "";
		for(int i = 0; i<n; i++){
			freq[i]/=v;
			for(int j = 0; j<freq[i]; j++){
				s+=(char)('a'+i);
			}
		}
		string t = s;
		reverse(t.begin(),t.end());
		s = s+t;
		string add = s;
		for(int i = 1; i<v/2; i++){
			s+=add;
		}
		cout << s << "\n";
	}
	return 0;
}