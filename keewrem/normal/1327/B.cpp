#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int T,N,K,a;
vi ps[100010];
bool taken[100010],tk[100010];
int main(){
    cin >> T;
    while (T--){
        cin >> N;
        for(int i = 1; i <= N; i++){
            taken[i]=0;
            tk[i]=0;
            ps[i].clear();
            cin >> K;
            while(K--){
                cin >> a;
                ps[i].push_back(a);
            }
        }
        int c = 0;
        for(int i = 1; i <= N; i++){
            for(auto x: ps[i]){
                if(!taken[x]){
                    taken[x]=1;
                    tk[i]=1;
                    c++;
                    break;
                }
            }
        }
        if (c == N){
            cout << "OPTIMAL\n";
            continue;
        }
        int m,f;
        for(int i = N; i > 0; i--){
            if(!tk[i])f= i;
            if(!taken[i])m=i;
        }
        cout << "IMPROVE\n" << f << " "<< m <<"\n";
    }
    return 0;
}