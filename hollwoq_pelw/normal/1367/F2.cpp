#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n; cin >> t; while(t--){
        cin >> n;
        int N = n + 5;
        int arr[N], dp[N], lst[N], fr[N], bk[N], nxt[N];
        map<int, int> rev;
        vector<int> pos[N];
        set<int> st;
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
            st.insert(arr[i]);
        }
        int cnt = 0;
        for (auto tmp : st){
            rev[tmp] = ++cnt;
        }
        for (int i = 1; i <= n; i++){
            arr[i] = rev[arr[i]];
            pos[arr[i]].push_back(i);
        }
        for (int i = 1; i <= cnt; i++){
            sort(pos[i].begin(), pos[i].end());
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++){
            nxt[i] = fr[i] = bk[i] = dp[i] = 0;
            if (i > 1){
                for (auto v : pos[i-1])
                    if (v < pos[i].front()) fr[i] ++;
            }
            if (i< cnt){
                for (auto v : pos[i+1])
                    if (v > pos[i].back()) bk[i] ++;
            }
            if (i == 1 || pos[i-1].back() >= pos[i].front()){
                lst[i] = i;
                dp[i] = pos[i].size();
            }else{
                lst[i] = lst[i-1];
                dp[i] = dp[i-1] + pos[i].size();
            }
			int p = 0;
			for(int j = 0; j < pos[i].size(); j++){
				while(p < pos[i+1].size() && pos[i+1][p] < pos[i][j]) p++;
				nxt[i] = max(nxt[i], j + 1 + (int) pos[i+1].size() - p);
			}
			ans = max({ans, dp[i] + fr[lst[i]] + bk[i], nxt[i]});
        }
        cout << n - ans << endl;
    }
}