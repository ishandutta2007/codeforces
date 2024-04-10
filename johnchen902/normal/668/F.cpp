#include <algorithm>
#include <cstdio>
#include <tuple>
#include <utility>
using namespace std;
constexpr int mod = 1000000007;
int& modinc(int& lhs, int rhs) { return lhs = (lhs + rhs) % mod; }
int modmul(int lhs, int rhs) { return (long long) lhs * rhs % mod; }
// generated magic numbers
constexpr int states[7] = {0, 1, 2, 5, 15, 52, 203};
constexpr int inter1_count[6] = {0, 2, 8, 49, 410, 4389};
constexpr int inter2_count[6] = {0, 1, 3, 15, 107, 1003};
tuple<int, int, int> inter1[5][4389], inter2[1003];
int initial1[203], initial2[52], dropdown[203];
void generate_all(int);
// solver
int parent[10000];
int missing[10000];
int dp[10000][203];
int solve(const int n, const int k) {
    if(k == 1)
        return 1;
    copy_n(initial2, states[k], dp[k - 1]);
    for(int i = k; i < n; i++)
        copy_n(initial1, states[k + 1], dp[i]);
    for(int i = n - 1; i >= k; i--) {
        int buffer[52] = {};
        for(int j = 0; j < states[k + 1]; j++)
            if(dropdown[j] >= 0)
                modinc(buffer[dropdown[j]], dp[i][j]);
        if(parent[i] != k - 1) {
            int buffer2[203] = {};
            for(int j = 0; j < inter1_count[k]; j++) {
                tuple<int, int, int> tiii = inter1[missing[i]][j];
                modinc(buffer2[get<2>(tiii)], modmul(buffer[get<0>(tiii)], dp[parent[i]][get<1>(tiii)]));
            }
            copy_n(buffer2, states[k + 1], dp[parent[i]]);
        } else {
            int buffer2[52] = {};
            for(int j = 0; j < inter2_count[k]; j++) {
                tuple<int, int, int> tiii = inter2[j];
                modinc(buffer2[get<2>(tiii)], modmul(buffer[get<0>(tiii)], dp[parent[i]][get<1>(tiii)]));
            }
            copy_n(buffer2, states[k], dp[parent[i]]);
        }
    }
    return dp[k - 1][0];
}
// main
int con_point[10000][5];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    generate_all(k);

    for(int i = k; i < n; i++) {
        for(int j = 0; j < k; j++) {
            scanf("%d", con_point[i] + j);
            con_point[i][j]--;
        }
        sort(con_point[i], con_point[i] + k);
        parent[i] = con_point[i][k - 1];
        if(parent[i] != k - 1)
            missing[i] = mismatch(con_point[i], con_point[i] + k - 1, con_point[parent[i]]).first - con_point[i];
    }
    printf("%d\n", solve(n, k));
}
// magic generator
#include <string>
#include <vector>
namespace magic_generator {
void generate_sets(int n, char max, const string &s, vector<string> &v) {
    if(n == 0) {
        v.push_back(s);
    } else {
        for(char c = 'A'; c < max; c++)
            generate_sets(n - 1, max, s + c, v);
        generate_sets(n - 1, max + 1, s + max, v);
    }
}
vector<string> generate_sets(int n) {
    vector<string> v;
    generate_sets(n, 'A', "", v);
    return move(v);
}
string reduce_str(const string& s) {
    string t;
    for(int i = 0, ci = 0; i < (int) s.size(); i++) {
        auto ite = find(s.begin(), s.begin() + i, s[i]);
        t.push_back(ite == s.begin() + i ? 'A' + ci++ : t[ite - s.begin()]);
    }
    return move(t);
}
string merge_str(const string &s1, const string &s2) {
    string sx = s2;
    for(int i = 0; i < (int) s1.size(); i++)
        if(find(s1.begin(), s1.begin() + i, s1[i]) == s1.begin() + i)
            for(int j = i + 1; j < (int) s1.size(); j++)
                if(s1[i] == s1[j]) {
                    if(sx[i] == sx[j])
                        return string();
                    char cfrom = sx[i], cto = sx[j];
                    for(char &cc : sx)
                        if(cc == cfrom)
                            cc = cto;
                }
    return reduce_str(sx);
}
template<typename Output_iterator>
Output_iterator gen_inter1(const vector<string> &v1, const vector<string> &v2, int ins, Output_iterator ite) {
    for(int i = 0; i < (int) v1.size(); i++) {
        string s1f = v1[i];
        s1f.insert(s1f.begin() + ins, 'Z');
        for(int j = 0; j < (int) v2.size(); j++) {
            string smg = merge_str(s1f, v2[j]);
            if(!smg.empty()) {
                int k = lower_bound(v2.begin(), v2.end(), smg) - v2.begin();
                *ite++ = make_tuple(i, j, k);
            }
        }
    }
    return ite;
}
template<typename Output_iterator>
Output_iterator gen_inter2(const vector<string> &v, Output_iterator ite) {
    for(int i = 0; i < (int) v.size(); i++) {
        for(int j = 0; j < (int) v.size(); j++) {
            string smg = merge_str(v[i], v[j]);
            if(!smg.empty()) {
                int k = lower_bound(v.begin(), v.end(), smg) - v.begin();
                *ite++ = make_tuple(i, j, k);
            }
        }
    }
    return ite;
}
template<typename RA_iterator>
void gen_initial1(const vector<string> &v, RA_iterator ite) {
    int n = v[0].size();
    for(int i = 0; i < (1 << (n - 1)); i++) {
        string s;
        for(int j = 0; j < n - 1; j++)
            s.push_back('A' + (((i >> j) & 1) ? n - 1 : j));
        s.push_back('A' + n - 1);
        ite[lower_bound(v.begin(), v.end(), reduce_str(move(s))) - v.begin()]++;
    }
}
template<typename RA_iterator>
void gen_initial2(const vector<string> &v, RA_iterator ite) {
    int n = v[0].size(), m = n * (n - 1) / 2;
    for(int i = 0; i < (1 << m); i++) {
        string s;
        for(int j = 0; j < n; j++) s.push_back('A' + j);
        for(int j = 0, l = 0; j < n; j++)
            for(int k = j + 1; k < n; k++, l++)
                if((i >> l) & 1) {
                    if(s[j] == s[k])
                        goto bad_combination;
                    char cfrom = s[j], cto = s[k];
                    for(char &cc : s)
                        if(cc == cfrom)
                            cc = cto;
                }
        ite[lower_bound(v.begin(), v.end(), reduce_str(move(s))) - v.begin()]++;
bad_combination:
        ;
    }
}
template<typename RA_iterator>
void gen_dropdown(const vector<string> &v1, const vector<string>& v2, RA_iterator ite) {
    for(int i = 0; i < (int) v2.size(); i++) {
        if(find(v2[i].begin(), v2[i].end() - 1, v2[i].back()) != v2[i].end() - 1)
            ite[i] = lower_bound(v1.begin(), v1.end(), v2[i].substr(0, v2[i].size() - 1)) - v1.begin();
        else
            ite[i] = -1;
    }
}
}

void generate_all(int k) {
    vector<string> vsk0 = magic_generator::generate_sets(k);
    vector<string> vsk1 = magic_generator::generate_sets(k + 1);
    for(int j = 0; j < k; j++)
        magic_generator::gen_inter1(vsk0, vsk1, j, inter1[j]);
    magic_generator::gen_inter2(vsk0, inter2);
    magic_generator::gen_initial1(vsk1, initial1);
    magic_generator::gen_initial2(vsk0, initial2);
    magic_generator::gen_dropdown(vsk0, vsk1, dropdown);
}