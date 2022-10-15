#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> getMaxTeam(const vector<vector<bool> >& edges, const vector<int>& set, vector<vector<int>> * answer) {
    if (set.size() == 0)
        return (*answer)[0];
    if (set.size() == 1) {
        (*answer)[1 << set[0]].push_back(set[0]);
        return set;
    }
    int index = 0;
    for (int i = 0; i < set.size(); ++i)
        index += 1 << set[i];
    if ((*answer)[index].size() > 0)
        return (*answer)[index];
    int x = set.back();
    vector<int> set1 = set;
    set1.pop_back();
    vector<int> team1 = getMaxTeam(edges, set1, answer);
    vector<int> set2;
    for (int i = 0; i < set.size() - 1; ++i)
        if (!edges[x][set[i]])
            set2.push_back(set[i]);
    /*if (set == set2) {
        (*answer)[index] = set;
        return set;
    }*/
    vector<int> team2 = getMaxTeam(edges, set2, answer);
    team2.push_back(x);
    if (team1.size() > team2.size()) {
        (*answer)[index] = team1;
        return team1;
    }
    else {
        (*answer)[index] = team2;
        return team2;
    }
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<string> data(n);
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    vector<vector<bool> > edges(n, vector<bool> (n, false));
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k) {
                if ((s1 == data[j]) && (s2 == data[k]))
                    edges[j][k] = edges[k][j] = true;
            }
    }
    vector<int> set;
    for (int i = 0; i < n; ++i)
        set.push_back(i);
    vector<vector<int> > answer(1 << n);
    vector<int> maxTeam = getMaxTeam(edges, set, &answer);
    cout << maxTeam.size() << endl;
    vector<string> team;
    for (int i = 0; i < maxTeam.size(); ++i)
        team.push_back(data[maxTeam[i]]);
    sort(team.begin(), team.end());
    for (int i = 0; i < team.size(); ++i)
        cout << team[i] << endl;
    return 0;
}