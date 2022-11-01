#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<int> votes[100001];

struct Id {
    int a, b;
    operator int () const { return votes[a][b]; }
};

int check(int buy) {
    int my_votes = votes[0].size() + buy;
    if(my_votes <= 0) return -1;
    int cost = 0;
    priority_queue<Id, vector<Id>, greater<Id>> pq;
    for(int i = 1; i <= 100000; i++) {
        int j = 0;
        for(; (int) votes[i].size() - j >= my_votes; j++) {
            cost += votes[i][j];
            buy--;
        }
        if(j < (int) votes[i].size())
            pq.push({i, j});
    }
    if(buy < 0) return -1;
    while(buy && !pq.empty()) {
        Id id = pq.top(); pq.pop();
        cost += (int) id;
        if(id.b + 1 < (int) votes[id.a].size())
            pq.push({id.a, id.b + 1});
        buy--;
    }
    if(buy) return -1;
    return cost;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        votes[a].push_back(b);
    }
    for(int i = 0; i < 100001; i++)
        sort(votes[i].begin(), votes[i].end());
//    for(int i = 0; i < n; i++)
//        printf("%d %d\n", i, check(i));

    if(check(0) == 0) {
        puts("0");
        return 0;
    }
    int l = 0, r = n - votes[0].size(); // (l, r]
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(check(mid) >= 0) r = mid;
        else l = mid;
    }
    l = r, r = n - votes[0].size(); // [l, r]
    while(l + 2 < r) {
        int m1 = (l * 2 + r) / 3, c1 = check(m1);
        int m2 = (l + r * 2) / 3, c2 = check(m2);
        if(c1 >= c2) l = m1;
        if(c1 <= c2) r = m2;
    }
    int mini = check(l);
    int c1 = check(l + 1); if(c1 != -1 && mini > c1) mini = c1;
    int c2 = check(l + 2); if(c2 != -1 && mini > c2) mini = c2;
    printf("%d\n", mini);
}