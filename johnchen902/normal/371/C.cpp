#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;

struct Ing{
    int n, p, r;
} ib, is, ic;

typedef long long Int64;
Int64 r;
vector<Ing> vec;
Int64 cnt;

bool any_non_0(){
    for(vector<Ing>::iterator it = vec.begin(); it != vec.end(); ++it)
        if(it->n != 0) return true;
    return false;
}

void slow_buy(){
    for(vector<Ing>::iterator it = vec.begin(); it != vec.end(); ++it)
        if(it->n >= it->r) it->n -= it->r;
        else r -= (it->r - it->n) * (it->p), it->n = 0;
    if(r >= 0)
        cnt++;
}

void fast_buy(){
    if(r <= 0) return;
    int p = 0;
    for(vector<Ing>::iterator it = vec.begin(); it != vec.end(); ++it)
        p += (it->r) * (it->p);
    cnt += r / p;
}

int main(){
    string s;
    cin >> s;
    ib.r = count(s.begin(), s.end(), 'B');
    is.r = count(s.begin(), s.end(), 'S');
    ic.r = count(s.begin(), s.end(), 'C');
    cin >> ib.n >> is.n >> ic.n >> ib.p >> is.p >> ic.p >> r;
    if(ib.r != 0) vec.push_back(ib);
    if(is.r != 0) vec.push_back(is);
    if(ic.r != 0) vec.push_back(ic);
    while(any_non_0()) slow_buy();
    fast_buy();
    cout << cnt << endl;
    return 0;
}