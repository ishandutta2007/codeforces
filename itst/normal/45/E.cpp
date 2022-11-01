#include<bits/stdc++.h>
using namespace std;

string s1[110] , s2[110];
int cnt1[27] , cnt2[27] , n;
bool vis[110];

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> s1[i];
		++cnt1[s1[i][0] - 'A'];
	}
	sort(s1 + 1 , s1 + n + 1);
	for(int i = 1 ; i <= n ; ++i){
		cin >> s2[i];
		++cnt2[s2[i][0] - 'A'];
	}
	sort(s2 + 1 , s2 + n + 1);
	for(int i = 1 ; i <= n ; ++i){
		if(i != 1)
			cout << ", ";
		cout << s1[i] << ' ';
		--cnt1[s1[i][0] - 'A'];
		if(cnt2[s1[i][0] - 'A'] > cnt1[s1[i][0] - 'A']){
			for(int j = 1 ; j <= n ; ++j)
				if(!vis[j] && s2[j][0] == s1[i][0]){
					cout << s2[j];
					vis[j] = 1;
					--cnt2[s2[j][0] - 'A'];
					break;
				}
		}
		else
			for(int j = 1 ; j <= n ; ++j)
				if(!vis[j] && (cnt1[s2[j][0] - 'A'] < cnt2[s2[j][0] - 'A'] || s2[j][0] == s1[i][0])){
					cout << s2[j];
					vis[j] = 1;
					--cnt2[s2[j][0] - 'A'];
					break;
				}
	}
	return 0;
}