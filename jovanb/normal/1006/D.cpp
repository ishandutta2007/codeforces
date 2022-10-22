#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

map <char, int> br;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ukup=0;
    for(int i=0; i<n; i++){
        int j = n-i-1;
        if(j == i){
            if(s1[i] != s2[i]) ukup++;
            continue;
        }
        if(j <= i) break;
        br.clear();
        char c1 = s1[i];
        char c2 = s1[j];
        char c3 = s2[i];
        char c4 = s2[j];
        br[c1]++;
        br[c2]++;
        br[c3]++;
        br[c4]++;
        if(br[c1] >= 4) continue;
        if(br[c1] >= 3 || br[c2] >= 3){ukup++; continue;}
        if(br[c1] >= 2){
            if(c2 != c1 && br[c2] >= 2){continue;}
            if(c3 != c1 && br[c3] >= 2){continue;}
            if(c4 != c1 && br[c4] >= 2){continue;}
            if(c2 == c1) ukup += 2;
            else ukup++;
            continue;
        }
        if(br[c2] >= 2){
            if(c1 != c2 && br[c1] >= 2){continue;}
            if(c3 != c2 && br[c3] >= 2){continue;}
            if(c4 != c2 && br[c4] >= 2){continue;}
            ukup ++;
            continue;
        }

        if(br[c3] >= 2){
            if(c2 != c3 && br[c2] >= 2){continue;}
            if(c1 != c3 && br[c1] >= 2){continue;}
            if(c4 != c3 && br[c4] >= 2){continue;}
            ukup++;
            continue;
        }
        ukup += 2;
    }
    cout << ukup;
    return 0;
}