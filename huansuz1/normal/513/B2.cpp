#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <cstdlib>
#include <map>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int , int>
using namespace std;
const int N = int(3e6);
int n,a[55];
ll m,d[55];
int main () {
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif
    cin >> n >> m;
    d[0] = 1;
    for(int i=1;i<=n;i++){
        d[i] = 2*d[i-1];
    }
    int i=1,j=n,k=1;
    while(k<=n){
        if(m > d[n-k-1]){
            m -= d[n-k-1];
            a[j] = k;
            j--;
        }
        else {
            a[i] = k;
            i++;
        }
        k++;
    }
    for(int i=1;i<=n;i++) cout << a[i] << " ";
return 0;

}