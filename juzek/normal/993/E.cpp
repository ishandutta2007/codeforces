#include <cstdio>
#include <complex>
#include <cstring>

#define pi       3.14159265358979323846

const int Z = 1024 * 512;

std::complex<double> x[Z], y[Z], tmp[Z];
std::complex<double> x2[Z], y2[Z];
int tab[Z];
long long odp[Z];

void fft(std::complex<double> *f, int g) {
    for (int i = 0, j = 0; i < Z; ++i) {
        if (i > j) swap(f[i], f[j]);
        for (int k = Z >> 1; (j ^= k) < k; k >>= 1);
    }
    for (int i = 1; i < Z; i <<= 1) {
        std::complex<double> w0 = (std::complex<double>) {cos(pi / i), sin(g * pi / i)};
        for (int j = 0; j < Z; j += i << 1) {
            std::complex<double> w = (std::complex<double>) {1, 0};
            for (int k = j; k < j + i; ++k) {
                std::complex<double> t = w * f[k + i];
                f[k + i] = f[k] - t;
                f[k] = f[k] + t;
                w = w * w0;
            }
        }
    }
//    if (g == -1) for (int i = 0; i < Z; ++i) f[i].real() /= Z;
}

int main() {
    int N, X;
    scanf("%d%d", &N, &X);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        tab[i] = (tab[i] < X);
    }
    int ter = 0;
    int ile = 0;
    for (int i = 1; i <= N; i++) {
        ile++;
        if (tab[i] == 1) {
            odp[0] += (long long) (ile - 1) * (ile) / 2;
            x[ter++] = std::complex<long double>(ile, 0);
            ile = 0;
        }
    }
    odp[0] += (long long) ile * (ile + 1) / 2;
    int jedynki = ter;
    ter = ile = 0;
    for (int i = N; i >= 1; i--) {
        ile++;
        if (tab[i] == 1) {
            x2[ter++] = std::complex<long double>(ile, 0);
            ile = 0;
        }
    }
    fft(x, 1);
    fft(x2, 1);
    for (int i = 0; i < Z; i++)
        x[i] *= x2[i];
    fft(x, -1);
    for (int i = 0; i < jedynki; i++)
        odp[jedynki - i] = (long long) std::round(x[i].real() / Z);
    for (int i = 0; i < N + 1; i++)
        printf("%lld ", odp[i]);
    return 0;
}