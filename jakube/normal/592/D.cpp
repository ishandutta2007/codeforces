#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>

template<typename T>
vector<T> reads(int count)
{
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>

struct Node{
    unordered_set<int> neighbors;
    int farthest_attack = -1;
    int farthest_dist = 0;
    int current_sum = 0;


    bool is_attacked = false;

};

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n = readi();
    int m = readi();

    unordered_map<int, Node> tree;
    FOR(i, n)
    {
        tree[i+1] = Node();
    }

    FOR(i, n-1){
        int a = readi();
        int b = readi();
        tree[a].neighbors.insert(b);
        tree[b].neighbors.insert(a);
    }

    queue<int> queue;

    FOR(i, n)
    {
        if (tree[i+1].neighbors.size() == 1)
        {
            queue.push(i+1);
        }
    }



    if (m == 1)
    {
        cout << readi() << endl;
        cout << 0 << endl;
        return 0;
    }



    FOR(i, m) {
        int t = readi();
        tree[t].is_attacked = true;
        tree[t].farthest_attack = t;
    }

    int farthest_dist = 0;
    int sum = 0;
    int farthest_attack = 0;




    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        Node &current_node = tree[current];
        int next = *(current_node.neighbors.begin());

        Node &next_node = tree[next];

        next_node.neighbors.erase(current);


        if (current_node.farthest_dist != 0 || current_node.is_attacked)
        {
            if (current_node.farthest_dist + 1 + next_node.farthest_dist > farthest_dist)
            {
                farthest_dist = current_node.farthest_dist + 1 + next_node.farthest_dist;
                farthest_attack = min(current_node.farthest_attack, next_node.farthest_attack);
            }
            else if (current_node.farthest_dist + 1 + next_node.farthest_dist == farthest_dist)
            {
                farthest_attack = min(farthest_attack, min(current_node.farthest_attack, next_node.farthest_attack));

            }



            if (m == 2 && (current_node.farthest_dist || current_node.is_attacked) && (next_node.farthest_dist || next_node.is_attacked))
            {
                sum = current_node.current_sum + 2 + next_node.current_sum;
                break;
            }
            else
            {
                if ((current_node.farthest_dist || current_node.is_attacked) && (next_node.farthest_dist || next_node.is_attacked))
                {
                    m--;
                }

                if (next_node.farthest_dist < current_node.farthest_dist + 1)
                {
                    next_node.farthest_attack = current_node.farthest_attack;
                }
                if (next_node.farthest_dist == current_node.farthest_dist + 1)
                {
                    next_node.farthest_attack = min(current_node.farthest_attack, next_node.farthest_attack);
                }

                next_node.farthest_dist = max(current_node.farthest_dist + 1, next_node.farthest_dist);
                next_node.current_sum += current_node.current_sum + 2;
            }
        }

        //cout << "current: " << current << " Next: " << next << " current_sum: " << next_node.current_sum << " farthest_dist: " << next_node.farthest_dist << endl;

        if (next_node.neighbors.size() == 1)
        {
            queue.push(next);
        }
    }
    cout << farthest_attack << endl;
    cout << sum - farthest_dist << endl;
}