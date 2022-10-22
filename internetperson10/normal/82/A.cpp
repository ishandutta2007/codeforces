#include <bits/stdc++.h>

using namespace std;

string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main() {
    int n;
    cin >> n;
    while(n>5) {
        n-=4;
        n/=2;
    }
    cout << names[n-1];
}