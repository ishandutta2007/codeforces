#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, s;
    vector<pair<int, int>> vec;
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++){
        int x, y, p;
        scanf("%d %d %d", &x, &y, &p);
        vec.push_back({x * x + y * y, p});
    }
    int l = 0, r = n;
    while(l != r){
//        fprintf(stderr, "%d %d\n", l, r);
        if(l + 1 == r){
            if(s + vec[l].second < 1000000)
                l = r;
            else
                r = l;
            break;
        }
        int mid = (l + r) / 2;
        nth_element(vec.begin() + l, vec.begin() + mid, vec.begin() + r);
        int sum = accumulate(vec.begin() + l, vec.begin() + mid, make_pair(0, 0),
                [](decltype(vec[0]) lhs, decltype(vec[0]) rhs){
                    return make_pair(0, lhs.second + rhs.second);
                }).second;
        if(s + sum < 1000000){
            s += sum;
            l = mid;
        } else {
            r = mid;
        }
    }
//    fprintf(stderr, "%d %d\n", l, r);
    if(l == n){
        puts("-1");
    } else {
        printf("%.9f", sqrt(vec[l].first));
    }
}