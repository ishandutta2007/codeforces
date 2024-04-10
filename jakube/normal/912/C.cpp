#include <bits/stdc++.h>
using namespace std;

struct S
{
    int max_health, start_health, regen;
    int last_time = 0;
};

struct T
{
    int time, enemy, health;
};

struct Event
{
    int time, enemy;
    bool operator<(const Event& other) const
    {
        return time > other.time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int bounty, increase, damage;
    cin >> bounty >> increase >> damage;
    vector<S> enemies(n);
    int min_max_health = std::numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        cin >> enemies[i].max_health >> enemies[i].start_health >> enemies[i].regen;
        min_max_health = min(min_max_health, enemies[i].max_health);
    }
    vector<vector<T>> changes(n);
    for (int i = 0; i < m; i++) {
        T t;
        cin >> t.time >> t.enemy >> t.health;
        t.enemy--;
        changes[t.enemy].push_back(t);
    }
    for (auto& change : changes) {
        sort(change.begin(), change.end(), [](auto p, auto q) {
            return p.time < q.time;
        });
        reverse(change.begin(), change.end());
    }
    
    if (increase > 0 && min_max_health <= damage) {
        cout << -1 << endl;
        return 0;
    }
    
    int current = 0;
    priority_queue<Event> events;
    auto add_event = [&events,&changes,&enemies,damage](int idx) {
        auto& enemy = enemies[idx];
        auto& change = changes[idx];
        if (enemy.regen > 0 && enemy.start_health <= damage) {
            int time = (damage - enemy.start_health) / enemy.regen + 1 + enemy.last_time;
            if (change.size() && time > change.back().time) {
                time = change.back().time;
            }
            events.push({time, idx});
        } else {
            if (change.size()) {
                events.push({change.back().time, idx});
            }
        }
    };

    for (int enemy = 0; enemy < n; enemy++) {
        auto& enem = enemies[enemy];
        if (enem.start_health <= damage) {
            current++;
        }
        if (enem.max_health <= damage) continue;
        
        // when isn't this any more true
        add_event(enemy);
    }

    long long max_value = (long long)current * bounty;
    int last_event = -1;
    while (!events.empty()) {
        auto event = events.top();
        events.pop();
        
        // look at last minute
        if (event.time != last_event)
            max_value = max(max_value, (long long)(bounty + (long long)increase * (event.time - 1)) * current);
        last_event = event.time;

        // now do changes
        auto& enemy = enemies[event.enemy];
        int old = enemy.start_health;
        enemy.start_health = min((long long)enemy.max_health, enemy.start_health + (long long)enemy.regen * (event.time - enemy.last_time));
        auto& change = changes[event.enemy];
        if (change.size() && change.back().time == event.time) {
            enemy.start_health = change.back().health;
            change.pop_back();
        }
        enemy.last_time = event.time;
        if (old <= damage && enemy.start_health > damage) {
            current--;
        }
        if (old > damage && enemy.start_health <= damage) {
            current++;
        }

        // compute next event
        add_event(event.enemy);
    }

    for (auto& enemy : enemies) {
        if (enemy.start_health <= damage && enemy.regen == 0 && increase > 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << max_value << endl;
}