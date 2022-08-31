#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
const int N = 100005;
int main(){
    int n;
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int pos = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') cnt1++;
        else if(s[i] == ')') cnt2++;
        else pos = i, cnt3++;
    }
    cnt2 += cnt3;
    if(cnt1 < cnt2){
        cout << -1 << endl;
        return 0;
    }
    int pref = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') pref++;
        if(s[i] == ')') pref--;
        if(s[i] == '#') pref--;
        if(i == pos) pref -= (cnt1 - cnt2);
        if(pref < 0){
            printf("%d\n", -1); 
            return 0;
        }
    }
    for(int i = 0; i < cnt3 - 1; i++) printf("%d ", 1);
    printf("%d\n", cnt1 - cnt2 + 1);
}