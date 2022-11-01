#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
void greedy(int left, int right, string& s, int& cnt, int& ans){
    for(int i = left; i <= right; i++){
        if(s[i] == '('){
            cnt++;
        }else if(cnt > 0){
            cnt --;
            ans ++;
        }
    }
}

int main(){
    string s;
    while(cin >> s){
        int n = s.size();
        const int L = min(n, 1000); // length
        const int B = (n - 1) / L + 1; // block
        vector<int> min_sum(B);
        vector<int> rest(B);
        vector<int> min_out(B);

        for(int i = 0; i < B; i++){
            int cnt = 0;
            for(int j = i * L; j < (i + 1) * L && j < n; j++){
                if(s[j] == '('){
                    cnt++;
                }else if(cnt > 0){
                    cnt --;
                    min_sum[i] ++;
                }else {
                    rest[i] ++;
                }
            }
            min_out[i] = cnt;
        }

        int m; cin >> m;
        for(int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            l--; r--;
            //printf("l:%d\nr:%d\n", l, r);
            int lb = l / L;
            int rb = r / L;
            //printf("lb:%d\nrb:%d\n", lb, rb);
            int cnt = 0;
            int ans = 0;
            if(lb == rb){
                greedy(l, r, s, cnt, ans);
                cout << 2 * ans << endl;
                continue;
            }
            greedy(l, (lb + 1) * L - 1, s, cnt, ans);
            for(int b = lb + 1; b < rb; b++){
                if(cnt <= rest[b]){
                    ans += min_sum[b] + cnt;
                    cnt = min_out[b];
                }else{
                    ans += min_sum[b] + rest[b];
                    cnt = min_out[b] + (cnt - rest[b]);
                }
            }
            greedy(rb * L, r, s, cnt, ans);
            cout << 2 * ans << endl;
        }
    }
    return 0;
}