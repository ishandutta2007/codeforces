#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
    int t; cin >> t;
    while(t--){
    string s; cin >> s;
    int n = s.length();
    int sum = 0;
    for(int i = 0; i < n;){
        int j = i;
        while(j < n && s[j] == s[i]) j++;
        sum += s[i] == '0';
        i = j;
    }
    cout << min(2, sum) << endl;
}}