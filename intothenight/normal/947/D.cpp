#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s, t;
	cin >> s >> t;
	int n = (int)s.size(), m = (int)t.size();
	vector<int> sa(n), ta(m), spref(n + 1), tpref(m + 1);
	sa[0] = s[0] == 'A';
	ta[0] = t[0] == 'A';
	for(auto i = 1; i < n; ++ i){
		if(s[i] == 'A'){
			sa[i] = sa[i - 1] + 1;
		}
	}
	for(auto i = 1; i < m; ++ i){
		if(t[i] == 'A'){
			ta[i] = ta[i - 1] + 1;
		}
	}
	for(auto i = 0; i < n; ++ i){
		spref[i + 1] = spref[i] + (s[i] != 'A');
	}
	for(auto i = 0; i < m; ++ i){
		tpref[i + 1] = tpref[i] + (t[i] != 'A');
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int sl, sr, tl, tr;
		cin >> sl >> sr >> tl >> tr, -- sl, -- tl;
		int strail = min(sr - sl, sa[sr - 1]), ttrail = min(tr - tl, ta[tr - 1]);
		if(strail < ttrail){
			cout << 0;
		}
		else{
			int add = 0;
			if(strail % 3 != ttrail % 3){
				add = 2;
			}
			sr -= strail, tr -= ttrail;
			int scnt = spref[sr] - spref[sl], tcnt = tpref[tr] - tpref[tl]; 
			cout << (scnt + add == tcnt || (scnt + add < tcnt && scnt + add + (strail != ttrail) && scnt % 2 == tcnt % 2));
		}
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////