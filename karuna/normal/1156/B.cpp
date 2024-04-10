#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;
int cnt = 0;
string s;
vector<int> ans;
int arr[30];
bool chk[30];

bool dfs(int x) {
    if (x!=-2) {
        chk[x] = true;
        ans.push_back(x);
    }

    if (cnt == ans.size()) return true;

    for (int i=0; i<26; i++) {
        if (abs(x-i)!=1 && arr[i]!=0 && chk[i]==false) {
            if (dfs(i)) return true;
        }
    }

    chk[x] = false;
    ans.pop_back();

    return false;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        cin >> s;


        for (int i=0; i<s.size(); i++) {
            arr[s[i]-'a']++;
        }

        for (int i=0; i<30; i++) {
            if (arr[i] != 0) ++cnt;
        }

        dfs(-2);
        if (ans.size() != cnt) {
            printf("No answer\n");
        }
        else {
            for (auto i : ans) {
                while (arr[i]--) {
                    printf("%c", i+'a');
                }
            }
            printf("\n");
        }

        for (int i=0; i<30; i++) {
            chk[i] = false;
            arr[i] = 0;
        }

        cnt=0;
        ans.clear();
    }
}