#include <bits/stdc++.h>
using namespace std;

std::vector<int> prefix_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p1 = 67;
    int p2 = 91;
    const int MOD = 888'888'901;

    int N, M;
    cin >> N >> M;

    vector<string> map1(N);
    vector<int> hashes(N);
    for (int i = 0; i < N; i++) {
        cin >> map1[i];
        long long hash = 0;
        for (char c : map1[i]) {
            hash = (hash * p1 + (c - 'a')) % MOD;
        }
        hashes[i] = hash;
    }
    map<int, int> m1;
    for (int i = 0; i < N-M+1; i++) {
        long long hash = 0;
        for (int j = 0; j < M; j++) {
            hash = (hash * p2 + hashes[i + j]) % MOD;
        }
        m1[hash] = i;
    }

    vector<string> map2(M);
    for (int i = 0; i < M; i++) {
        cin >> map2[i];
    }
    vector<int> hashes2(N);
    for (int i = 0; i < N; i++) {
        long long hash = 0;
        for (int j = 0; j < M; j++) {
            hash = (hash * p2 + (map2[j][i] - 'a')) % MOD;
        }
        hashes2[i] = hash;
    }
    for (int i = 0; i < N-M+1; i++) {
        long long hash = 0;
        for (int j = 0; j < M; j++) {
            hash = (hash * p1 + hashes2[i + j]) % MOD;
        }
        if (m1.count(hash)) {
            cout << m1[hash] + 1 << " " << i + 1 << '\n';
            return 0;
        }
    }

}