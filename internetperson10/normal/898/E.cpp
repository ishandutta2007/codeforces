#include <bits/stdc++.h>

using namespace std;

vector<int> candies;

int main() {
    long long int n, c, s=0, zeroes=0, squares=0;
    cin >> n;
    for(int a=0; a<n; a++) {
        cin >> c;
        if(c==0) {
            candies.push_back(0);
            zeroes++;
        }
        else if(floor(sqrt(c))==ceil(sqrt(c))) {
            candies.push_back(0);
            squares++;
        }
        else candies.push_back(min(abs(floor(sqrt(c))*floor(sqrt(c))-c), abs(ceil(sqrt(c))*ceil(sqrt(c))-c)));
    }
    sort(candies.begin(), candies.end());
    if(zeroes+squares>n/2) {
        int miss=zeroes+squares-n/2;
        while(miss && squares) {
            s++;
            miss--;
            squares--;
        }
        while(miss && zeroes) {
            s+=2;
            miss--;
            zeroes--;
        }
    }
    else {
    for(int a=0; a<n/2; a++) {
        s+=candies[a];
    }
    }
    cout << s;
}