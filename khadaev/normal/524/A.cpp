#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, l;
    long a, b;
    set<pair<long, long> > s;
    vector<long> users, new_users;
    scanf("%d%d", &m, &l);
    for (long i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        s.insert(make_pair(a,b));
        users.push_back(a);
        users.push_back(b);
    };
    sort(users.begin(), users.end());
    new_users.push_back(users[0]);
    for (long i = 1; i < users.size(); ++i)
        if (users[i] != users[i - 1])
            new_users.push_back(users[i]);
    users = new_users;
    for (long i = 0; i < users.size(); ++i) {
        vector<long> str;
        long ans = 0;
        long friends = 0;
        for (long j = 0; j < users.size(); ++j) 
            if ((s.count(make_pair(users[i],users[j])) > 0) || (s.count(make_pair(users[j],users[i])) > 0)) ++friends;
        for (long j = 0; j < users.size(); ++j) {
            if ((i == j) || (s.count(make_pair(users[i],users[j])) > 0) || (s.count(make_pair(users[j],users[i])) > 0))
                continue;
            long cnt = 0;
            for (long k = 0; k < users.size(); ++k) {
                if (((s.count(make_pair(users[i],users[k])) > 0) || (s.count(make_pair(users[k], users[i])) > 0)) && ((s.count(make_pair(users[j],users[k])) > 0) || (s.count(make_pair(users[k],users[j])) > 0)))
                    ++cnt;
            };
            if (cnt * 100 >= l * friends){
                ++ans;
            };
        };
        printf("%d: %d ", (users[i]), ans);
        for (long j = 0; j < users.size(); ++j) {
            if ((i == j) || (s.count(make_pair(users[i],users[j])) > 0) || (s.count(make_pair(users[j],users[i])) > 0))
                continue;
            long cnt = 0;
            for (long k = 0; k < users.size(); ++k) {
                if (((s.count(make_pair(users[i],users[k])) > 0) || (s.count(make_pair(users[k], users[i])) > 0)) && ((s.count(make_pair(users[j],users[k])) > 0) || (s.count(make_pair(users[k],users[j])) > 0)))
                    ++cnt;
            };
            if (cnt * 100 >= l * friends){
                printf("%d ", (users[j]));
            };
        };
        printf("\n");
    };
};