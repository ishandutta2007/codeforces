#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <chrono>
using namespace std;
typedef long long ll;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

namespace std{
    namespace
    {

        // Code from boost
        // Reciprocal of the golden ratio helps spread entropy
        //     and handles duplicates.
        // See Mike Seymour in magic-numbers-in-boosthash-combine:
        //     http://stackoverflow.com/questions/4948780

        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }

        // Recursive template code derived from Matthieu M.
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
            hash_combine(seed, std::get<Index>(tuple));
          }
        };

        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            hash_combine(seed, std::get<0>(tuple));
          }
        };
    }

    template <typename ... TT>
    struct hash<std::tuple<TT...>> 
    {
        size_t
        operator()(std::tuple<TT...> const& tt) const
        {                                              
            size_t seed = 0;                             
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
            return seed;                                 
        }                                              

    };
}

template <typename TT>
struct tuple_hash
{
    size_t operator()(TT const &tt) const {
        return std::hash<TT>()(tt);
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;
    vector<unordered_multiset<int, custom_hash>> graph1(n, unordered_multiset<int, custom_hash>());
    vector<unordered_multiset<int, custom_hash>> graph2(n, unordered_multiset<int, custom_hash>());

    unordered_map<tuple<int, int>, queue<int>, tuple_hash<tuple<int, int>>> edge_index1;
    unordered_map<tuple<int, int>, queue<int>, tuple_hash<tuple<int, int>>> edge_index2;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if (w == 1) {
            graph1[u].insert(v);
            graph1[v].insert(u);
            edge_index1[{u, v}].push(i);
        } else {
            graph2[u].insert(v);
            graph2[v].insert(u);
            edge_index2[{u, v}].push(i);
        }
    }

    int num_oddysey = 0;
    for (int i = 0; i < n; i++) {
        if (graph1[i].size() % 2 == 1) num_oddysey++;
    }



    // All nodes are set
    vector<int> direction(m, -1);
    
    unordered_map<int, int, custom_hash> partner1;
    unordered_map<int, int, custom_hash> directed_partner1;
    unordered_map<int, vector<int>, custom_hash> euler_path1;

    // Pass through 1, only odd values
    for (int i = 0; i < n; i++) {
        if (graph1[i].size() % 2 == 0) {
            continue;
        }

        int curr_node = i;
        while (graph1[curr_node].size() > 0) {
            int next_node = *(graph1[curr_node].begin());
            
            // First find the edge and direct it
            if (edge_index1[{curr_node, next_node}].size() > 0) {
                int next_edge_index = edge_index1[{curr_node, next_node}].front();
                edge_index1[{curr_node, next_node}].pop();
                direction[next_edge_index] = 1;
                euler_path1[i].push_back(next_edge_index);
            } else {
                int next_edge_index = edge_index1[{next_node, curr_node}].front();
                edge_index1[{next_node, curr_node}].pop();
                direction[next_edge_index] = 2;
                euler_path1[i].push_back(next_edge_index);
            }

            // Second delete from graph
            graph1[curr_node].erase(graph1[curr_node].find(next_node));
            graph1[next_node].erase(graph1[next_node].find(curr_node));

            // Iterate
            curr_node = next_node;
        }
        
        partner1[i + 1] = curr_node + 1;
        partner1[curr_node + 1] = i + 1;
        directed_partner1[i + 1] = curr_node + 1;
    }

    // Pass through 1, euler cycles

    for (int i = 0; i < n; i++) {
        int curr_node = i;
        while (graph1[curr_node].size() > 0) {
            int next_node = *(graph1[curr_node].begin());
            
            // First find the edge and direct it
            if (edge_index1[{curr_node, next_node}].size() > 0) {
                int next_edge_index = edge_index1[{curr_node, next_node}].front();
                edge_index1[{curr_node, next_node}].pop();
                direction[next_edge_index] = 1;
            } else {
                int next_edge_index = edge_index1[{next_node, curr_node}].front();
                edge_index1[{next_node, curr_node}].pop();
                direction[next_edge_index] = 2;
            }

            // Second delete from graph
            graph1[curr_node].erase(graph1[curr_node].find(next_node));
            graph1[next_node].erase(graph1[next_node].find(curr_node));

            // Iterate
            curr_node = next_node;
        }
    }

    // Pass through 2, only odd nodes

    unordered_map<int, int, custom_hash> partner2;
    unordered_map<int, int, custom_hash> directed_partner2;
    unordered_map<int, vector<int>, custom_hash> euler_path2;

    for (int i = 0; i < n; i++) {
        if (graph2[i].size() % 2 == 0) {
            continue;
        }
    
        int curr_node = i;
        while (graph2[curr_node].size() > 0) {
            int next_node = *(graph2[curr_node].begin());
            
            // First find the edge and direct it
            if (edge_index2[{curr_node, next_node}].size() > 0) {
                int next_edge_index = edge_index2[{curr_node, next_node}].front();
                edge_index2[{curr_node, next_node}].pop();
                direction[next_edge_index] = 1;
                euler_path2[i].push_back(next_edge_index);
            } else {
                int next_edge_index = edge_index2[{next_node, curr_node}].front();
                edge_index2[{next_node, curr_node}].pop();
                direction[next_edge_index] = 2;
                euler_path2[i].push_back(next_edge_index);
            }

            // Second delete from graph
            graph2[curr_node].erase(graph2[curr_node].find(next_node));
            graph2[next_node].erase(graph2[next_node].find(curr_node));

            // Iterate
            curr_node = next_node;
        }

        partner2[i + 1] = curr_node + 1;
        partner2[curr_node + 1] = i + 1;
        directed_partner2[i + 1] = curr_node + 1;
    }

    // Pass through 2, euler cycles
    for (int i = 0; i < n; i++) {

        int curr_node = i;
        while (graph2[curr_node].size() > 0) {
            int next_node = *(graph2[curr_node].begin());
            
            // First find the edge and direct it
            if (edge_index2[{curr_node, next_node}].size() > 0) {
                int next_edge_index = edge_index2[{curr_node, next_node}].front();
                edge_index2[{curr_node, next_node}].pop();
                direction[next_edge_index] = 1;
            } else {
                int next_edge_index = edge_index2[{next_node, curr_node}].front();
                edge_index2[{next_node, curr_node}].pop();
                direction[next_edge_index] = 2;
            }

            // Second delete from graph
            graph2[curr_node].erase(graph2[curr_node].find(next_node));
            graph2[next_node].erase(graph2[next_node].find(curr_node));

            // Iterate
            curr_node = next_node;
        }
    }


    // Direct the euler paths proper

    for (int i = 0; i < n; i++) {
        if (partner1[i + 1] == 0 || partner2[i + 1] != 0) {
            continue;
        }

        // Has partner1, no partner2
        bool odd_step = true;
        int curr_node = i;
        while (true) {
            // Go to next node
            int next_node = 0;
            if (odd_step) {
                next_node = partner1[curr_node + 1];
            } else {
                next_node = partner2[curr_node + 1];
            }

            if (next_node == 0) {
                break;
            }

            // Reverse euler_path if needed
            next_node--;
            if (odd_step) {
                if (directed_partner1[next_node + 1] == curr_node + 1) {
                    for (auto e : euler_path1[next_node]) {
                        direction[e] = 3 - direction[e];
                    }
                }
            } else {
                if (directed_partner2[next_node + 1] == curr_node + 1) {
                    for (auto e : euler_path2[next_node]) {
                        direction[e] = 3 - direction[e];
                    }
                }
            }
            
            // Set partners to 0
            if (odd_step) {
                partner1[curr_node + 1] = 0;
                partner1[next_node + 1] = 0;
                directed_partner1[curr_node + 1] = 0;
                directed_partner1[next_node + 1] = 0;
            } else {
                partner2[curr_node + 1] = 0;
                partner2[next_node + 1] = 0;
                directed_partner2[curr_node + 1] = 0;
                directed_partner2[next_node + 1] = 0;
            }

            curr_node = next_node;
            odd_step = !odd_step;
        }
    }


    for (int i = 0; i < n; i++) {
        if (partner2[i + 1] == 0 || partner1[i + 1] != 0) {
            continue;
        }

        // Has partner2, no partner1
        bool odd_step = false;
        int curr_node = i;
        while (true) {
            // Go to next node
            int next_node = 0;
            if (odd_step) {
                next_node = partner1[curr_node + 1];
            } else {
                next_node = partner2[curr_node + 1];
            }

            if (next_node == 0) {
                break;
            }

            // Reverse euler_path if needed
            next_node--;
            if (odd_step) {
                if (directed_partner1[next_node + 1] == curr_node + 1) {
                    for (auto e : euler_path1[next_node]) {
                        direction[e] = 3 - direction[e];
                    }
                }
            } else {
                if (directed_partner2[next_node + 1] == curr_node + 1) {
                    for (auto e : euler_path2[next_node]) {
                        direction[e] = 3 - direction[e];
                    }
                }
            }
            
            // Set partners to 0
            if (odd_step) {
                partner1[curr_node + 1] = 0;
                partner1[next_node + 1] = 0;
                directed_partner1[curr_node + 1] = 0;
                directed_partner1[next_node + 1] = 0;
            } else {
                partner2[curr_node + 1] = 0;
                partner2[next_node + 1] = 0;
                directed_partner2[curr_node + 1] = 0;
                directed_partner2[next_node + 1] = 0;
            }

            curr_node = next_node;
            odd_step = !odd_step;
        }
    }


    for (int i = 0; i < n; i++) {
        if (partner1[i + 1] == 0) {
            continue;
        }

        // Has both partner1 and partner2
        bool odd_step = true;
        int curr_node = i;
        int first_step = true;
        while (curr_node != i || first_step) {
            first_step = false;

            // Go to next node
            int next_node = 0;
            if (odd_step) {
                next_node = partner1[curr_node + 1];
            } else {
                next_node = partner2[curr_node + 1];
            }

            // Reverse euler_path if needed
            next_node--;
            if (odd_step) {
                if (directed_partner1[next_node + 1] == curr_node + 1) {
                    for (auto e : euler_path1[next_node]) {
                        direction[e] = 3 - direction[e];
                    }
                }
            } else {
                if (directed_partner2[next_node + 1] == curr_node + 1) {
                    for (auto e : euler_path2[next_node]) {
                        direction[e] = 3 - direction[e];
                    }
                }
            }
            
            // Set partners to 0
            if (odd_step) {
                partner1[curr_node + 1] = 0;
                partner1[next_node + 1] = 0;
                directed_partner1[curr_node + 1] = 0;
                directed_partner1[next_node + 1] = 0;
            } else {
                partner2[curr_node + 1] = 0;
                partner2[next_node + 1] = 0;
                directed_partner2[curr_node + 1] = 0;
                directed_partner2[next_node + 1] = 0;
            }

            curr_node = next_node;
            odd_step = !odd_step;
        }
    }

    cout << num_oddysey << "\n";
    for (int i = 0; i < m; i++) {
        cout << direction[i];
    }
    cout << "\n";
}