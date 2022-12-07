#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n;
char str[2222];
string s1, s2;
map<string, set<string> > h;
map<set<string>, set<string> > h2;

vector<vector<string> > ans;
vector<string> sb;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int len = strlen(str);
        int j = 7;
        string s1 = "";
        for (; j < len && str[j] != '/'; j++)
            s1 += str[j];
        s2 = "";
        for (; j < len; j++)
            s2 += str[j];
        h[s1].insert(s2);
    }
    for (map<string, set<string> >::iterator it = h.begin(); it != h.end(); it++)
        h2[it->second].insert(it->first);
    for (map<set<string>, set<string> >::iterator it = h2.begin(); it != h2.end(); it++) {
        sb.clear();
        for (set<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            sb.push_back(*it2);
        }
        if (sb.size() > 1) ans.push_back(sb);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("http://");
            for (int k = 0; k < ans[i][j].length(); k++) {
                printf("%c", ans[i][j][k]);
            }
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}