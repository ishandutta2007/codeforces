#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

typedef std::pair<int, int> pii;

int parse(const std::string& s) {
    return atoi(s.substr(0, 2).c_str()) * 60 * 60 +
        atoi(s.substr(3, 2).c_str()) * 60 +
        atoi(s.substr(6, 2).c_str());
}

const int START = 0;
const int END = 1;

struct Event {
    int ts;
    int type;
    int id;
    Event(int ts, int type, int id) : ts(ts), type(type), id(id) {}
    bool operator<(const Event& event) const {
        if (ts != event.ts) return ts < event.ts;
        if (type != event.type) return type < event.type;
        return id < event.id;
    }
};

int main() {
    int n, M, T;
    cin >> n >> M >> T;
    std::vector<Event> events;
    for (int i = 0; i < n; ++i) {
        std::string s;
        cin >> s;
        int ts = parse(s);
        events.push_back({ts, START, i});
        events.push_back({ts + T - 1, END, i});
    }
    std::sort(events.begin(), events.end());
    vector<int> toId(n, -1);
    vector<int> res(n);
    bool matchM = false;
    int actives = 0;
    int lastUsed = -1;
    for (const auto& event: events) {
        if (event.type == START) {
            if (actives != M) {
                ++lastUsed;
                ++actives;
                if (actives == M) matchM = true;
            }
            toId[lastUsed] = event.id;
            res[event.id] = lastUsed;
        } else {
            assert(actives);
            int probablyEnds = res[event.id];
            if (toId[probablyEnds] == event.id) {
                --actives;
            }
        }
    }
    if (!matchM) {
        std::cout << "No solution" << std::endl;
        return 0;
    }
    cout << lastUsed + 1 << std::endl;
    for (int x: res) std::cout << x + 1 << std::endl;
    return 0;
}