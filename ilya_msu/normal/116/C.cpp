#include<iostream>
#include<vector>
#include<string>

using namespace std;

int evaluate(vector<int> * depth, const vector<int>& graph, int i) {
    if ((*depth)[i] == 0)
        (*depth)[i] = evaluate(depth, graph, graph[i] - 1) + 1;
    return (*depth)[i];
}

int main() {
    int n;
    cin >> n;
    vector<int> graph(n);
    vector<int> depth(n, 0);
    vector<vector<int> > data(n);

    for (int i = 0; i < n; ++i) {
        cin >> graph[i];
        if (graph[i] == -1)
            depth[i] = 1;
    }
    for (int i = 0; i < n; ++i)
        depth[i] = evaluate(&depth, graph, i);
    int max = 0;
    for (int i = 0; i < n; ++i)
        if (max < depth[i])
            max = depth[i];
    cout << max << endl;
    return 0;
}