#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n;
string s[100005][2];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s[i][0] >> s[i][1];
		if(s[i][0] > s[i][1]) swap(s[i][0], s[i][1]);
	}
	int k;
	cin >> k;
	string w = s[k-1][0];
	for(int i=1; i<n; i++){
		scanf("%d",&k);
		if(s[k-1][0] > w) w = s[k-1][0];
		else if(s[k-1][1] > w) w = s[k-1][1];
		else{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}