#include <bits/stdc++.h>
using namespace std;
long niz1[100000];
long niz2[100000];
int main(){
    long n,m,br=0;
    cin >> n >> m;
    for(long i = 0; i < n; i++){
        cin >> niz1[i];
    }
    for(long i = 0; i < m; i++){
        cin >> niz2[i];
    }
    for(long i = 0; i < n; i++){
        if(niz1[i] >= niz2[m - 1]){
            br = max(br,abs(niz1[i] - niz2[m - 1]));
        }
        else if(niz1[i] <= niz2[0]){
            br = max(br,abs(niz1[i] - niz2[0]));
        }
        else{
        long prvi = lower_bound(niz2, niz2 + m, niz1[i]) - niz2;
        long poslednji = upper_bound(niz2,niz2 + m,niz1[i]) - niz2;
        if(niz2[prvi] != niz1[i]){
            prvi--;
        }
        br = max(br,min(abs(niz1[i] - niz2[prvi]), abs(niz1[i] - niz2[poslednji])));
        }
    }
    cout << br << endl;
    return 0;
}