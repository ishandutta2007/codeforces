#include <cstdio>
#include <set>
#include <utility>

int main(){
    unsigned n;
    std::scanf("%u", &n);
    std::set<std::pair<unsigned, unsigned>> mp;
    for(unsigned i = 0; i < n; i++){
        unsigned x, k;
        std::scanf("%u%u", &x, &k);
        if(x >= 1 && !mp.count({k, x - 1})) {
            std::puts("NO");
            return 0;
        } else {
            mp.insert({k, x});
        }
    }
    puts("YES");
    return 0;
}