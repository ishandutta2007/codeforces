#include<bits/stdc++.h>
using namespace std;
int main(){
    int t , s , x;
    cin >> t >> s >> x;
    if(t <= x && ((x - t) % s == 0 || (x - t) % s == 1) && x != t + 1)
        puts("YES");
    else
        puts("NO");
    return 0;
}