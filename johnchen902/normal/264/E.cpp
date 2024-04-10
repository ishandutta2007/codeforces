#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <stack>
using namespace std;

vector<deque<pair<int, int>>> a;
map<int, int> p2h, h2p;

void insert(int p, int h) {
    stack<pair<int, int>> temp;
    for(auto ite = h2p.end(); ite != h2p.begin(); ) {
        --ite;
        if(ite->first < h)
            break;
        temp.push(make_pair(ite->second, ite->first));
        auto ite2 = partition_point(a.begin(), a.end(),
                [ite](const deque<pair<int, int>> &d) {
                    return d.front().first < ite->second;
                });
        ite2->pop_front();
        if(ite2->empty())
            a.pop_back();
    }
    p2h.insert(make_pair(p, h));
    h2p.insert(make_pair(h, p));
    temp.push(make_pair(p, h));
    while(!temp.empty()) {
        auto pa = temp.top();
        temp.pop();
        auto ite = partition_point(a.begin(), a.end(),
                [pa](const deque<pair<int, int>> &d) {
                    return d.front().first < pa.first;
                });
        if(ite == a.end())
            a.emplace_back(1, pa);
        else
            ite->push_front(pa);
    }
}

void remove(int x) {
    stack<pair<int, int>> temp;
    for(auto ite = p2h.end(); x--; ) {
        --ite;
        temp.push(*ite);
        auto ite2 = partition_point(a.begin(), a.end(),
                [ite](const deque<pair<int, int>> &d) {
                    return d.back().second < ite->second;
                });
        ite2->pop_back();
        if(ite2->empty())
            a.pop_back();
    }

    p2h.erase(temp.top().first);
    h2p.erase(temp.top().second);
    temp.pop();

    while(!temp.empty()) {
        auto pa = temp.top();
        temp.pop();
        auto ite = partition_point(a.begin(), a.end(),
                [pa](const deque<pair<int, int>> &d) {
                    return d.back().second < pa.second;
                });
        if(ite == a.end())
            a.emplace_back(1, pa);
        else
            ite->push_back(pa);
    }
}

int getlis() {
    return a.size();
}

int main() {
    int q;
    scanf("%*d %d", &q);
    for(int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int p, h;
            scanf("%d %d", &p, &h);
            insert(-p, i - h);
        } else if(type == 2) {
            int x;
            scanf("%d", &x);
            remove(x);
        }
        printf("%d\n", getlis());
    }
}