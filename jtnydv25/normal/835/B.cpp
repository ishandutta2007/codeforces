#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
int main(){
    int t = 1, n;
    // sd(t);
    while(t--){
        // sd(n);
        string s; int k;
        cin.tie(0);
        cin >> k >> s;
        int n = s.length();
        int sm = 0;
        vector<int> digs;
        for(int i = 0; i < n; i++){
            sm += s[i] - '0';
            digs.pb(s[i] - '0');
        }
        if(sm >= k){
            cout << 0; return 0;
        }
        sort(digs.begin(), digs.end());
        for(int i = 0; i < n; i++){
            if(sm + 9 - digs[i] >= k){
                cout << i + 1;
                return 0;
            }
            sm += 9 - digs[i];
        }
    }
}