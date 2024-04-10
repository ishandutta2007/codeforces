#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int p[300005];
int gde[300005];

queue <pair <int, int>> q;

void swapuj(int a, int b){
    q.push({a, b});
    swap(p[a], p[b]);
    gde[p[a]] = a;
    gde[p[b]] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        gde[p[i]] = i;
    }
    for(int d=0; n/2-d > 1; d++){
        int i = n/2-d;
        if(p[i] != i){
            int m = gde[i];
            if(m > n/2){
                swapuj(m, 1);
                swapuj(1, n);
                swapuj(n, i);
            }
            else{
                swapuj(m, n);
                swapuj(n, i);
            }
        }
        i = n/2+1+d;
        if(p[i] != i){
            int m = gde[i];
            if(m > n/2){
                swapuj(m, 1);
                swapuj(1, i);
            }
            else{
                swapuj(m, n);
                swapuj(n, 1);
                swapuj(1, i);
            }
        }
    }
    if(p[1] != 1) swapuj(1, n);
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front().first << " " << q.front().second << "\n";
        q.pop();
    }
    return 0;
}