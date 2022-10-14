#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
int n, m;
alignas(32) int a[1<<17], tmp[8];

#include<immintrin.h>
using reg = __m256i;
namespace fastio {

const int buf_size = 1 << 14;
char buf_read[buf_size];
char buf_write[buf_size + 30];
char *ptr_read = buf_read + buf_size;
char *ptr_write = buf_write;

int read_int() {
    auto getChar = []() {
        if (ptr_read == buf_read + buf_size){
            fread(buf_read, 1, buf_size, stdin);
            ptr_read = buf_read;
        }
        return *ptr_read++;
    };
    char c = getChar();
    while (c && (c < '0' || c > '9')) {
        c = getChar();
    }
    int res = 0;
    while (c >= '0' && c <= '9'){
        res = res * 10 + (c - '0');
        c = getChar();
    }
    return res;
}

void write_flush() {
    fwrite(buf_write, 1, ptr_write - buf_write, stdout);
    ptr_write = buf_write;
}

void write_int(int x) {
    if (x < 0) {
        *ptr_write++ = '-';
        x = -x;
    }
    char *start = ptr_write;
    if (!x) {
        *ptr_write++ = '0';
    }
    while (x) {
        *ptr_write++ = x % 10 + '0';
        x /= 10;
    }
    reverse(start, ptr_write);
    if (ptr_write >= buf_write + buf_size) {
        write_flush();
    }
}

void write_char(char c) {
    *ptr_write++ = c;
    if (ptr_write >= buf_write + buf_size) {
        write_flush();
    }
}

}
using namespace fastio;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	n = read_int(), m = read_int();
	for(int i = 0; i < n; i++) a[i] = read_int();
	reg ar, s, X;
	for(int t, l, r, x, i = 0; i < m; i++) {
		t = read_int(), l = read_int()-1, r = read_int(), x = read_int();
		X = _mm256_set1_epi32(x);
		if(t == 1) {
			for(; l < r && (l&7); l++) {
				a[l] = a[l] > x ? a[l]-x : a[l];
			}
			for(; l+7 < r; l+=8) {
				ar = _mm256_load_si256((reg*)&a[l]);
				//a[l] = a[l] > x ? a[l]-x : a[l];
				s = _mm256_cmpgt_epi32(ar, X);
				s = _mm256_and_si256(s, X);
				ar = _mm256_sub_epi32(ar, s);
				_mm256_store_si256((reg*)&a[l], ar);
			}
			for(; l < r; l++) {
				a[l] = a[l] > x ? a[l]-x : a[l];
			}
		} else {
			int res = 0;
			for(; l < r && (l&7); l++) {
				res -= a[l] == x;
			}
			s = _mm256_set1_epi32(0);
			for(; l+7 < r; l+=8) {
				ar = _mm256_load_si256((reg*)&a[l]);
				s = _mm256_add_epi32(s, _mm256_cmpeq_epi32(ar, X));
			}
			for(; l < r; l++) {
				res -= a[l] == x;
			}
			_mm256_store_si256((reg*)&tmp, s);
			for(int i = 0; i < 8; i++) res += tmp[i];
			write_int(-res); write_char('\n');
		}
	}
	write_flush();
}