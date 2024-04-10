#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;

string str; int cnt[3] , T , N;

signed main(){
	for(cin >> T ; T ; --T){
		cin >> N >> cnt[0] >> cnt[1] >> cnt[2] >> str;
		int win = 0; string ans; ans.resize(N);
		for(int i = 0 ; i < str.size() ; ++i)
			if(str[i] == 'R' && cnt[1]){
				ans[i] = 'P'; --cnt[1]; ++win;
			}
			else if(str[i] == 'P' && cnt[2]){
				ans[i] = 'S'; --cnt[2]; ++win;
			}
			else if(str[i] == 'S' && cnt[0]){
				ans[i] = 'R'; --cnt[0]; ++win;
			}
		if(win < (N + 1) / 2) cout << "NO\n";
		else{
			cout << "YES\n";
			for(int i = 0 ; i < N ; ++i)
				if(ans[i]) cout << ans[i];
				else
					if(cnt[0]){cout << 'R'; --cnt[0];}
					else if(cnt[1]){cout << 'P'; --cnt[1];}
					else{cout << 'S'; --cnt[2];}
			cout << endl;
		}
	}
	return 0;
}