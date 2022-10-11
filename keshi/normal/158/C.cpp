#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;


#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, l;
string s;
vector<string> ans;

int main(){
	fast_io;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s == "pwd"){
			cout << "/";
			for(int j = 0; j < ans.size(); j++){
				cout << ans[j] << "/";
			}
			cout << endl;
		}
		else{
			cin >> s;
			s += '/';
			
			if(s[0] == '/'){
				ans.clear();
			}
			
			l = -1;
			for(int j = 0; j < s.size(); j++){
				if(s[j] == '/'){
					if(j != l + 1){
						if(s[l + 1] == '.'){
							if(!ans.empty()){
								ans.pop_back();
							}
						}
						else{
							//cout << "## " << l + 1 << " " << j - 1 << " " << s.substr(l + 1, j - l - 1) << endl;
							ans.push_back(s.substr(l + 1, j - l - 1));
						}
					}
					l = j;
				}
			}
		}
	}
	
	return 0;
	
}