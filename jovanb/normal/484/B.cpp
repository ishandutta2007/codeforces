#include <bits/stdc++.h>
using namespace std;

const int maxval = 2050000;
int ima[maxval];
int niz[200005];
int trenmax[maxval];
bool bio[maxval];

int main() {
    
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        ima[niz[i]] = 1;
    }
    for(int i=2; i<maxval; i++){
        if(ima[i-1]) trenmax[i] = i-1;
        else trenmax[i] = trenmax[i-1];
    }
    int maxres = 0;
    for(int i=1; i<=n; i++){
        if(bio[niz[i]]) continue;
        int x = niz[i]*2;
        while(x < maxval){
            if(trenmax[x] > niz[i]) maxres = max(maxres, trenmax[x]%niz[i]);
            x += niz[i];
        }
        bio[niz[i]] = 1;
    }
    cout << maxres;
}