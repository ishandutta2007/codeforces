#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const int INF = 1e9;


int n, m, t;
int b[N];
int answer[N];
multiset < pair < int, int > > q;
int cur; 



void read() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        b[i] = hh * 3600 + mm * 60 + ss;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        q.insert(mp(b[i], 1));
    }
    bool flagMax = 0;
    int cnt = 0;
    int last = -1;
    int lastId = -1;
    int j = 0;
    for (; !q.empty(); ) {
        //cerr << "cnt: " << cnt << endl;
        auto x = *(q.begin());
        q.erase(q.begin());
        if (x.sc == 1) {
            if (cnt == m) {
                assert(last != -1);
                answer[j] = lastId;
                assert(q.count(mp(last + t, 0)) >= 1);
                q.erase(q.find(mp(last + t, 0)));
                last = x.fr;
                q.insert(mp(last + t, 0));
                j++;
            }
            else {
                answer[j] = cur;
                last = x.fr;
                lastId = cur;
                j++;
                cur++;
                q.insert(mp(x.fr + t, 0));
                cnt++;
                if (cnt == m)
                    flagMax = 1;
            }
        } 
        else if(x.sc == 0) {
            cnt--;
        }
        else 
            assert(false);
    }

    if (flagMax == 0) 
        printf("No solution\n");
    else {
        printf("%d\n", cur);
        for (int i = 0; i < n; i++)
            printf("%d\n", answer[i] + 1);
    }
        
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}