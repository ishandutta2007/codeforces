#include <bits/stdc++.h>
using namespace std; 
int main(){
    int c = 0; string s;
    int gen[] = {2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49};
    for (auto i: gen){
        cout << i << endl;
        fflush(stdout);
        cin >> s;
        if (s[0] == 'y') c++;
        if (c >= 2) return cout << "composite", 0;
    }
    cout << "prime";
    return 0;
}