#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int c[100050];
int b[100050];
unordered_map<int, multiset<int> > pathes;
unordered_map<int, int> degree;
vector<int> ans;
vector<int> answer;
map<int, bool> visited;
map<int, bool> usedmerge;
set<int> query;

unordered_map<int, vector<int> > merging;

void search(int from) {
    ans.push_back(from);
    visited[from] = true;
    query.insert(from);
    cerr << "SEARCHING " << from << endl;
    if(pathes[from].empty()) return;
    auto itr = pathes[from].begin();
    if(pathes[from].size() >= 2) {
        while(pathes[*itr].size() == 1) {
            itr++;
            if(itr == pathes[from].end()) {
                itr--;
                break;
            }
        }
    }
    int to = *itr;
    auto itr2 = pathes[to].lower_bound(from);
    if(itr == itr2) {
        itr2++;
        if(*itr != *itr2) return;
    }
    pathes[from].erase(itr);
    pathes[to].erase(itr2);
    search(to);
}

void search2(int from, int start) {
    if(pathes[from].empty()) return;
    if(visited[from] == false) query.insert(from);
    visited[from] = true;
    merging[start].push_back(from);
    auto itr = pathes[from].begin();
    if(pathes[from].size() >= 2) {
        while(pathes[*itr].size() == 1) {
            itr++;
            if(itr == pathes[from].end()) {
                itr--;
                break;
            }
        }
    }
    int to = *itr;
    auto itr2 = pathes[to].lower_bound(from);
    if(itr == itr2) {
        itr2++;
        if(*itr != *itr2) return;
    }
    pathes[from].erase(itr);
    pathes[to].erase(itr2);
    search2(to, start);
}

void print(int now) {
    if(usedmerge[now]) {
        //cout << now << " ";
        answer.push_back(now);
        return;
    }
    usedmerge[now] = true;
    for(int i = 0; i < merging[now].size(); i++) {
        print(merging[now][i]);
        //answer.push_back(merging[now][i]);
    }
    //cout << now << " ";
    answer.push_back(now);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) cin >> b[i];
    for(int i = 1; i < n; i++) cin >> c[i];
    int start = b[1];
    for(int i = 1; i < n; i++) {
        if(b[i] > c[i]) {
            cout << -1 << endl;
            return 0;
        }
        degree[b[i]]++;
        degree[c[i]]++;
        pathes[b[i]].insert(c[i]);
        pathes[c[i]].insert(b[i]);
    }
    set<int> odd;
    for(int i = 1; i < n; i++) {
        if((degree[b[i]] % 2) == 1) {
            start = b[i];
            odd.insert(b[i]);
        }
        if((degree[c[i]] % 2) == 1) {
            start = c[i];
            odd.insert(c[i]);
        }
    }
    if(odd.size() > 2) {
        cout << -1 << endl;
        return 0;
    }
    search(start);
    /*
    for(int i = 1; i < n; i++) {
        if(visited[b[i]]) search2(b[i], b[i]);
        if(visited[c[i]]) search2(c[i], c[i]);
    }
    */
    while(!query.empty()) {
        auto itr = query.begin();
        int now = *itr;
        query.erase(itr);
        search2(now, now);
    }
    for(int i = 0; i < ans.size(); i++) {
        print(ans[i]);
        /*
        if(merging[ans[i]].empty()) {
            //cout << ans[i] << " ";
            answer.push_back(ans[i]);
            continue;
        }
        for(int j = 0; j < merging[ans[i]].size(); j++) {
            //cout << merging[ans[i]][j] << " ";
            answer.push_back(merging[ans[i]][j]);
        }
        answer.push_back(ans[i]);
        merging[ans[i]].clear();
        */
    }
    //cout << endl;
    if(answer.size() < n) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}