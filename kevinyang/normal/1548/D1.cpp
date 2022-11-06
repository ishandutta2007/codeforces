#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	pair<int,int> arr[n];
	for(int i = 0; i<n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	vector<vector<int>>freq(2,vector<int>(2));
	for(int i = 0; i<n; i++){
		freq[arr[i].first/2%2][arr[i].second/2%2]++;
	}
	int ans = 0;
	for(int a = 0; a<2; a++){
		for(int b = 0; b<2; b++){
			if(!freq[a][b])continue;
			int s1 = freq[a][b];
			freq[a][b]--;
			for(int c = 0; c<2; c++){
				for(int d = 0; d<2; d++){
					if(!freq[c][d])continue;
					int s2 = freq[c][d];
					freq[c][d]--;
					for(int e = 0; e<2; e++){
						for(int f = 0; f<2; f++){
							if(!freq[e][f])continue;
							int dif = 0;
							if(a!=c&&b!=d)dif^=1;
							if(a!=e&&b!=f)dif^=1;
							if(c!=e&&d!=f)dif^=1;
							if(dif==0){
								ans+=s1*s2*freq[e][f];
							}
						}
					}
					freq[c][d]++;
				}
			}
			freq[a][b]++;
		}
	}
	cout << ans/6 << "\n";
	return 0;
}