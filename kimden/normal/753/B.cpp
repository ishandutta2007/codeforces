#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v;
    int a, b;
    for(int i = 0; i < 10; i++){
        cout << i << i << i << i << endl;
        cin >> a >> b;
        if(a + b > 0){
            v.push_back(i);
        }
    }
    vector<int> w = {1, 2, 3, 4};
    do{
        for(int i = 0; i < 4; i++){
            cout << v[w[i] - 1];
        }
        cout << endl;
        cin >> a >> b;
        if(a == 4 && b == 0){
            return 0;
        }
    }while(next_permutation(w.begin(), w.end()));
    return 0;
}