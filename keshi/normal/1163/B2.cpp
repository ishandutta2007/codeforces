#include <bits/stdc++.h>
using namespace std;

int cnt[100100];
map <int, int> c;
int n, ans, a;
map<int, int>::iterator it, ir;

bool check(){
	
	if (c.size() > 2){
		return 0;
	}
	
	it = c.begin();
	ir = c.end();
	ir--;
	
	
	//cout << "S" << endl << " ## " << it->first << " => " << it->second << endl<< " ## " << ir->first << " => " << ir->second << endl;
	
	if (it->first == 1 && it->second == 1){
		return 1;
	}
	if (c.size() == 1){
		if (it->first == 1 || it->second == 1){
			return 1;
		}
		return 0;
	}
	if(it->first + 1 != ir->first){
		return 0;
	}
	if(ir->second == 1){
		return 1;
	}
	
	
	return 0;
}



int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		if(cnt[a]){
			c[cnt[a]]--;
			if (c[cnt[a]] == 0){
				c.erase(cnt[a]);
			}
		}
		cnt[a]++;
		c[cnt[a]]++;
		if (check()){
			ans = i + 1;
		}
	}
	cout << ans;
}