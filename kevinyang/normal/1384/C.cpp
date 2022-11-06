#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		string a;
		string b;
		cin >> n;
		cin >> a;
		cin >> b;
		vector<char>arr(n);
		for(int i = 0; i<n; i++){
			arr[i] = a[i];
		}
		bool works = true;
		for(int i = 0; i<n; i++){
			if((int)a[i]<=(int)b[i]){
				continue;
			}
			else{
				works = false;
			}
		}
		if(!works){
			cout << "-1\n";
			continue;
		}
		int count = 0;
		for(int l = 0; l<20; l++){
			bool need = false;
			for(int i = 0; i<n; i++){
				if(arr[i]==(char)(97+l)&& b[i]!=arr[i]){
					need = true;
					break;
				}
			}
			if(!need){
				continue;
			}
			count++;
			char low = 'z';
			for(int i = 0; i<n; i++){
				if(arr[i]==(char)(97+l)&arr[i]!=b[i]){
					if(b[i]<low){
						low = b[i];
					}
				}
			}
			for(int i = 0; i<n; i++){
				if(arr[i]==(char)(97+l)&&b[i]>=low){
					arr[i] = low;
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}