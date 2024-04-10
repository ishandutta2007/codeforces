#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[200005];
ll b;
int n,m;
int i;
ll sum=0;
ll tmp;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a[0]=0;
    for(int i=0;i<n;++i){
        cin >> tmp;
        a[i+1]=a[i]+tmp;
    }
    int j=0;
    for(int i=0;i<m;++i){
        cin >> b;
        while(b>a[j]){
            ++j;
            sum=a[j-1];
        }
        cout << j << " " << b-sum << "\n";
    }
    return 0;



}