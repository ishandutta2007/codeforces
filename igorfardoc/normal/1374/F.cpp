#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi ans;
vi a;

void do1(int i) {
    int temp = a[i];
    a[i] = a[i + 2];
    a[i + 2] = a[i + 1];
    a[i + 1] = temp;
    ans.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        ans.clear();
        int n;
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            if(i == n - 2) {
                break;
            }
            int min1 = 1000;
            int minid = -1;
            for(int j = i; j < n; j++) {
                if(min1 > a[j]) {
                    min1 = a[j];
                    minid = j;
                }
            }
            while(minid - i >= 2) {
                do1(minid - 2);
                minid -= 2;
            }
            if(i == minid) {
                continue;
            }
            do1(i);
            do1(i);
        }
        if(a[n - 2] > a[n - 1]) {
            if(a[n - 1] == a[n - 3]) {
                do1(n - 3);
            } else {
                int pos = -1;
                for(int i = n - 3; i > 0; i--) {
                    if(a[i] == a[i - 1]) {
                        pos = i;
                        break;
                    }
                }
                if(pos == -1) {
                    cout << -1 << '\n';
                    continue;
                }
                int id1 = n - 1;
                if(id1 % 2 == pos % 2) {
                    --id1;
                }
                while(id1 - pos > 1) {
                    do1(id1 - 2);
                    id1 -= 2;
                }
                do1(pos - 1);
                do1(pos - 1);
                --id1;
                while(n - id1 > 2) {
                    do1(id1);
                    do1(id1);
                    id1 += 2;
                }
            }
        }
        cout << ans.size() << '\n';
        for(auto& el : ans) {
            cout << el + 1 << ' ';
        }
        cout << '\n';
    }
}