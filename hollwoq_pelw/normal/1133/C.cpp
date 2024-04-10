#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n;
    int a[n], l = 0, r = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    int mx = 0;
    while(l < n){
        while(r < n&& a[r++] - a[l] <= 5){mx = max(r-l, mx);}
        l ++;
    }
    cout << mx;
}
/*
\||/     \||/      +==-==-==
 |/       \|       |/
 ||   +   ||      |/  |
 -|==???==|-  =+  |++==+==-=
 ||   +   ||      |\  |
 |\       /|       |\    
/||\     /||\      +==-==-==
*/