#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(auto q: v){
        cout << q << " ";
    }
    cout << endl;
    return 0;
}