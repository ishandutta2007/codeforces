#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin >> N;
    bool a[N];
    bool b[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i =0; i < N; i++)cin>>b[i];
    for(int i = 0; i <N; i++){
        if(a[i]&& b[i]){
            a[i]=0;
            b[i]=0;
        }
    }
    int aa=0, bb=0;
    for(int i = 0; i < N; i++){
        if(a[i])aa++;
        if(b[i])bb++;
    }
    if(aa==0){cout << -1;return 0;}
    cout << bb/aa+1;
    return 0;
}