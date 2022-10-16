#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

long long gcd(long long a, long long b)
{
    if(a < b){
        swap(a, b);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main() {
    //cout.porecision(10);
    long long l, r, x, y;
    cin >> l >> r >> x >> y;
    if((y % x) != 0){
        cout << 0 << endl;
        return 0;
    }
    long long product = y / x;
    long long ans = 0;
    for(long long i = 1; i <= r; i++){
        if(i * x < l){
            continue;
        }
        if(i * x > r){
            break;
        }
        if(i > product){
            break;
        }
        if((product % i) != 0){
            continue;
        }
        long long j = product / i;
        if((j * x) < l){
            continue;
        }
        if((j * x) > r){
            continue;
        }
        if(i > j){
            break;
        }
        if(gcd(i * x, j * x) != x){
            continue;
        }
        ans++;
        if(i != j){
            ans++;
        }
        //cout << i * x << " " << j * x << " " << gcd(i * x, j * x) << " " << lcm(i * x, j * x) << endl;
    }
    cout << ans << endl;
    return 0;
}