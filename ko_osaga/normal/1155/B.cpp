#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e6 + 3;
const int MAXN = 300005;

int n;
string s;
int main(){
	cin >> n >> s;
	int turn = (n - 11) / 2;
	if(count(s.begin(), s.end(), '8') <= turn){
		cout << "NO";
		return 0;
	}
	for(int i=0; i<s.size(); i++){
		if(s[i] == '8'){
			turn--;
			if(turn < 0){
				if(i <= n - 11){
					cout << "YES" << endl;
				}
				else cout << "NO" <<endl;
				return 0;
			}
		}
	}
}