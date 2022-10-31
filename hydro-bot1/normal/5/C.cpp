// Hydro submission #621f2c6678544c65a9b96421@1646210150130
#include<bits/stdc++.h>

using namespace std;


int vis[1001000];

void slove(){
	string s; cin >> s;
	stack<int> st, num;
	map<int, int> mp;
	// cout << s.size() << '\n';
	for(int i = 0; i <(int) s.size(); i++){
		if(s[i] == ')'){
			if(!st.empty() && st.top() == '('){
				vis[num.top()] = 1;
				vis[i] = 1;
				st.pop();
				num.pop();
			} 
		} else {
			st.push(s[i]);
			num.push(i);
		}
	    //	cout << cnt << '\n';
	}
	int maxn = 0, p = 0, cnt = 0;
	for(int i = 0; i <= (int) s.size(); i++){
		if(vis[i] == 1) cnt++;
		else {
			if(cnt == 0) continue;
			if(cnt > maxn){
				maxn = cnt;
				p = 1;
			}
			else if(cnt == maxn){
				p++;
			}
			cnt = 0;
		}
	}
	if(maxn == 0) cout << 0 << ' ' << 1 << '\n';
	 else cout << maxn << ' ' << p << '\n';
}


int main(){
	slove();


}