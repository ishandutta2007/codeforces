#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 0;

int n;

int main () {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

	int ttt;
    cin >> ttt;
	while (ttt--) {
        //cout <<"-----------------\n";
        cin >> n;
        string s;
        cin >> s;
        int w1 = 0, w2 = 0;
        char x = '1', nx = '0';

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() and s[i-1] == x) {
                w1++;
            }
            if (i == s.size())
                break;

            //cout << s[i] << " " << x << endl;

            if ((s[i] == nx and s[i+1] == nx)) {
                w1++;
                //cout << "zliczam\n";
            }

            if (x == '1') {
                x = '0';
                nx = '1';
            }
            else {
                x = '1';
                nx = '0';
            }
        }

        //cout << "+++\n";
        x = '0';
        nx = '1';
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() and s[i-1] == x) {
                w2++;
            }
            if (i == s.size())
                break;

            //cout << s[i] << " " << x << endl;

            if ((s[i] == nx and s[i+1] == nx)) {
                w2++;
                //cout << "zliczam\n";
            }

            if (x == '1') {
                x = '0';
                nx = '1';
            }
            else {
                x = '1';
                nx = '0';
            }
        }

        cout << min(w1, w2) << "\n";

	}
	return 0;
}