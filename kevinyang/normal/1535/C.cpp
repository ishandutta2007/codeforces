#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		vector<int>psaodd(n+1);//zeroes
		vector<int>psaeven(n+1);
		vector<int>psa2odd(n+1);//ones
		vector<int>psa2even(n+1);
		for(int i = 1; i<=n; i++){
			psaodd[i] = psaodd[i-1]+((i%2==1)&&(s[i-1]=='0'));
			psaeven[i] = psaeven[i-1]+((i%2==0)&&(s[i-1]=='0'));
			psa2odd[i] = psa2odd[i-1]+((i%2==1)&&(s[i-1]=='1'));
			psa2even[i] = psa2even[i-1]+((i%2==0)&&(s[i-1]=='1'));
		}
		int ans = 0;
		for(int i = 1; i<=n; i++){
			int low = -1; int high = i-1; int mid = (low+high)/2;
			while(low+1<high){
				bool f = false;
				int a = psaodd[i]-psaodd[mid];
				int b = psaeven[i]-psaeven[mid];
				int c = psa2odd[i]-psa2odd[mid];
				int d = psa2even[i]-psa2even[mid];
				if((a==0&&d==0)||(b==0&&c==0)){
					f = true;
				}
				if(f){
					high = mid;
				}
				else{
					low = mid;
				}
				mid = (low+high)/2;
			}
			ans+=i-high;
			//cout << i-high << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}