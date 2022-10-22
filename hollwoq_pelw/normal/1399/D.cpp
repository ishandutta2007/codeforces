#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    while(t--){
        int res = 0;
        string s;
        cin >> n >> s;
        stack<int> st[2];
        vector<int> b(n);
        for(int i = 0; i < n; i ++){
            int k = s[i] - '0';
            int p = k ^ 1;
            if(st[p].empty()){
                b[i] = ++res;
                st[k].push(b[i]);
            }
            else{
                b[i] = st[p].top();
                st[p].pop();
                st[k].push(b[i]);
            }
        }
        cout << res << endl;
        for(int i = 0; i < n; i ++)
            cout << b[i] <<" ";
        cout << endl;
    }
}