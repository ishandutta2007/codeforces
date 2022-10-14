#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
int N;
ll K;

int main(){
    cin >> N;
    ll a[N][N];
    int x,y;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 1; i < N; i+=2)for(int j = 0; j < N; j++){
        a[i][j] = 1LL<<(i+j);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << a[i][j]<<" ";
        }
        cout << "\n";
        cout.flush();
    }
    cin >> T;ll q;
    while(T--){
        cin >> K;
        x = 0, y = 0;
        cout << 1<<" "<<1<<endl;
        cout.flush();
        for(int i = 0; i < 2*N-2; i++){
            q = K&(1LL<<(i+1));
            if((x < N-1) && (a[x+1][y]==q))x++;
            else y++;
        //    cout << "Q "<<q<<endl;
            cout << x+1<<" "<<y+1<<endl;
            cout.flush();
        }

    }
    return 0;
}