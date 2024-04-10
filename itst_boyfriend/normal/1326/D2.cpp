#include<bits/stdc++.h>
using namespace std;

const int _ = 2e6 + 7;
vector < int > idl[_] , idr[_];
bool valid[_]; int len[_] , mxl[_] , mxr[_];
string str; int t , mx , id1 , id2;

void Manacher(){
	int L = str.size(); memset(len , 0 , sizeof(int) * (2 * L + 1));
	for(int i = 1 ; i <= L ; ++i){idl[i].clear(); idr[i].clear();}
	int mx = 1 , id = 1; static char tmp[_];
	for(int i = 0 ; i < str.size() ; ++i) tmp[2 * i + 1] = str[i];
	for(int i = 1 ; i <= 2 * L - 1 ; ++i){
		if(mx > i) len[i] = min(len[2 * id - i] , mx - i);
		while(i - len[i] >= 0 && i + len[i] <= 2 * L && tmp[i - len[i]] == tmp[i + len[i]]) ++len[i];
		int l = ((i - len[i] + 1) >> 1) + 1 , r = (i + len[i] - 1) >> 1;
		if(l <= r){idl[l].push_back(i); idr[r].push_back(i);}
		if(mx < i + len[i]){mx = i + len[i]; id = i;}
	}
	mx = 0;
	for(int i = 1 ; i <= L ; ++i){
		for(auto t : idl[i]) if(t <= L) mx = max(mx , t);
		mxl[i] = ((mx - (2 * i - 1)) * 2 + 1 + 1) / 2;
	}
	int mn = 2 * L + 1;
	for(int i = L ; i ; --i){
		for(auto t : idr[i]) if(t >= L) mn = min(mn , t);
		mxr[i] = ((2 * i - 1 - mn) * 2 + 1 + 1) / 2;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> t ; t ; --t){
		cin >> str; mx = 0; Manacher(); valid[0] = 1;
		for(int i = 1 ; i <= str.size() ; ++i) valid[i] = valid[i - 1] && str[i - 1] == str[str.size() - i];
		int ans = 0 , L = str.size();
		for(int i = 0 ; valid[i] && i * 2 <= str.size() ; ++i){
			if(mxl[i + 1] + 2 * i > ans){
				ans = mxl[i + 1] + 2 * i; id1 = i + mxl[i + 1]; id2 = i;
			}
			if(mxr[L - i] + 2 * i > ans){
				ans = mxr[L - i] + 2 * i; id1 = i; id2 = i + mxr[L - i];
			}
		}
		cout << string(str , 0 , id1) + string(str , str.size() - id2 , id2) << endl;
	}
	return 0;
}