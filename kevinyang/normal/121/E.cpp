#include <bits/stdc++.h>
using namespace std;
int sq = 318;

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>lazy(400);
	vector<int>good(10005);
	vector<int>gud;

	vector<int>val(400);
	for(int i = 1; i<=10000; i++){
		bool f = true;
		string s = to_string(i);
		for(char nxt: s){
			if(nxt=='4'||nxt=='7')continue;
			f = false;
		}
		if(f){
			good[i] = 1;
			gud.push_back(i);
		}
	}
	vector<vector<int>>freq(400,vector<int>(10005));
	for(int i = 1; i<=n; i++){
		freq[i/sq][arr[i]]++;
		if(good[arr[i]])val[i/sq]++;
	}
	while(m--){
		string cm;
		cin >> cm;
		if(cm=="add"){
			int l,r,d;
			cin >> l >> r >> d;
			int i = l;
			while(i%sq!=0&&i<=r){
				if(good[arr[i]+lazy[i/sq]])val[i/sq]--;
				freq[i/sq][arr[i]]--;
				arr[i]+=d;
				if(good[arr[i]+lazy[i/sq]])val[i/sq]++;
				freq[i/sq][arr[i]]++;
				i++;
			}
			while(i+sq<=r){
				
				for(int nxt: gud){
					if(nxt-lazy[i/sq]>=0){
						val[i/sq]-=freq[i/sq][nxt-lazy[i/sq]];
					}
				}
				assert(i%sq==0);
				lazy[i/sq]+=d;
				for(int nxt:gud){
					if(nxt-lazy[i/sq]>=0){
						val[i/sq]+=freq[i/sq][nxt-lazy[i/sq]];
					}
				}
				i+=sq;
			}
			while(i<=r){
				if(good[arr[i]+lazy[i/sq]])val[i/sq]--;
				freq[i/sq][arr[i]]--;
				arr[i]+=d;
				if(good[arr[i]+lazy[i/sq]])val[i/sq]++;
				freq[i/sq][arr[i]]++;
				i++;
			}
		}
		else{
			int l,r;
			cin >> l >> r;
			int i = l;
			int cnt = 0;
			while(i%sq!=0&&i<=r){
				if(good[arr[i]+lazy[i/sq]]){
					cnt++;
				}
				i++;
			}
			while(i+sq<=r){
				for(int nxt: gud){
					if(nxt-lazy[i/sq]>=0){
						cnt+=freq[i/sq][nxt-lazy[i/sq]];
					}
				}
				i+=sq;
			}
			while(i<=r){
				if(good[arr[i]+lazy[i/sq]]){
					cnt++;
				}
				i++;
			}
			cout << cnt << "\n";
		}
	}
	return 0;
}