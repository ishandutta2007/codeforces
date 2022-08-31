#include <iostream>
#include <vector>
int n, m, k;
std::vector<std::pair<std::string, int>> ans;
void addStep(std::string s, int f) {
    if (f == 0)
        return;
    int tot = s.length() * f;
    if (tot >= k) {
        if (k >= s.length())
            ans.emplace_back(s, k / s.length());
        if (k % s.length() != 0)
            ans.emplace_back(s.substr(0, k % s.length()), 1);
        std::cout << "YES\n";
        std::cout << ans.size() << "\n";
        for (auto [s, f] : ans)
            std::cout << f << " " << s << "\n";
        exit(0);
    }
    ans.emplace_back(s, f);
    k -= tot;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    for (int i = 0; i < n - 1; ++i) {
        addStep("RDU", m - 1);
        addStep("L", m - 1);
        addStep("D", 1);
    }
    addStep("R", m - 1);
    addStep("L", m - 1);
    addStep("U", n - 1);
    std::cout << "NO\n";
    return 0;
}