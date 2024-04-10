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

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        int a;
        int c = 0;
        for(int i = 0; i < N; i++){
            cin >> a; if(a==1)c++;
        }
        if(c <= N/2)c = 0;
        else  c = 1;
        if((N%4 == 2) && (c==1))N+=2;
        cout << N/2<<"\n";
        for(int i = 0; i < N/2; i++)cout << c << " ";
        cout <<"\n";
    }
    return 0;
}