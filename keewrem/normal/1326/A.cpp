#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
int N,M,t;

int main(){
    cin >> t;
    while(t--){
    cin >> N;
    if(N==1){cout << "-1\n"; continue;}
    for(int i = 0; i < N-2; i++){
        printf("2");
    }
    if(N%3==1)printf("33\n");
    else printf("23\n");
    }
    return 0;
}