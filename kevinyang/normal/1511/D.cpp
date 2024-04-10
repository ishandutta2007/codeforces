#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	string s;
	int cnt = 0;
	while(true){
		for(int i = 0; i<k; i++){
			if(cnt==n)break;
			s+=(char)(i+'a');
			cnt++;
			for(int j = i+1; j<k; j++){
				if(cnt==n)break;
				s+=(char)(i+'a');
				cnt++;
				if(cnt==n)break;
				s+=(char)(j+'a');
				cnt++;
			}
			if(cnt==n)break;
		}
		if(cnt==n)break;
	}
	
	cout << s << "\n";
	return 0;
}