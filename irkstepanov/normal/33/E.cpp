#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int inf = 1e9;

struct data
{
    int id;
    int day;
    int t;
    int cost;
    int spend;
    data() : id(-1) {}
    data(int id, int day, int t, int cost, int spend) : id(id), day(day), t(t), cost(cost), spend(spend) {}
    bool operator<(const data& other) const
    {
        if (day != other.day) {
            return day < other.day;
        }
        return t < other.t;
    }
};

vector<char> free_time(24 * 60, true);

int str_to_time(const string& s)
{
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + s[4] - '0';
}

void occupy_day(const string& s)
{
    int l = str_to_time(s.substr(0, 5));
    int r = str_to_time(s.substr(6, 5));
    for (int i = l; i <= r; ++i) {
        free_time[i] = false;
    }
}

struct dd
{
    int last;
    int pre_last;
    int tl, tr;
    dd() : pre_last(-1) {}
    dd(int last, int pre_last, int tl, int tr) : last(last), pre_last(pre_last), tl(tl), tr(tr) {}
};

struct answer
{
    int id;
    int tl, tr;
};

void time_to_str(int t)
{
    cout << t / (24 * 60) + 1 << " ";
    t %= (24 * 60);
    int h = t / 60;
    int m = t % 60;
    if (h < 10) {
        cout << 0;
    }
    cout << h;
    cout << ":";
    if (m < 10) {
        cout << 0;
    }
    cout << m;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int cnt_subjects;
    cin >> cnt_subjects;
    int n, days;
    cin >> n >> days;

    map<string, int> subjects;
    vector<string> subject_names(cnt_subjects);
    for (int i = 0; i < cnt_subjects; ++i) {
        cin >> subject_names[i];
    }
    for (int i = 0; i < cnt_subjects; ++i) {
        int val;
        cin >> val;
        subjects[subject_names[i]] = val;
    }

    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        occupy_day(s);
    }

    bool is_free = false;
    for (int i = 0; i < 24 * 60; ++i) {
        if (free_time[i]) {
            is_free = true;
        }
    }
    if (!is_free) {
        cout << "0\n0\n";
        return 0;
    }

    vector<int> next_time(24 * 60 * (days + 1), -1);
    for (int i = 24 * 60 * (days + 1) - 2; i >= 0; --i) {
        int t = i % (24 * 60);
        if (free_time[(t + 1) % (24 * 60)]) {
            next_time[i] = i + 1;
        } else {
            next_time[i] = next_time[i + 1];
        }
    }

    vector<data> v;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int day;
        cin >> day;
        string t;
        cin >> t;
        int cost;
        cin >> cost;
        if (subjects.count(s)) {
            --day;
            v.pb({i + 1, day, str_to_time(t), cost, subjects[s]});
        }
    }
    n = sz(v);
    sort(all(v));

    /*for (int i = 0; i < n; ++i) {
        cout << v[i].id << " " << v[i].day << " " << v[i].t << " " << v[i].cost << " " << v[i].spend << "\n";
    }*/

    vector<vector<int> > dp(n + 1, vector<int>(24 * 60 * (days + 1), -inf));
    vector<vector<dd> > pr(n + 1, vector<dd>(24 * 60 * (days + 1)));
    int qq = 0;
    if (!free_time[0]) {
        qq = next_time[0];
    }
    dp[0][qq] = 0;

    for (int j = 1; j <= n; ++j) {
        int finish = 0;
        if (!free_time[0]) {
            finish = next_time[0];
        }
        for (int c = 1; c < v[j - 1].spend; ++c) {
            finish = next_time[finish];
            if (finish >= v[j - 1].day * 24 * 60 + v[j - 1].t) {
                break;
            }
            /*if (j == 1) {
                cout << finish / 60 << " " << finish % 60 << "\n";
            }*/
        }
        if (finish >= v[j - 1].day * 24 * 60 + v[j - 1].t) {
            continue;
        }
        //cout << j << " " << finish << "\n";
        for (int start = 0; start < 24 * 60 * days; ++start) {
            if (!free_time[start % (24 * 60)]) {
                continue;
            }
            if (finish < v[j - 1].day * 24 * 60 + v[j - 1].t) {for (int i = 0; i < j; ++i) {
                if (dp[i][start] == -inf) {
                    continue;
                }
                if (dp[i][start] + v[j - 1].cost > dp[j][next_time[finish]]) {
                    dp[j][next_time[finish]] = dp[i][start] + v[j - 1].cost;
                    pr[j][next_time[finish]] = {v[j - 1].id, i, start, finish};
                }
            }
            finish = next_time[finish];} else break;
        }
    }

    int ans = -inf;
    int ans_i, ans_start;

    for (int i = 0; i <= n; ++i) {
        for (int start = 0; start < 24 * 60 * (days + 1); ++start) {
            if (dp[i][start] > ans) {
                ans = dp[i][start];
                ans_i = i, ans_start = start;
            }
        }
    }

    cout << ans << "\n";
    vector<answer> vv;
    while (ans_i) {
        //cout << ans_i << " " << ans_start << "\n";
        vv.pb({pr[ans_i][ans_start].last, pr[ans_i][ans_start].tl, pr[ans_i][ans_start].tr});
        int new_ans_i = pr[ans_i][ans_start].pre_last;
        int new_ans_start = pr[ans_i][ans_start].tl;
        ans_i = new_ans_i;
        ans_start = new_ans_start;
    }

    reverse(all(vv));

    cout << sz(vv) << "\n";
    for (answer& aa : vv) {
        cout << aa.id << " ";
        time_to_str(aa.tl);
        cout << " ";
        time_to_str(aa.tr);
        cout << "\n";
    }

}