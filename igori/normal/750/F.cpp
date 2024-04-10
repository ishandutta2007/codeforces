#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> graph[1500];
int vis[1500];
int answered = 0;
int height[1500];
int vas[1500];

bool comp(int a, int b)
{
    return vas[a] > vas[b];
}

#define abra if (answered) return;

vector<int> ask(int v)
{
    if (graph[v].size() != 0)
    {
        return graph[v];
    }
    int k;
    vector<int> num;
    if (answered)
        return num;
    cout << "? " << v << endl;
    cin >> k;
    if (k == 0)
        exit(0);
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
    graph[v] = num;
    return num;
}

void ans(int v)
{
    abra;
    cout << "! " << v << endl;
    answered = 1;
    return;
}

void run_ans(int p)
{
    vector<int> ss;
    ss.push_back(p);
    vector<int> dist(500);
    dist[p] = 1;
    for (int i = 0; i < min(6, (int)ss.size()); i++)
    {
        int v = ss[i];
        vector<int> g = ask(v);
        if (g.size() == 2)
        {
            ans(v);
            return;
        }
        for (int j = 0; j < g.size(); j++)
        {
            int u = g[j];
            if (vas[u] == 0 && dist[u] == 0 && dist[v] + 1 <= 3)
            {
                ss.push_back(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
    abra;
    ans(ss[ss.size() - 1]);
}

vector<int> go(int v, int par)
{
    //cout << "IN" << endl;
    vector<int> t;
    t.push_back(v);
    while (1)
    {
        if (height[v] != -1)
        {
            for (int i = 1; i < height[v]; i++)
                t.push_back(0);
            //cout << "OUT 1" << endl;
            return t;
        }
        vector<int> near = ask(v);
        if (near.size() == 2)
        {
            ans(v);
            answered = 1;
            //cout << "OUT 2" << endl;
            return t;
        }
        if (near.size() == 1)
        {
            //cout << "OUT 3" << endl;
            return t;
        }
        int u = 0;
        for (int i = 0; i < near.size(); i++)
        {
            if (near[i] != par)
            {
                u = near[i];
                break;
            }
        }
        t.push_back(u);
        par = v;
        v = u;
    }
    //cout << "OUT Z" << endl;
    return t;
}

void solve()
{
    int h;
    cin >> h;
    if (h == 0)
        exit(0);
    answered = 0;
    fill(vis, vis + 500, 0);
    for (int i = 0; i < 500; i++)
    {
        graph[i].resize(0);
        height[i] = -1;
        vas[i] = 0;
    }
    int center = 1;
    vector<int> ask1 = ask(center);
    if (ask1.size() == 2)
    {
        ans(center);
        return;
    }
    int it = 800;
    while (it--)
    {
        abra;
        ask1 = ask(center);
        if (height[center] >= h - 2)
        {
            //cout << "WENT HERE" << endl;
            run_ans(center);
            abra;
            return;
        }
        if (ask(center).size() == 2)
        {
            abra;
            ans(center);
            return;
        }
        if (ask(center).size() != 1)
        {
            sort(graph[center].begin(), graph[center].end(), comp);
            sort(ask1.begin(), ask1.end(), comp);
            //cout << endl << ask1.size() << " " << ask(center).size() << endl;
            abra;
            vector<int> path1 = go(ask1[0], center);
            //cout << "P1" << endl;
            abra;
            vector<int> path2 = go(ask1[1], center);
            //cout << "P2" << endl;
            abra;
            vector<int> all;
            //cout << all.size() << "HERE" << endl << endl;
            for (int i = path1.size() - 1; i >= 0; i--)
                all.push_back(path1[i]);
            all.push_back(center);
            for (int i = 0; i < path2.size(); i++)
                all.push_back(path2[i]);
            //cout << "COMBINE" << endl;
            vector<int> exists(500);
            for (int i = 0; i <= all.size() / 2; i++)
            {
                height[all[i]] = i + 1;
                height[all[all.size() - i - 1]] = i + 1;
                exists[all[i]] = 1;
                exists[all[all.size() - 1 - i]] = 1;
                vas[all[i]] = 1;
                vas[all[all.size() - 1 - i]] = 1;
            }
            center = all[all.size() / 2];
            vector<int> d = ask(center);
            if (d.size() == 2)
            {
                ans(center);
                return;
            }
            abra;
            for (int i = 0; i < d.size(); i++)
            {
                if (exists[d[i]] == 0)
                {
                    center = d[i];
                    height[center] = height[all[all.size() / 2]] + 1;
                }
            }
        }
        else
        {
            abra;
            //cout << "smth wrong" << endl;
            height[center] = 1;
            center = graph[center][0];
            height[center] = 2;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}

/*
1
3
1 2
3 5 1 4
1 2
*/