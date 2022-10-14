#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

long long sol;
int n;
int p[MAXN], lefv[2*MAXN], rigv[2*MAXN];
vector <int> lefmx, lefmn, rigmx, rigmn;

void dvc (int lef, int rig) {
    if (rig - lef < 1) return;
    int mid = (lef + rig) / 2;
    lefmx.clear(); lefmn.clear();
    rigmx.clear(); rigmn.clear();
    for (int i = mid; i >= lef; i--) {
        lefmx.push_back(max(p[i], lefmx.empty() ? 0 : lefmx.back() ));
        lefmn.push_back(min(p[i], lefmn.empty() ? n : lefmn.back() ));
    }
    for (int i = mid + 1; i <= rig; i++) {
        rigmx.push_back(max(p[i], rigmx.empty() ? 0 : rigmx.back() ));
        rigmn.push_back(min(p[i], rigmn.empty() ? n : rigmn.back() ));
    }
    int lefp = 0, rigp = 0;
    int lefr = -1, rigr = -1;
    while (lefp < lefmx.size() || rigp < rigmx.size()) {
        if (rigp == rigmx.size() || lefp != lefmx.size() && lefmx[lefp] < rigmx[rigp]) {
            lefv[lefmn[lefp] + lefp]++;
            while (rigr + 1  < rigp && lefmn[lefp] < rigmn[rigr + 1]) {
                rigr++;
                rigv[rigmn[rigr] + rigr]--;
            }
            int ind = lefmx[lefp] - lefmn[lefp] - lefp - 1;
            if (0 <= ind && ind <= rigr) sol++;
            ind = lefmx[lefp] - lefp - 1;
            if (ind) sol += rigv[ind];
            lefp++;
        } else {
            rigv[rigmn[rigp] + rigp]++;
            while (lefr + 1  < lefp && rigmn[rigp] < lefmn[lefr + 1]) {
                lefr++;
                lefv[lefmn[lefr] + lefr]--;
            }
            int ind = rigmx[rigp] - rigmn[rigp] - rigp - 1;
            if (0 <= ind && ind <= lefr) sol++;
            ind = rigmx[rigp] - rigp - 1;
            if (ind) sol += lefv[ind];
            rigp++;
        }
    }
    for (int i = 0; i < lefmn.size(); i++) {
        lefv[lefmn[i] + i] = 0;
    }
    for (int i = 0; i < rigmn.size(); i++) {
        rigv[rigmn[i] + i] = 0;
    }
    dvc(lef, mid);
    dvc(mid + 1, rig);
}

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x] = y;
    }
    dvc(1, n);
    cout << sol + n;
    return 0;
}