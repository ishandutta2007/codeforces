#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    int a[505];
    int degree[505];
    int sum = 0;
    vector<int> one;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        degree[i] = 0;
        if(a[i] == 1){
            one.push_back(i);
        }
    }
    if(sum < 2 * (n - 1)){
        cout << "NO" << endl;
        return 0;
    }
    if(n == 2){
        cout << "YES 1" << endl << "1" << endl << "1 2" << endl;
        return 0;
    }
    vector<i_i> pathes;
    vector<int> main;
    for(int i = 1; i <= n; i++){
        if(a[i] >= 2){
            main.push_back(i);
            degree[i] = 2;
        }
    }
    degree[main[0]]--;
    degree[main.back()]--;
    for(int i = 1; i < main.size(); i++){
        pathes.push_back({main[i], main[i - 1]});
    }
    int diameter = main.size() - 1;
    if(one.size() == 1){
        diameter++;
        pathes.push_back({one[0], main[0]});
    } 
    if(one.size() >= 2){
        diameter += 2;
        pathes.push_back({main[0], one.back()});
        degree[main[0]]++;
        one.pop_back();
        pathes.push_back({main.back(), one.back()});
        degree[main.back()]++;
        one.pop_back();
        int index = 0;
        while(!one.empty()){
            int now = one.back();
            one.pop_back();
            while(degree[main[index]] == a[main[index]]){
                index++;
            }
            degree[main[index]]++;
            pathes.push_back({now, main[index]});
        }
    }
    cout << "YES " << diameter << endl;
    cout << pathes.size() << endl;
    for(int i = 0; i < pathes.size(); i++){
        cout << pathes[i].first << " " << pathes[i].second << endl;
    }
    return 0;
}