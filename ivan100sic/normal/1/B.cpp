#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool tip(string s) {
    int c = 0;
    for (int i=0; i<(int)s.size() - 1; i++) {
        if (isdigit(s[i]) != isdigit(s[i+1]))
            c++;
    }
    return c == 1;
}

int pw(int x, int y) {
	int z = 1;
	while (y--)
		z *= x;
	return z;
}

int convert(string s) {
    int z = 0;
	for (int i=1; i<(int)s.size(); i++) {
		z += pw(26, i);
	}
	int w = 0;
    for (char x : s) {
        w = 26 * w + x - 'A';
    }
    return w + z + 1;
}

string convert_back(int x) {
	x--;
    string p;
    int w = 26, j = 1;
    for (int i=1; i<=8; i++) {
    	if (x < w) {
    		j = i;
    		break;
    	} else {
    		x -= w;
    		w *= 26;
    	}
    }

    while (j > 0) {
        p += (char)(x % 26 + 'A');
        x /= 26;
        j--;
    }
    reverse(p.begin(), p.end());
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        if (tip(s)) {
            int y = 0;
            while (!isdigit(s[y]))
                y++;
            int x = convert(s.substr(0, y));
            int z = stoi(s.substr(y));
            cout << "R" << z << "C" << x << '\n';
        } else {
        	int i = s.find('R');
        	int j = s.find('C');
        	int x = stoi(s.substr(i+1, j-i-1));
        	int y = stoi(s.substr(j+1));
        	cout << convert_back(y) << x << '\n';
        }
    }
}