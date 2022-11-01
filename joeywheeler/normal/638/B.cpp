#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int nek[26];
int pre[26];
bool se[26];
char buf[100];

int main() {
    int n; scanf("%d", &n);
    FO(i,0,26) nek[i] = pre[i] = -1;
    FO(i,0,n) {
        scanf(" %s", buf);
        int l = strlen(buf);
        FO(i,0,l) {
            se[buf[i]-'a'] = true;
        }
        FO(i,0,l-1) {
            nek[buf[i]-'a'] = buf[i+1]-'a';
            pre[buf[i+1]-'a'] = buf[i]-'a';
        }
    }
    FO(i,0,26) if (se[i] && pre[i] == -1) {
        for (int j = i; j != -1; j = nek[j]) printf("%c", j+'a');
    }
    printf("\n");
}