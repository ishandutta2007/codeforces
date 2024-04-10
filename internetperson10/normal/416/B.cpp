#include <bits/stdc++.h>

using namespace std;

long long int arr[50005][5];

int main() {
    int ing, er;
    cin >> ing >> er;
    for(int a=0; a<ing; a++) {
        for(int b=0; b<er; b++) {
            cin >> arr[a][b];
            if(a>0 && b>0) arr[a][b]+=max(arr[a-1][b], arr[a][b-1]);
            else if(a>0) arr[a][b]+=arr[a-1][b];
            else if(b>0) arr[a][b]+=arr[a][b-1];
            if(b+1==er) cout << arr[a][b] << ' ';
        }
    }
}