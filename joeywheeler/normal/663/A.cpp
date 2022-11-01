#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char buf[1005];
int l, ans;

vector<char> c;

int main() {
    gets(buf);
    l =strlen(buf);
    int cans = 1;
    FO(i,0,l) {
        if (buf[i] == '+') {
            c.push_back(buf[i]);
            cans++;
        } else if (buf[i] == '-') {
            c.push_back(buf[i]);
            cans--;
        } else if (buf[i] == '=') {
            int x;
            sscanf(buf+i+1, " %d", &x);
            ans = x;
            break;
        }
    }

    vector<int> v(sz(c)+1);
    FO(i,0,sz(v)) v[i] = 1;
    // increase
    FO(i,0,sz(v)) {
        if (i == 0 || c[i-1] == '+') {
            while (cans < ans && v[i] < ans) {
                cans++;
                v[i]++;
            }
        }
    }
    FO(i,1,sz(v)) {
        if (c[i-1] == '-') {
            while (cans > ans && v[i] < ans) {
                cans--;
                v[i]++;
            }
        }
    }
    if (cans == ans) {
        printf("Possible\n");
        printf("%d ", v[0]);
        FO(i,1,sz(v)) printf("%c %d ", c[i-1], v[i]);
        printf("= %d\n", ans);
    } else printf("Impossible\n");
}