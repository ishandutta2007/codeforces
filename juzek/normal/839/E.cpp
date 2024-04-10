#include <cstdio>
#include <vector>

int tab[47][47];
std::vector<int> wybrane;
int sr, ter;
int maxi[1 << 21];
int wyn = 0;
int N;

void adam(int a) {
    if (a >= sr) {
        maxi[ter] = (int) wybrane.size();
        return;
    }
    bool moge = true;
    for (auto it : wybrane)
        moge &= tab[it][a];
    if (moge) {
        ter ^= (1 << a);
        wybrane.push_back(a);
        adam(a + 1);
        ter ^= (1 << a);
        wybrane.pop_back();
    }
    adam(a + 1);
}

void adam2(int a) {
    if (a >= N) {
        int moge = (1 << sr) - 1;
        for (int i = 0; i < sr; i++) {
            int wsp = 0;
            for (auto it : wybrane)
                if (!tab[it][i])
                    wsp = (1 << i);
            moge ^= wsp;
        }
        wyn = std::max(wyn, (int) wybrane.size() + maxi[moge]);
        return;
    }
    bool moge = true;
    for (auto it : wybrane)
        moge &= tab[it][a];
    if (moge) {
        wybrane.push_back(a);
        adam2(a + 1);
        wybrane.pop_back();
    }
    adam2(a + 1);
}

int main() {
    int K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        for (int w = 0; w < N; w++)
            scanf("%d", &tab[i][w]);
    sr = N / 2;
    adam(0);
    int kon = 1 << sr;
    for (int i = 0; i < kon; i++)
        for (int w = 0; w < sr; w++)
            if ((i & (1 << w)))
                maxi[i] = std::max(maxi[i], maxi[i ^ (1 << w)]);
    adam2(sr);
    double wsp = double(K) / wyn;
    wsp *= wsp;
    printf("%lf", wsp * wyn * (wyn - 1) / 2);
//    printf("%d", wyn);
    return 0;
}