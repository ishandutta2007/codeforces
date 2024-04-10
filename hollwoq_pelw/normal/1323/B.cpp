#include<bits/stdc++.h>

using namespace std;

int main()  {
    int n;  cin >> n;
    int m;  cin >> m;
    int k;  cin >> k;

    vector<int> row;
    vector<int> col;

    for(int i = 0 ; i < n ; ++i)    {
        int x;  cin >> x;
        if (x)  row.push_back(i);
    }
    for(int j = 0 ; j < m ; ++j)    {
        int x;  cin >> x;
        if (x)  col.push_back(j);
    }
    long long ans = 0;
    auto cal = [&](int R,int C) {
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i = R - 1 ; i < row.size() ; ++i)  if (row[i - R + 1] == row[i] - R + 1)   cnt0++;
        for(int i = C - 1 ; i < col.size() ; ++i)  if (col[i - C + 1] == col[i] - C + 1)   cnt1++;

        ans += 1ll * cnt0 * cnt1;
    };

    for(int i = 1 ; i * i <= k ; ++i){
        if (k % i == 0) {
            cal(i,k / i);
            if (i * i < k)cal(k / i,i);
        }
    }
    cout << ans << endl;
}