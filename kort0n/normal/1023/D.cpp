#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

    //cout.precision(10);
int n, q;
const int root = 400;
int a[205000];
int b[600];
int sizeb = 0;
vector<int> first, last;

int mini(int left, int right){
    int ans = INF;
    for(int i = 1; i <= sizeb; i++){
        if((right < ((i - 1) * root + 1)) || (left > (root * i))){
            continue;
        }
        if((left <= ((i - 1) * root + 1)) && (right >= (root * i))){
            ans = min(ans, b[i]);
            continue;
        }
        for(int j = 1; j <= root; j++){
            int k = (i - 1) * root + j;
            if(k < left){
                continue;
            }
            if(k > right){
                continue;
            }
            if(k > n){
                continue;
            }
            ans = min(ans, a[k]);
        }
    }
    return ans;
}

int main()
{
    bool checker = true;
    bool checker2 = false;
    bool checker3 = false;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == q){
            checker2 = true;
        }
        if(a[i] != 0){
            checker = false;
        }
        if(a[i] == 0){
            checker3 = true;
            a[i] = INF;
        }
    }
    if(checker == true){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << q << " ";
        }
        cout << endl;
        return 0;
    }
    if((checker2 == false) && (checker3 == false)){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 1; (i - 1) * root < n; i++){
        sizeb++;
        b[i] = INF;
        for(int j = (i - 1) * root + 1; (j <= n) && (j <= i * root); j++){
            b[i] = min(b[i], a[j]);
        }
    }
    //cout << 1 << endl;
    first.push_back(-1);
    last.push_back(-1);
    for(int i = 1; i <= q; i++){
        first.push_back(-1);
        last.push_back(-1);
    }
    for(int i = 1; i <= n; i++){
        //cout << i << endl;
        if(a[i] == INF){
            continue;
        }
        if(first[a[i]] == -1){
            first[a[i]] = i;
        }
        last[a[i]] = i;
    }
    /*for(int i = 1; i <= q; i++){
        cout << first[i] << " " << last[i] << endl;
    }*/
    //cout << 2 << endl;
    for(int i = 1; i <= q; i++){
        if(first[i] == last[i]){
            continue;
        }
        if(mini(first[i], last[i]) != i){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(checker2 == false){
        int i = 1;
        while(a[i] != INF){
            i++;
        }
        a[i] = q;
    }
    if(a[1] == INF){
        int i = 2;
        while(a[i] == INF){
            i++;
        }
        a[1] = a[i];
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++){
        if(a[i] == INF){
            a[i] = a[i - 1];
        }
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}