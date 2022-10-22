#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    string s;
    cin >> s;
    int n = s.size();
    int g = n/2;
    int i=0, j=n-1;
    string s1 = "";
    while(i<j){
        if(2*s1.size() >= g) break;
        if(2*s1.size() == g-1){
            cout << s1 << s[i];
            reverse(s1.begin(), s1.end());
            cout << s1;
            return 0;
        }
        if(s[i] != s[j] && s[i] != s[j-1]){
            i++;
            continue;
        }
        if(s[i] == s[j]){
            s1 += s[i];
            j--;
            i++;
        }
        else{
            if(i >= j-1) break;
            s1 += s[i];
            i++;
            j -= 2;
        }
    }
    if(2*s1.size() < g) cout << "IMPOSSIBLE";
    else {
        cout << s1;
        reverse(s1.begin(), s1.end());
        cout << s1;
    }
    return 0;
}