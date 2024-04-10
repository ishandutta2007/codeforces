#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool is(unsigned x){
    unsigned l = 1, r = x;
    while(l + 1 != r){
        unsigned mid = (l + r) / 2;
        if(mid * mid < x)
            l = mid;
        else if(mid * mid > x)
            r = mid;
        else
            return true;
    }
    return l * l == x;
}

void generates(vector<int>& v, unsigned n){
    if(n == 1){ v = {1}; return; }
    if(n == 2){ v = {3, 4}; return; }
    fill_n(back_inserter(v), n, 1);
    unsigned sum = n;
    for(unsigned j = 2; j <= 10000 && !is(sum); j++){
//        fprintf(stderr, "trying with %u and %u...\n", j - 1, j);
        for(unsigned i = 0; i < n && !is(sum); i++)
            v[i] = j, sum += 2 * j - 1;
    }
}

int main(){
    unsigned n, m;
    cin >> n >> m;
    vector<int> v1, v2;
    generates(v1, n);
    generates(v2, m);
    for(unsigned i = 0; i < n; i++)
        for(unsigned j = 0; j < m; j++){
            cout << v1[i] * v2[j];
            if(j == m - 1) cout << endl;
            else cout << " ";
        }
}