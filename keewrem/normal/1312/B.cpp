#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair <ll,ll> pll;

int N,M,T,i;
vi v;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        v.clear();
        for(i = 0; i < N; i++){
            scanf("%d",&M);
            v.push_back(M);
        }
        sort(v.begin(),v.end());
        for(i = v.size()-1; i >= 0;i--){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}