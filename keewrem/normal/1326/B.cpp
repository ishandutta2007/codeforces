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
    cin >> N;
    int B[N];
    for(int i = 0; i < N; i++)cin >> B[i];
    int cm = -1000000001;
    int A[N];
    A[0]=B[0];
    for(int i = 1; i < N; i++){
        if(A[i-1]>cm)cm = A[i-1];
        A[i] = B[i]+cm;
    }
    for(int i = 0; i <N; i++)cout << A[i] << " ";
    return 0;
}