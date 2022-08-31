#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n;
char str[1005][10];

void ok(){
	puts("YES");
	for(int i=0; i<n; i++) puts(str[i]);
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> str[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<=3; j+=3){
			if(str[i][j] == str[i][j+1] && str[i][j+1] == 'O'){
				str[i][j] = str[i][j+1] = '+';
				ok();
				return 0;
			}
		}
	}
	puts("NO");
}