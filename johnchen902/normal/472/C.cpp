#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string first[100000];
string second[100000];
string curr;

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> first[i] >> second[i];
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if(curr >= first[x] && curr >= second[x]) {
            puts("NO");
            return 0;
        } else if(curr >= first[x]) {
            curr = second[x];
        } else if(curr >= second[x]) {
            curr = first[x];
        } else {
            curr = min(first[x], second[x]);
        }
    }
    puts("YES");
}