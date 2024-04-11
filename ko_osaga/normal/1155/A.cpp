#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e6 + 3;
const int MAXN = 300005;
int n;
string s;

int main(){
	cin >> n;
	cin >> s;
	if(is_sorted(s.begin(), s.end())){
		cout << "NO";
		return 0;
	}
	for(int i=1; i<s.size(); i++){
		if(s[i-1] > s[i]){
			printf("YES\n%d %d\n", i, i + 1);
			return 0;
		}
	}
}