#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long
#define inf (int)1e9
#define pii pair < int , int >

const int N = 300005;

int n, q;
int a[N];
int b[N], len = 0;
bool read[N];
int cur = 0;
vector < int > ids[N];
int last = 1;

int main(){ 
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= q;++ i){
        int tp, x;
        cin >> tp >> x;        
        if(tp == 1){
            ++ cur;
            b[++ len] = x;
            ids[x].pb(len);
        }
        else if(tp == 2){
            for(int it = 0;it < ids[x].size();++ it){
                int index = ids[x][it];
                if(!read[index])
                    -- cur;
                read[index] = true;
            }
            ids[x].clear();
        }
        else if(tp == 3){
            for(int it = last;it <= x;++ it){
                if(!read[it]){
                    -- cur;
                    read[it] = true;
                }
            }
        }
        if(tp == 3)
            last = max(x, last);
        cout << cur << endl;
    }
    return 0;
}