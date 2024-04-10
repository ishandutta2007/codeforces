#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

enum Probility {
    never, probably, always
};

typedef std::pair<int, int> Situation; // (first living, second living)

const int max_n = 3000;

int n, k;
Probility prob[max_n];
bool searched[max_n][max_n];
bool siglenton_searched[max_n];
bool void_searched;

bool dppm[max_n], dpph[max_n];

void init_dps(){
    dppm[n - 1] = prob[n - 1] != always;
    dpph[n - 1] = prob[n - 1] != never;
    for(int i = n - 2; i >= 0; i--){
        dppm[i] = dppm[i + 1] && prob[i] != always;
        dpph[i] = dpph[i + 1] || prob[i] != never;
    }
}

inline bool possible_miss(int second) {
    return dppm[second];
}

inline bool possible_hit(int second) {
    return dpph[second];
}

void bfs() {
    std::queue<Situation> situs;
    situs.push(Situation(0, 1));
    searched[0][1] = true;
    while(!situs.empty()) {
        if(k == 0) return; k--;
        std::queue<Situation> next_situs;
        while(!situs.empty()) {
            Situation situ = situs.front();
            situs.pop();
            // FIXME assume all probility == probably
            if(situ.second == n - 1) { // only two fools left
                // 1O 2O: ignored, stop searching
                // 1O 2X: one left, stop searching
                if(prob[situ.first] != never && possible_miss(situ.second))
                    siglenton_searched[situ.first] = true;
                // 1X 2O: one left, stop searching
                if(prob[situ.first] != always && possible_hit(situ.second))
                    siglenton_searched[situ.second] = true;
                // 1X 2X: nobody left, stop searching
                if(prob[situ.first] != never && possible_hit(situ.second))
                    void_searched = true;
            } else { // at least three fools left
                // 1O 2O: ignored, stop searching
                // 1O 2X:
                if(prob[situ.first] != never && possible_miss(situ.second) && !searched[situ.first][situ.second + 1]) {
                    next_situs.push(Situation(situ.first, situ.second + 1));
                    searched[situ.first][situ.second + 1] = true;
                }
                // 1X 2O:
                if(prob[situ.first] != always && possible_hit(situ.second) && !searched[situ.second][situ.second + 1]) {
                    next_situs.push(Situation(situ.second ,situ.second + 1));
                    searched[situ.second][situ.second + 1] = true;
                }
                // 1X 2X:
                if(prob[situ.first] != never && possible_hit(situ.second)) {
                    if(situ.second == n - 2) { // three fools, two dead, stop searching
                        siglenton_searched[n - 1] = true; // the last survived
                    } else {
                        if(!searched[situ.second + 1][situ.second + 2]) {
                            next_situs.push(Situation(situ.second + 1, situ.second + 2));
                            searched[situ.second + 1][situ.second + 2] = true;
                        }
                    }
                }
            }
        }
        swap(situs, next_situs);
    }
}

int main() {
    std::cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int p;
        std::cin >> p;
        prob[i] = p == 0 ? never : p == 100 ? always : probably;
    }
    if(n > 1) {
        init_dps();
        bfs();
        int ns = 0;
        for(int i = 0; i < n; i++)
            ns += std::count(searched[i], searched[i] + n, true);
        ns += std::count(siglenton_searched, siglenton_searched + n, true);
        ns += void_searched ? 1 : 0;
        std::cout << ns << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }
}