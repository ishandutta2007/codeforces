#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >>tst;
    while (tst--) {
        int n;
        cin >>n;
        int64_t w= 0;
        vector<int> arr(n);
        for (int i = 0;i < n; ++i) {
            cin >> arr[i];
            w += arr[i];
        }
        sort(arr.begin(), arr.end());
        multiset<int> st;
        st.insert(w);
        while (!arr.empty() && st.size() <= arr.size()) {
            auto it= st.end();
            it--;
            int k = *it;
            st.erase(it);
            if(k < arr.back()) break;
            if (k == arr.back()) {
                arr.pop_back();
                continue;
            }
            st.insert(k / 2);
            st.insert((k + 1) / 2);
        }
        if (arr.empty()) {
            cout<< "YES"<<endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}