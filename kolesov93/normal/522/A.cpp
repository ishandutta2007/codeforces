#include <iostream>
#include <map>
#include <string>

using namespace std;

void canonize(string& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] += 'a' - 'A';
        }
    }
}

map<string, int> f;

int main() {
    int n;
    cin >> n;

    f["polycarp"] = 1;
    int ans = 1;
    while (n--) {
        string a, b, c;
        cin >> a >> b >> c;
        canonize(a);
        canonize(b);
        canonize(c);

        f[a] = f[c] + 1;
        ans = max(ans, f[a]);
    }

    cout << ans << endl;

    return 0;
}