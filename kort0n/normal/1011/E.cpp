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

int gcd(int a, int b)
{
    if(a < b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    //cout.precision(10);
    int n, k;
    cin >> n >> k;
    //int a[100010];
    int ans = k;
    for(int i = 1; i <= n; i++){
        int in;
        cin >> in;
        in = gcd(in, k);
        ans = gcd(in, ans);
    }
    vector<int> answer;
    answer.push_back(0);
    for(int i = 1; i < k; i++){
        if(i % ans == 0){
            answer.push_back(i);
        }
    }
    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}