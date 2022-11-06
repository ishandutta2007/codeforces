#include <iostream>

using namespace std;

int length(string s1, string s2){
    int m = 0;
    for (int i = 0; i < 6; i++) {
        if (s1[i] != s2[i]) {
            m++;
        }
    }
    return m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, m = 13;
    string s[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < i; j++) {
            m = min(m, length(s[i], s[j]));
        }
    }
    cout << (m - 1) / 2 << '\n';
	return 0;
}