#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
int main(){
    int t = 1, n;
    // sd(t);
    while(t--){
        int s, v1, v2, t1, t2;
        cin >> s >> v1 >> v2 >> t1 >> t2;
        int x = 2 * t1 + s * v1, y = 2 * t2 + s * v2;
        if(x < y){cout << "First";}
        if(x == y){cout << "Friendship";}
        if(x > y){cout << "Second";}
    }
}