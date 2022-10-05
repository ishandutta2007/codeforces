#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int ocnt = 1, ecnt = 2;
    int t = n / 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(t) <= j && j < n - abs(t)) printf("%d ", ocnt), ocnt += 2;
            else printf("%d ", ecnt), ecnt += 2;
        }t--;
        puts("");
    }
}