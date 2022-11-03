#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> names;
    for (int i = 0; i < 26; ++i) {
        char p = 'A' + i;
        char pp = 'a' + i;
        string str;
        names.push_back(str + p);
        str += 'A';
        names.push_back(str + pp);
    }
    int n, k;
    cin >> n >> k;
    int j = 0;
    string str;
    cin >> str;
    vector<string> ans;
    if (str == "YES") {
        for (int i = 0; i < k; ++i) {
            ans.push_back(names[j++]);
        }
    } else {
        ans.push_back(names[0]);
        for (int i = 1; i < k; ++i) {
            ans.push_back(names[j++]);
        }
    }
    for (int i = k; i < n; ++i) {
        string str;
        cin >> str;
        if (str == "YES") {
            ans.push_back(names[j++]);
        } else {
            ans.push_back(ans[i - k + 1]);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}