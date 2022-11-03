#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string> a(n), b(n);
	for(int i =0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	vector<bool> can(n, 1);
	bool is = 1;
	map<string, int> used;
	for(int i =0; i < n; i++){
		for(int j =i + 1; j < n; j++){
			if(a[i][0] == a[j][0] && a[i][1] == a[j][1] && a[i][2] == a[j][2]){
				can[i] =0;
				can[j] =0;
				string res =""; 
				res+= (a[i][0]);
					res += a[i][1];
					res += b[i][0];
				if(used[res] != i + 1 && used[res])
					is =0;
				used[res] = i + 1;
				res = "";
				res+= (a[j][0]);
					res += a[j][1];
					res += b[j][0];
				if(used[res] != j + 1 && used[res])
					is =0;
				used[res] = j + 1;
			}
		}
	}
	for(int val = 0; val < n + 1; val++){
		for(int i =0; i < n; i++){
			if(can[i]){
				string res =""; 
				res+= (a[i][0]);
					res += a[i][1];
					res += a[i][2];
				if(used[res] && used[res] != i + 1){
					can[i] =0;
					res = "";
					res+= (a[i][0]);
					res += a[i][1];
					res += b[i][0];
					if(used[res]&& used[res] != i + 1){
						is =0;
					}
					used[res] = i + 1;
				}
			}
		}
	}
	if(!is){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i =0; i < n; i++){
		if(can[i]){
			cout << a[i][0] << a[i][1] << a[i][2] << '\n';
		}
		else{
			cout << a[i][0] << a[i][1] << b[i][0] << '\n';
		}
	}
	return 0;
}