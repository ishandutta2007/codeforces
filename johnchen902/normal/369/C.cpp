#include <iostream>
#include <algorithm>
#include <utility>
#include <list>
#include <vector>

const int max_n = 100000;

typedef std::pair<int, bool> Road; // (to, problemric)

std::list<Road> adj[max_n];
bool is_visited[max_n];
std::vector<int> candidates;

int n;

// return if there are problem roads in sub tree
bool dfs(int id, int parent){
//    std::cerr << "[(" << id << ", " << parent << ")";
    bool contain_problem = false;
    for(std::list<Road>::iterator it = adj[id].begin(); it != adj[id].end(); ++it){
        if(it->first != parent){
            bool cp = dfs(it->first, id);
            if(it->second && !cp)
                candidates.push_back(it->first + 1);
            if(it->second || cp)
                contain_problem = true;
        }
    }
//    std::cerr << "(" << contain_problem << ")]";
    return contain_problem;
}

int main(){
    std::cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y, t;
        std::cin >> x >> y >> t;
        adj[x - 1].push_back(Road(y - 1, t == 2));
        adj[y - 1].push_back(Road(x - 1, t == 2));
    }
    dfs(0, -1);
//    std::cerr << std::endl;
    std::cout << candidates.size() << std::endl;
    bool first = true;
    for(std::vector<int>::iterator it = candidates.begin(); it != candidates.end(); ++it){
        if(first)
            first = false;
        else
            std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}