#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main(){
    int n, k, x;
    cin >> n >> k;
    vector <pair <int, int> > arr;
    map <int, int> ans, m;
    for (int i = 0; i < n; ++i){
        cin >> x;
        m[i] = x;
        arr.push_back({x, -1});
    }
    for (int i = 0; i < n; ++i){
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    vector <int> q;
    q.push_back(arr[0].first);
    ans[arr[0].first] = arr[0].second;
    q.pop_back();
    for (int i = 1; i < n; ++i){
        q.push_back(arr[i - 1].second);
        int cnt = arr[i].second;
        sort(q.begin(), q.end());
        reverse(q.begin(), q.end());
        // cout << q.size() << endl;
        if (q.size() > k){
            q.pop_back();
        }
        for (int j = 0; j < q.size(); ++j){
            int elem = q[j];
            cnt += elem;
        }
        ans[arr[i].first] = cnt;
    }
    for (int i = 0; i < n; ++i){
        cout << ans[m[i]] << " ";
    }
    return 0;
}