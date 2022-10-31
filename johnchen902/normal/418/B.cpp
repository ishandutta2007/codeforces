#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Friend{
    unsigned x, k, m;
};

constexpr unsigned long long infinity = 2000000000000000001ull;

vector<Friend> frs;
unsigned long long solu[1048576];

int main(){
    unsigned n, m, b;
    cin >> n >> m >> b;
    for(unsigned i = 0; i < n; i++){
        unsigned xi, ki, mi, p = 0;
        cin >> xi >> ki >> mi;
        for(unsigned j = 0; j < mi; j++){
            unsigned q;
            cin >> q;
            p |= 1 << (q - 1);
        }
        frs.push_back({xi, ki, p});
    }
    sort(frs.begin(), frs.end(), [](const Friend& lhs, const Friend& rhs){
         return lhs.k < rhs.k;
    });
    fill_n(solu, 1u << m, infinity);
    solu[0] = 0;
    unsigned long long sol = infinity;
    for(unsigned j = 0; j < n; j++){
        const Friend& fr = frs[j];
        for(unsigned i = 0; i < (1u << m); i++)
            solu[i | fr.m] = min(solu[i | fr.m], solu[i] + fr.x);
        sol = min(sol, solu[(1u << m) - 1] + fr.k * 1ull * b);
    }
    if(sol >= infinity)
        cout << "-1" << endl;
    else
        cout << sol << endl;
}