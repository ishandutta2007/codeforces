#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>

int tab[100007];
std::vector<int> lucky;
std::unordered_map<int, std::vector<int>> pozycje;
std::set<int> teraz;
long long dodaje = 0;
long long suma[100007];
long long ssuma[100007];

bool isLucky(int a) {
    while (a != 0) {
        if (a % 10 != 4 && a % 10 != 7)
            return false;
        a /= 10;
    }
    return true;
}

void dorzuc(int pos) {
    auto prev = teraz.upper_bound(pos), next = prev--;
    if (next != teraz.end()) {
        dodaje -= suma[*next - *prev - 1];
        dodaje += suma[*next - pos - 1];
    }
    dodaje += suma[pos - *prev - 1];
    teraz.insert(pos);
}

void usun() {
    auto last = teraz.rbegin();
    auto pLast = last;
    pLast++;
    dodaje -= suma[*last - *pLast - 1];
    teraz.erase(--teraz.end());
}

int main() {
    int N;
    scanf("%d", &N);
    long long lastDod = 0;
    for (int i = 1; i <= N; i++)
        suma[i] = suma[i - 1] + i;
    for (int i = 1; i <= N; i++)
        ssuma[i] = ssuma[i - 1] + suma[i];
    lucky.push_back(0);
    long long wyn = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        if (isLucky(tab[i])) {
            teraz.insert(0);
            lucky.push_back(i);
            pozycje[tab[i]].push_back(i);
            lastDod = 0;
            for (int w = (int) lucky.size() - 1; w >= 1; w--) {
                for (auto it : pozycje[tab[lucky[w]]])
                    if (teraz.count(it) == 0)
                        dorzuc(it);
                    else
                        break;
                if (*teraz.rbegin() == lucky[w])
                    usun();
                lastDod += dodaje * (lucky[w] - lucky[w - 1]);
                int k = lucky[w] - *teraz.rbegin();
                int o = lucky[w] - lucky[w - 1];
                lastDod += ssuma[k - 1] - ssuma[k - o - 1];
//                lastDod += ssuma[lucky[w] - 1] - ssuma[lucky[w - 1] - 1];
//                lastDod += suma[lucky[w] - *teraz.rbegin() - 1];
            }
            teraz.clear();
        } else
            lastDod += suma[i - 1];
        wyn += lastDod;
    }
    printf("%lld", wyn);
    return 0;
}