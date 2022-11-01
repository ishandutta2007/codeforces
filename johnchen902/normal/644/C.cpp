#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int n;
    std::scanf("%d\n", &n);
    using P = std::pair<std::string, std::string>;
    std::vector<P> vec;
    for(int i = 0; i < n; i++) {
        char line[50];
        std::fgets(line, 50, stdin);
        char host[21] = "", path[22] = "";
        std::sscanf(line, "http://%[^/\n]%s", host, path);
        vec.push_back(std::make_pair(host, path));
    }
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    for(int i = 0, j = 1; j < (int) vec.size(); j++) {
        if(vec[i].first == vec[j].first) {
            vec[i].second += "$";
            vec[i].second += vec[j].second;
            vec[j] = P();
        } else {
            i = j;
        }
    }
    vec.erase(std::remove(vec.begin(), vec.end(), P()), vec.end());
    std::sort(vec.begin(), vec.end(), [](const P &l, const P &r) { return l.second < r.second; });
    vec[0].first = "http://" + vec[0].first;
    for(int i = 0, j = 1; j < (int) vec.size(); j++) {
        if(vec[i].second == vec[j].second) {
            vec[i].first += " http://";
            vec[i].first += vec[j].first;
            vec[j] = P();
        } else {
            i = j;
            vec[i].first = "http://" + vec[i].first;
        }
    }
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](const P& p){ return p.first.find(' ') == std::string::npos; }), vec.end());
    std::printf("%d\n", (int) vec.size());
    for(const P& p : vec)
        std::puts(p.first.c_str());
}