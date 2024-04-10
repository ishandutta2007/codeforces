#include<bits/stdc++.h>


using namespace std;

int main(){
    int n, m;
    cin >> n;
    cout << n / 7 * 2 + (n % 7 == 6) << ' ' << n / 7 * 2 + (n % 7 == 1) + 2*(n % 7 >= 2); 
}