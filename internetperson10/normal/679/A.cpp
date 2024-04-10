#include <bits/stdc++.h>

using namespace std;

bool good[101];
bool nums[101];

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool ask(int x) {
    if(good[x]) return nums[x];
    good[x] = true;
    cout << x << endl;
    string s;
    cin >> s;
    if(s == "yes") return nums[x] = 1;
    return nums[x] = 0;
}

int main() {
    int ans = 0;
    ans = (ask(2) + ask(3) + ask(5) + ask(7));
    if(ans == 0) {
        cout << "prime" << endl;
        return 0;
    }
    else {
        bool isPrime = true;
        int c;
        if(ask(2)) c = 2;
        else if(ask(3)) c = 3;
        else if(ask(5)) c = 5;
        else c = 7;
            for(int i = 0; i < primes.size(); i++) {
                if(c * primes[i] > 100) break;
                if(ask(c * primes[i])) {
                    isPrime = false;
                    break;
                }
            }
        if(isPrime) cout << "prime" << endl;
        else cout << "composite" << endl;
    }
}