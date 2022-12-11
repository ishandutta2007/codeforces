#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
int main() {
	int _; read(_);
	while (_--) {
		int A, B, C, D;
		read(A), read(B), read(C), read(D);
		if ((A + B) & 1) {
			if (B + C == 0) {
				printf("Ya Tidak ");
			} else if (A + D == 0) {
				printf("Tidak Ya ");
			} else {
				printf("Ya Ya ");
			}
			printf("Tidak Tidak\n");
		} else {
			printf("Tidak Tidak ");
			if (B + C == 0) {
				printf("Tidak Ya\n");
			} else if (A + D == 0) {
				printf("Ya Tidak\n");
			} else {
				printf("Ya Ya\n");
			}
		}
	}
	return 0;
}