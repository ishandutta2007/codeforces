#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 1000005;
typedef long long lint;

string a, b[105];
int n;

int main(){
	cin >> a >> n;
	for(int i=0; i<n; i++){
		cin >> b[i];
		if(b[i] == a){
			cout << "YES";
			return 0;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(b[i][1] == a[0] && b[j][0] == a[1]){
				cout << "YES";
				return 0;
			}

		}
	}
	cout << "NO";
}