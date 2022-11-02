#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a[100009], r[100009][109];
vector<int> v[100009], rv[109];
queue<int> q;
void ds(int g)
{
    for (int i = 0; i < rv[g].size(); i++)
        q.push(rv[g][i]);
    while (q.size() > 0){
        int t = q.front();
        q.pop();
        for (int i = 0; i < v[t].size(); i++){
            if ((a[v[t][i]] != g && r[v[t][i]][g] == 0) || r[t][g] + 1 < r[v[t][i]][g]){
                r[v[t][i]][g] = r[t][g] + 1;
                q.push(v[t][i]);
            }
        }
    }
}

int main()
{
    int n, m, s, k;
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>s;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        rv[a[i]].push_back(i);
    }
    int sa, sb;
    for (int i = 1; i <= m; i++){
        cin>>sa>>sb;
        v[sa].push_back(sb);
        v[sb].push_back(sa);
    }
    for (int i = 1; i <= k; i++)
        ds(i);
    for (int i = 1; i <= n; i++){
        sort(r[i]+1, r[i]+k+1);
        int ss = 0;
        for (int j = 1; j <= s; j++)
            ss += r[i][j];
        cout<<ss<<" ";
    }
    cout<<'\n';
    return 0;
}