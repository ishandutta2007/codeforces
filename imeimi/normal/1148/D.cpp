#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n;
vector<int> solve(vector<int> A, vector<int> B, vector<int> I) {
    int n = A.size();
    vector<int> ord;
    for (int i = 0; i < n; ++i) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return B[i] > B[j];
    });
    vector<int> ans;
    for (int i : ord) {
        ans.push_back(I[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> A1, A2, B1, B2, I1, I2;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            A1.push_back(a);
            B1.push_back(b);
            I1.push_back(i);
        }
        else {
            A2.push_back(b);
            B2.push_back(a);
            I2.push_back(i);
        }
    }
    vector<int> ans1 = solve(A1, B1, I1);
    vector<int> ans2 = solve(A2, B2, I2);
    reverse(ans2.begin(), ans2.end());
    if (ans1.size() < ans2.size()) ans1 = ans2;
    printf("%u\n", ans1.size());
    for (int i : ans1) printf("%d ", i);
    return 0;
}