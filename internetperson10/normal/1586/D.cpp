#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> que;
vector<int> ans;

int ask() {
    cout << "? ";
    for(int i = 0; i < que.size(); i++) cout << que[i] << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    que.resize(n);
    ans.resize(n);
    que[n-1] = n;
    int le = n; 
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-1; j++) que[j] = i;
        int x = ask();
        if(x) {
            le = min(le, i);
            ans[x-1] = n - (i - le);
        }
    }
    que[n-1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < n-1; j++) que[j] = i;
        int x = ask();
        if(x) {
            ans[x-1] = le - i + 1;
        }
    }
    ans[n-1] = le;
    cout << "! ";
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}