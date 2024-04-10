#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

map<int, int> freq;

int main(){
    int n, x;
    sd(n);
    for(int i = 1; i <= n; i++){
        sd(x);
        freq[x]++;
    }
    int curr = 0;
    for(auto it : freq){
        curr = max(curr, it.second);
    }
    cout << curr;
}