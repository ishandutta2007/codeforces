#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

#define int

constexpr signed max_output = 100000;

map<long long, vector<long long>> memo;

bool dfs(long long x, long long k) {
    if(k == 0) {
        static signed outputed = 0; // < 100000
        if(outputed) putchar(' ');
        printf("%I64d", x);
        return ++outputed < max_output;
    }
    if(x == 1)
        return dfs(1, 0);
    if(!memo.count(x)) {
        long long i;
        for(i = 1; i * i <= x; i++)
            if(x % i == 0)
                memo[x].push_back(i);
        while(i * i >= x) i--;
        for(; i >= 1; i--)
            if(x % i == 0)
                memo[x].push_back(x / i);
    }
    for(auto i : memo[x])
        if(!dfs(i, k - 1))
            return false;
    return true;
}

signed main(){
    long long x, k;
    scanf("%I64d %I64d", &x, &k);
    dfs(x, k);
    putchar('\n');
}