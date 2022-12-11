#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int cnt[10];
int need[10];

int length(int val)
{
    if (val == 0) {
        return 1;
    }
    int ans = 0;
    while (val) {
        ++ans;
        val /= 10;
    }
    return ans;
}

string conv(int val)
{
    if (val == 0) {
        return "0";
    }
    string ans = "";
    while (val) {
        ans += (char)(val % 10 + '0');
        val /= 10;
    }
    reverse(all(ans));
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if (a == "01" || a == "10") {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < sz(a); ++i) {
        ++cnt[a[i] - '0'];
    }

    int len;
    for (len = 1; ; ++len) {
        if (len + length(len) > sz(a)) {
            --len;
            break;
        }
    }

    string tmp = conv(len);
    for (int i = 0; i < sz(tmp); ++i) {
        --cnt[tmp[i] - '0'];
    }

    for (int i = 0; i < sz(b); ++i) {
        ++need[b[i] - '0'];
    }

    bool profit = false;
    for (int i = 0; i < sz(b) - 1; ++i) {
        if (b[i] > b[i + 1]) {
            profit = false;
            break;
        } else if (b[i] < b[i + 1]) {
            profit = true;
            break;
        }
    }

    string ans = "";
    int pos = 0;
    if (b[0] != '0') {
        ans = b;
        for (int i = 0; i < sz(b); ++i) {
            --cnt[b[i] - '0'];
        }
        for (int i = 0; i < 10; ++i) {
            while (cnt[i]) {
                ans += (char)(i + '0');
                --cnt[i];
            }
        }
    } else {
        int first;
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] - 1 >= need[i]) {
                first = i;
                break;
            }
        }
        ans = (char)(first + '0');
        --cnt[first];
        for (int i = 0; i < sz(b); ++i) {
            ans += b[i];
            --cnt[b[i] - '0'];
        }
        for (int i = 0; i < 10; ++i) {
            while (cnt[i]) {
                ans += (char)(i + '0');
                --cnt[i];
            }
        }
        pos = 1;
    }

    for (int i = pos + sz(b); i < sz(ans); ++i) {
        ++cnt[ans[i] - '0'];
    }

    string t = "";
    if (pos == 1) {
        t += ans[0];
    }

    for (; ; ++pos) {
        int least = -1;
        for (int i = 0; i < 10; ++i) {
            if (pos == 0 && i == 0) {
                continue;
            }
            if (cnt[i]) {
                least = i;
                break;
            }
        }
        if (least == -1) {
            break;
        }
        if (least < b[0] - '0' || (least == b[0] - '0' && profit)) {
            --cnt[least];
            t += (char)(least + '0');
        } else {
            break;
        }
    }

    for (int i = 0; i < sz(b); ++i) {
        t += b[i];
    }
    for (int i = 0; i < 10; ++i) {
        while (cnt[i]) {
            t += (char)(i + '0');
            --cnt[i];
        }
    }

     string ANS = t;
     for (int i = 0; i < sz(t); ++i) {
        ++cnt[t[i] - '0'];
     }
     ans = "";
     t = "";

     {
        int first = -1;
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] - 1 >= need[i]) {
                first = i;
                break;
            }
        }
        if (first == -1) {
            cout << ANS << "\n";
            return 0;
        }
        ans = (char)(first + '0');
        --cnt[first];
        for (int i = 0; i < sz(b); ++i) {
            ans += b[i];
            --cnt[b[i] - '0'];
        }
        for (int i = 0; i < 10; ++i) {
            while (cnt[i]) {
                ans += (char)(i + '0');
                --cnt[i];
            }
        }
        pos = 1;
    }

    for (int i = pos + sz(b); i < sz(ans); ++i) {
        ++cnt[ans[i] - '0'];
    }

    t = "";
    if (pos == 1) {
        t += ans[0];
    }

    for (; ; ++pos) {
        int least = -1;
        for (int i = 0; i < 10; ++i) {
            if (pos == 0 && i == 0) {
                continue;
            }
            if (cnt[i]) {
                least = i;
                break;
            }
        }
        if (least == -1) {
            break;
        }
        if (least < b[0] - '0' || (least == b[0] - '0' && profit)) {
            --cnt[least];
            t += (char)(least + '0');
        } else {
            break;
        }
    }

    for (int i = 0; i < sz(b); ++i) {
        t += b[i];
    }
    for (int i = 0; i < 10; ++i) {
        while (cnt[i]) {
            t += (char)(i + '0');
            --cnt[i];
        }
    }

    ANS = min(ANS, t);
    cout << ANS << "\n";

}