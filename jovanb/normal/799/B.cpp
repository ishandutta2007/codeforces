#include <bits/stdc++.h>
using namespace std;
long long p[200000];
long long a[200000];
long long b[200000];
priority_queue <long long, vector <long long>, greater <long long>> q[56];
map <long long,long long> bio;
int main(){
    long long n,m,k;
    cin >> n;
    for(long i = 0; i < n; i++){
        cin >> p[i];
    }
    for(long i = 0; i < n; i++){
        cin >> a[i];
        q[a[i]].push(p[i]);
    }
    for(long i = 0; i < n; i++){
        cin >> b[i];
        q[b[i]].push(p[i]);
    }
    cin >> m;
    while(m--){
        cin >> k;
        for(long i = 1; i <= 3; i++){
            while(q[i].size() && bio[q[i].top()]){
                q[i].pop();
            }
        }
        if(q[k].empty()){
            cout << "-1 "; 
        }
        else{
            cout << q[k].top() <<  " ";
            bio[q[k].top()] = 1;
            q[k].pop();
        }
    }
}