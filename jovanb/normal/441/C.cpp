#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m, k, i=1, j=1, smer=1, kp;
    cin >> n >> m >> k;
    kp = n*m;
    while(k > 1){
        k--;
        cout << "2 " << i << " " << j << " ";
        if(smer == 1) j++;
        else j--;
        if(j <= 0){
            j = 1;
            i++;
            smer = 1;
        }
        else if(j > m){
            j = m;
            i++;
            smer = 0;
        }
        cout << i << " " << j << endl;
        if(smer == 1) j++;
        else j--;
        if(j <= 0){
            j = 1;
            i++;
            smer = 1;
        }
        else if(j > m){
            j = m;
            i++;
            smer = 0;
        }
        kp -= 2;
    }
    if(i <= n) cout << kp << " ";
    while(i<=n){
        cout << i << " " << j << " ";
        if(smer == 1) j++;
        else j--;
        if(j <= 0){
            j = 1;
            i++;
            smer = 1;
        }
        else if(j > m){
            j = m;
            i++;
            smer = 0;
        }
    }
    return 0;
}