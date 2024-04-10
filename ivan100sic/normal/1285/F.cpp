#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// vvv stolen from neal vvv

namespace IO {
    const int BUFFER_SIZE = 1 << 15;
 
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
 
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
 
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
 
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();
 
        return input_buffer[advance ? input_pos++ : input_pos];
    }
 
    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;
 
        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;
 
        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
 
        if (negative)
            number = -number;
    }
 
    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}


// ^^^ stolen from neal ^^^^

const int h = 100000;

int f[h+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=h; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > h) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

ll sol = 0;
int n, c[h+1];

int main() {
	int n;
	IO::read_int(n);
	while (n--) {
		int x;
		IO::read_int(x);
		c[x]++;
		if (c[x] == 2)
			sol = max<ll>(sol, x);
	}
	for (int i=1; i<=h; i++)
		for (int j=i; j<=h; j+=i)
			c[i] |= c[j];

	basic_string<int> v, u;

	for (int j=1; j<=h; j++) {
		if (c[j]) {
			v += j;
		}
	}

	auto w = factor(v.back());
	for (int mask=0; mask<(1<<w.size()); mask++) {
		int q = 1;
		for (int i=0; i<(int)w.size(); i++) {
			if (mask & (1 << i))
				q *= w[i].first;
		}
		int h = 0;
		for (int x : v)
			if (gcd(x, q) == 1)
				h = max(h, x);
		u += h;
	}

	for (int x : v)
		for (int y : u)
			sol = max(sol, x/gcd(x, y)*1ll*y);

	cout << sol << '\n';
}