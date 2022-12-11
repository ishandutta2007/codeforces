#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct word
{
    vector<string> v;
};

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int k;
    cin >> k;

    string text;
    getline(cin, text);
    getline(cin, text);

    vector<word> words;
    int ptr = 0;
    while (ptr < sz(text)) {
        int f = sz(text);
        for (int i = ptr + 1; i < sz(text); ++i) {
            if (text[i] == ' ') {
                f = i;
                break;
            }
        }
        --f;
        word w;
        string curr = "";
        for (int i = ptr; i <= f; ++i) {
            if (text[i] == '-') {
                w.v.pb(curr);
                curr = "";
            } else {
                curr += text[i];
            }
        }
        w.v.pb(curr);
        words.pb(w);
        ptr = f + 2;
    }

    /*for (word& w : words) {
        for (string& s : w.v) {
            cout << s << " ";
        }
        cout << "\n";
    }*/

    int lf = -1, rg = int(1e9);
    //int lf = 9, rg = 11;

    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        int cnt = 1;
        int occ = 0;

        for (int i = 0; i < sz(words) && cnt <= k; ++i) {
            word& w = words[i];
            if (occ + sz(w.v[0]) + (sz(w.v) > 1) > md) {
                occ = 0;
                ++cnt;
            }
            int sum = 0;
            for (int j = 0; j < sz(w.v); ++j) {
                sum += sz(w.v[j]) + (j != sz(w.v) - 1);
            }
            if (occ + sum + (i != sz(words) - 1) <= md) {
                occ += sum + (i != sz(words) - 1);
                continue;
            }
            int ptr = 0;
            while (ptr < sz(w.v) && cnt <= k) {
                sum = 0;
                int poss = -1;
                for (int j = ptr; j < sz(w.v); ++j) {
                    int d = sz(w.v[j]) + (i != sz(words) - 1 || j != sz(w.v) - 1);
                    if (occ + sum + d <= md) {
                        sum += d;
                        poss = j;
                    } else {
                        break;
                    }
                }
                if (poss == -1) {
                    occ = 0;
                    ++cnt;
                    continue;
                }
                occ += sum;
                //cout << "!" << poss << "\n";
                ptr = poss + 1;
            }

            //cout << i << " " << cnt << " " << occ << "\n";
        }

        if (cnt <= k) {
            rg = md;
        } else {
            lf = md;
        }
    }

    cout << rg << "\n";

}